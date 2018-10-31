import requests
import json
import time
import re
import configparser


def solution_name(item, suffix):
    return "%03d_%s.%s" % (item['stat']['question_id'], item['stat']['question__title'].replace(' ', '_'), suffix)


class Config:
    # Basic configuration
    name = ''
    pws = ''
    local_path = ''
    github_url = 'https://github.com/leelddd/leetcode/blob/master/'
    leetcode_url = 'https://leetcode.com/problems/'
    difficulty = ['Easy', 'Medium', 'Hard']
    column = {
        '#': lambda item: "%03d" % item['stat']['question_id'],
        'Title': lambda item: '[' + item['stat']['question__title'] + '](' + Config.leetcode_url + item['stat'][
            'question__title_slug'] + ')',
        'Difficulty': lambda item: Config.difficulty[item['difficulty']['level'] - 1],
        'Solution': lambda item: '[cpp](' + Config.github_url + 'latest_submissions/' + solution_name(item, 'cpp') + ')'
    }

    # all_column = ['Id', 'Title', 'Difficulty', 'Description', 'C++', 'Java', 'Python', 'Python3', 'C', 'C#',
    #               'JavaScript',
    #               'Ruby',
    #               'Swift', 'Go', 'Scala', 'Kotlin']

    # Customize for yourself
    column_order = ['#', 'Title', 'Difficulty', 'Solution']


class API:
    urls = {
        'base': 'https://leetcode.com',
        'login': 'https://leetcode.com/accounts/login',
        'problem': 'https://leetcode.com/api/problems/algorithms',
        'sub': 'https://leetcode.com/api/submissions/'
    }

    code_regex = r"(?<=submissionCode: ').*(?=',\n  editCodeUrl)"

    def __init__(self, name, pwd):
        self.session = self.__login__(name, pwd)

    def __login__(self, name, pwd):
        login_url = 'https://leetcode.com/accounts/login'
        headers = {
            'User-Agent': 'Mozilla/5.0',
            'Referer': login_url
        }
        s = requests.Session()
        s.get(login_url)
        csrftoken = s.cookies['csrftoken']
        payload = {'csrfmiddlewaretoken': csrftoken,
                   'login': name,
                   'password': pwd}
        s.post(login_url, data=payload, headers=headers)
        return s

    def ac_status(self):
        content = self.session.get(self.urls['problem']).content
        status = json.loads(content)
        return status

    def problems(self, status='ac'):
        content = self.session.get(self.urls['problem']).content
        all_questions = json.loads(content)['stat_status_pairs']
        if status == 'all':
            return all_questions
        else:
            return [item for item in all_questions if item['status'] == status]

    def submissions(self, problem, languages=None):
        if languages is None:
            languages = {'cpp'}
        content = self.session.get(self.urls['sub'] + problem).content
        time.sleep(1)
        submissions = json.loads(content)['submissions_dump']
        result = []
        for submission in submissions:
            if submission['lang'] in languages:
                result.append(submission)
                languages.remove(submission['lang'])
            if len(languages) == 0: break
        return result

    def submission(self, url):
        html = self.session.get(self.urls['base'] + url).text
        reg = re.compile(self.code_regex)
        solution = reg.findall(html)[0]

        def cd(matched):
            return matched.group('value').encode('utf-8').decode('unicode-escape')

        return re.sub('(?P<value>\\\\u[0-9A-F]{4})', cd, solution)


def status():
    pass


def custom():
    return '## '


def table(problems):
    result = '| ' + ' | '.join(Config.column_order) + ' |\n'
    result += '|:---:' * len(Config.column_order) + '|\n'
    lines = []
    for problem in problems:
        line = '|' + '|'.join([Config.column[item](problem) for item in Config.column_order]) + '|'
        lines.append(line)
    lines.reverse()
    return result + '\n'.join(lines)


def main():
    api = API(Config.name, Config.pwd)
    print('generating README.md file...')
    # write 1. update time; 2. ac status; 3. solution table
    problems = api.problems()
    with open(Config.local_path + 'README.md', 'w+') as f:
        f.write('# Leetcode Solutions\n')
        f.write('This README file was build by [script/readme.py](%sscript/readme.py) file\n\n' % Config.github_url)
        f.write('Update Time:\t%s\n\n' % time.asctime(time.localtime()))
        status = api.ac_status()
        f.write('Status:\t%d/%d\n' % (status['num_solved'], status['num_total']))
        f.write('## Solution Table\n')
        f.write(table(problems))
    print('generating finish')

    # get latest submissions
    # for problem in problems:
    #     try:
    #         for solution in api.submissions(problem['stat']['question__title_slug']):
    #             f = open(Config.local_path + '/latest_submissions/' +  solution_name(problem, solution['lang']), 'w+')
    #             print('downloading submission ', problem['stat']['question__title'])
    #             f.write(api.submission(solution['url']))
    #             f.close()
    #     except:
    #         print('wrong in', problem['stat']['question__title'])



if __name__ == '__main__':
    config = configparser.ConfigParser()
    config.read('login.ini')
    Config.name = config['default']['name']
    Config.pwd = config['default']['pwd']
    Config.local_path = config['default']['path']
    main()
