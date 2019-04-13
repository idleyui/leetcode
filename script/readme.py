import requests
import json
import time
import re
import configparser
import os
import random


def solution_name(item, suffix):
    return "%03d_%s.%s" % (item['stat']['frontend_question_id'], item['stat']['question__title'].replace(' ', '_'), suffix)


class Config:
    """Basic configurations
        Attributes:
            local_path:     path to store algorithms file
            github_url:     your leetcode repository url in github
            leetcode_url:   leetcode url
            difficulty:
            column:         generate template for columns
            column_order:   order of your column
    """
    local_path = ''
    github_url = 'https://github.com/leelddd/leetcode/blob/master/'
    leetcode_url = 'https://leetcode.com/problems/'
    difficulty = ['Easy', 'Medium', 'Hard']
    column = {
        '#': lambda item: "%03d" % item['stat']['frontend_question_id'],
        'Title': lambda item: '[' + item['stat']['question__title'] + '](' + Config.leetcode_url + item['stat'][
            'question__title_slug'] + ')',
        'Difficulty': lambda item: Config.difficulty[item['difficulty']['level'] - 1],
        'Solution': lambda item: '[cpp](' + Config.github_url + 'solution/' + solution_name(item, 'cpp') + ')'
    }
    column_order = ['#', 'Title', 'Difficulty', 'Solution']


def table(problem_dic: dict, solution_list: list):
    """Generate solution table string by problems json

    :param problems: leetcode problems json api
    :return: table string
    """
    result = '| ' + ' | '.join(Config.column_order) + ' |\n'
    result += '|:---:' * len(Config.column_order) + '|\n'
    lines = []
    for problem in solution_list:
        line = '|' + '|'.join(
            [Config.column[item](problem_dic[problem]) for item in Config.column_order]) + '|'
        lines.append(line)
    lines.reverse()
    return result + '\n'.join(lines)


# def readme(api_json: json, problems: dict, mine: dict):
def readme(problem_dic: dict, problem_cnt: dict, solution_list: list, solution_cnt: dict):
    """Generate README.md file

    Format:

    # LeetCode Solutions
    built by this file
    update time
    AC status:
        - total
        - easy
        - medium
        - hard
    solution table

    Update:
    1. Update update time 2. Update AC status 3. Update solution table

    :param api: leetcode API class
    :return:
    """
    print('generating README.md file...')

    with open(Config.local_path + 'README.md', 'w+') as f:
        f.write('# Leetcode Solutions\n')
        f.write(
            'This README file was build by [script/readme.py](%sscript/readme.py) file\n\n' % Config.github_url)
        f.write('Update Time:\t%s\n\n' % time.asctime(time.localtime()))

        f.write('Status:\t%d/%d\n\n' % (solution_cnt['num_total'], problem_cnt['num_total']))
        f.write('Easy:\t%d/%d\n\n' % (solution_cnt['easy'], problem_cnt['easy']))
        f.write('Medium:\t%d/%d\n\n' % (solution_cnt['medium'], problem_cnt['medium']))
        f.write('Hard:\t%d/%d\n\n' % (solution_cnt['hard'], problem_cnt['hard']))

        f.write('## Solution Table\n')
        f.write(table(problem_dic, solution_list))

    print('generating finish')


def get_problems(solution_path):
    """
    :return:    problem_dic:dict    {1: {problem_json}, 2: {problem_json}}
    :return:    problem_cnt:dict    {'num_total': 973, 'easy': 269, 'medium': 494, 'hard': 210}
    :return:    solution_list:list  [1,2,3,...]
    :return:    solution_cnt:dict   {'num_total': 973, 'easy': 269, 'medium': 494, 'hard': 210}
    """
    api = 'https://leetcode.com/api/problems/algorithms/'
    api_json = requests.get(url=api).json()

    problem_dic = {int(item['stat']['frontend_question_id']): item for item in api_json['stat_status_pairs']}

    def group_by_difficulty(level):
        return sum([1 if item['difficulty']['level'] == level else 0 for item in api_json['stat_status_pairs']])

    problem_cnt = {
        'num_total': api_json['num_total'],
        'easy': group_by_difficulty(1),
        'medium': group_by_difficulty(2),
        'hard': group_by_difficulty(3)
    }

    file_list = os.listdir(solution_path)[0:-1]
    solution_list = [int(item[:3]) for item in file_list]

    def cnt_by_diff(level):
        return sum([1 if problem_dic[f]['difficulty']['level'] == level else 0
                    for f in solution_list])

    solution_cnt = {
        'num_total': len(file_list),
        'easy': cnt_by_diff(1),
        'medium': cnt_by_diff(2),
        'hard': cnt_by_diff(3),
    }

    return problem_dic, problem_cnt, solution_list, solution_cnt


def update(solution_path):
    problem_dic, problem_cnt, solution_list, solution_cnt = get_problems(solution_path)
    readme(problem_dic, problem_cnt, solution_list, solution_cnt)


if __name__ == '__main__':
    update('./solution/')  # update solution table and
