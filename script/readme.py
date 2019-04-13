import requests
import json
import time
import re
import configparser
import os
import random


def solution_name(item, suffix):
    return "%03d_%s.%s" % (item['stat']['question_id'], item['stat']['question__title'].replace(' ', '_'), suffix)


class Config:
    """Basic configurations
        Attributes:
            name:           leetcode account name
            pwd:            leetcode account password
            local_path:     path to store algorithms file
            github_url:     your leetcode repository url in github
            leetcode_url:   leetcode url
            difficulty:
            column:         generate template for columns
            column_order:   order of your column
    """
    name = ''
    pwd = ''
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


def table(api_json: json, mine: dict):
    """Generate solution table string by problems json

    :param problems: leetcode problems json api
    :return: table string
    """
    result = '| ' + ' | '.join(Config.column_order) + ' |\n'
    result += '|:---:' * len(Config.column_order) + '|\n'
    lines = []
    for problem in mine['ac_list']:
        line = '|' + '|'.join([Config.column[item](api_json['stat_status_pairs'][-problem]) for item in Config.column_order]) + '|'
        lines.append(line)
    lines.reverse()
    return result + '\n'.join(lines)


def readme(api_json: json, problems: dict, mine: dict):
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

        f.write('Status:\t%d/%d\n\n' % (mine['num_total'], problems['num_total']))
        f.write('Easy:\t%d/%d\n\n' % (mine['easy'], problems['easy']))
        f.write('Medium:\t%d/%d\n\n' % (mine['medium'], problems['medium']))
        f.write('Hard:\t%d/%d\n\n' % (mine['hard'], problems['hard']))

        f.write('## Solution Table\n')
        f.write(table(api_json, mine))

    print('generating finish')


def default_update(solution_path):
    """Default update

    Update README.md and latest submissions

    :return:
    """
    api_json, problems = get_problems()
    mine = get_mine(solution_path, api_json)

    readme(api_json, problems, mine)


def get_problems():
    """
    :return {'num_total': 973, 'easy': 269, 'medium': 494, 'hard': 210}
    """
    api = 'https://leetcode.com/api/problems/algorithms/'
    api_json = requests.get(url=api).json()
    problems = {}
    problems['num_total'] = api_json['num_total']

    def group_by_difficulty(level):
        return sum([1 if item['difficulty']['level'] == level else 0 for item in api_json['stat_status_pairs']])

    problems['easy'] = group_by_difficulty(1)
    problems['medium'] = group_by_difficulty(2)
    problems['hard'] = group_by_difficulty(3)
    return api_json, problems


def get_mine(solution_path: str, api_json: json):
    """
    :param api_json:
    :return: {'num_total': 0, 'easy', 0, 'medium': 0, 'hard': 0}
    """
    mine = {}
    file_list = os.listdir(solution_path)[0:-1]
    ac_list = [int(item[:3]) for item in file_list]
    mine['num_total'] = len(file_list)

    def cnt_by_diff(level):
        return sum([1 if api_json['stat_status_pairs'][-f]['difficulty']['level'] == level else 0
                    for f in ac_list])

    mine['easy'] = cnt_by_diff(1)
    mine['medium'] = cnt_by_diff(2)
    mine['hard'] = cnt_by_diff(3)
    mine['ac_list'] = ac_list
    return mine


if __name__ == '__main__':
    # api_json, pb = get_problems()
    # mine = get_mine('../solution/', api_json)
    # print(pb, mine)
    default_update('./solution/')  # update solution table and
