# -*- coding: utf-8 -*-

import requests
import time
import os


########################################################################################################################
# configurations guide
# - necessary:
#     - edit `root`(local project root) and `url`(github repository url) in `__main__`
#     - write your own `README.set_solution_dict()` method
# - optional:
#     - solution table style in `README.table()` method
#     - readme style in `README.readme()` method
########################################################################################################################

class README:

    def __init__(self, root, github_url):
        """Basic configurations
            local_path:     your local project root path
            github_url:     your leetcode repository url in github
            leetcode_url:   leetcode url
            problem_dic:dict    id:dict {1: { 'title': 'Two Sum', 'title_slug': 'two-sum', 'difficulty': 1 }}
            problem_cnt:dict    {'num_total': 973, 'easy': 269, 'medium': 494, 'hard': 210}
            solution_dict:dict  id:str(path) {2:'solution/002_Two_Sum.cpp'}
            solution_cnt:dict   {'num_total': 973, 'easy': 269, 'medium': 494, 'hard': 210}
        """
        self.root = root
        self.github_url = github_url
        self.leetcode_url = 'https://leetcode.com/problems/'
        self.problem_dic = {}
        self.solution_dict = {}
        self.problem_cnt = {}
        self.solution_cnt = {}
        self.set()

    def set_solution_dict(self):
        """ Define your own function to set solution dict
        self.root might be helpful

        Format:{id(int): path(relative path to project root)}
        eg:{2:'solution/002_Two_Sum.cpp'}

        """
        relative_path = 'solution/'
        file_list = os.listdir(self.root + relative_path)
        self.solution_dict = {int(filename[:3]): (relative_path + filename)
                              for filename in file_list if filename[-3:] == 'cpp'}

    def table(self):
        """Generate solution table string by problem dict and solution dict

        **table configuration**

        column_order:   display columns and its order
        column_func:    generate rules

        :return table string
        """

        difficulty = ['#', 'Easy', 'Medium', 'Hard']
        column_order = ['#', 'Title', 'Difficulty', 'Solution']
        column_func = {
            '#': lambda item, path: "%03d" % item['id'],
            'Title': lambda item, path: '[%s](%s%s)' % (item['title'], self.leetcode_url, item['title_slug']),
            'Difficulty': lambda item, path: difficulty[item['difficulty']],
            'Solution': lambda item, path: '[cpp](%s%s)' % (self.github_url, path)
        }

        result = '| ' + ' | '.join(column_order) + ' |\n'
        result += '|:---:' * len(column_order) + '|\n'
        lines = []
        for id, path in self.solution_dict.items():
            line = '|' + '|'.join(
                [column_func[item](self.problem_dic[id], path) for item in column_order]) + '|'
            lines.append(line)
        lines.reverse()
        return result + '\n'.join(lines)

    def readme(self):
        """Generate README.md file in project root

        **Default Format**:
        # LeetCode Solutions
        built by [this file]
        update time: [time]
        AC status: [n]/[m]
            - total
            - easy
            - medium
            - hard
        [solution table]

        """
        print('generating README.md file...')

        with open(self.root + 'README.md', 'w+') as f:
            f.write('# LeetCode Solutions\n\n')
            f.write('This README file was built by [script/readme.py](%sscript/readme.py)\n\n' % self.github_url)
            f.write('Update Time:\t%s\n\n' % time.asctime(time.localtime()))

            f.write('Status:\t%d/%d\n\n' % (self.solution_cnt['num_total'], self.problem_cnt['num_total']))
            f.write('Easy:\t%d/%d\n\n' % (self.solution_cnt['easy'], self.problem_cnt['easy']))
            f.write('Medium:\t%d/%d\n\n' % (self.solution_cnt['medium'], self.problem_cnt['medium']))
            f.write('Hard:\t%d/%d\n\n' % (self.solution_cnt['hard'], self.problem_cnt['hard']))

            f.write('## Solution Table\n')
            f.write(self.table())

        print('generating finish')

    ####################################################################################################################
    # default methods

    def set_problem_dict(self, api):
        """LeetCode original api to mine format

        Original LeetCode Problem API Example(Update 2019/4/13):
        https://leetcode.com/api/problems/algorithms/
        {
          "stat": {
            "question_id": 1,
            "question__article__live": true,
            "question__article__slug": "two-sum",
            "question__title": "Two Sum",
            "question__title_slug": "two-sum",
            "question__hide": false,
            "total_acs": 1668832,
            "total_submitted": 3864105,
            "frontend_question_id": 1,
            "is_new_question": false
          },
          "status": "null",
          "difficulty": {
            "level": 1
          },
          "paid_only": false,
          "is_favor": false,
          "frequency": 0,
          "progress": 0
        }

        My dict format
        {
          1: {
                'id': '1',
                'title': 'Two Sum',
                'title_slug': 'two-sum',
                'difficulty': 1
          }
        """
        self.problem_dic = {
            int(item['stat']['frontend_question_id']):
                {
                    'id': item['stat']['frontend_question_id'],
                    'title': item['stat']['question__title'],
                    'title_slug': item['stat']['question__title_slug'],
                    'difficulty': item['difficulty']['level']
                }
            for item in api['stat_status_pairs']}

    def set(self):
        """ set  """
        api = 'https://leetcode.com/api/problems/algorithms/'
        api_json = requests.get(url=api).json()
        # set problem_dict
        self.set_problem_dict(api_json)

        # set solution_dict
        self.set_solution_dict()

        # set problem_cnt
        def group_by_difficulty(level):
            return sum([1 if item['difficulty'] == level else 0 for item in self.problem_dic.values()])

        self.problem_cnt = {
            'num_total': len(self.problem_dic),
            'easy': group_by_difficulty(1),
            'medium': group_by_difficulty(2),
            'hard': group_by_difficulty(3)
        }

        # set solution_cnt
        def cnt_by_diff(level):
            return sum([1 if self.problem_dic[f]['difficulty'] == level else 0
                        for f in self.solution_dict.keys()])

        self.solution_cnt = {
            'num_total': len(self.solution_dict),
            'easy': cnt_by_diff(1),
            'medium': cnt_by_diff(2),
            'hard': cnt_by_diff(3),
        }


if __name__ == '__main__':
    root = 'C:/Users/Leeld/Documents/projects/leetcode/'
    url = 'https://github.com/leelddd/leetcode/blob/master/'
    r = README(root, url)
    r.readme()
    print()
