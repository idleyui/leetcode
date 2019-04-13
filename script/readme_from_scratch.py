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
        '#': lambda item: "%03d" % item['stat']['question_id'],
        'Title': lambda item: '[' + item['stat']['question__title'] + '](' + Config.leetcode_url + item['stat'][
            'question__title_slug'] + ')',
        'Difficulty': lambda item: Config.difficulty[item['difficulty']['level'] - 1],
        'Solution': lambda item: '[cpp](' + Config.github_url + 'latest_submissions/' + solution_name(item, 'cpp') + ')'
    }
    column_order = ['#', 'Title', 'Difficulty', 'Solution']


def init(filename):
    config = configparser.ConfigParser()
    config.read(filename)
    Config.name = config['login']['name']
    Config.pwd = config['login']['pwd']
    Config.local_path = config['st']['path']


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

    def problems(self, status='ac'):
        content = self.session.get(self.urls['problem']).content
        all_questions = json.loads(content)['stat_status_pairs']
        if status == 'all':
            return json.loads(content), all_questions
        else:
            return json.loads(content), [item for item in all_questions if item['status'] == status]

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


def table(problems):
    """Generate solution table string by problems json

    :param problems: leetcode problems json api
    :return: table string
    """
    result = '| ' + ' | '.join(Config.column_order) + ' |\n'
    result += '|:---:' * len(Config.column_order) + '|\n'
    lines = []
    for problem in problems:
        line = '|' + '|'.join([Config.column[item](problem) for item in Config.column_order]) + '|'
        lines.append(line)
    lines.reverse()
    return result + '\n'.join(lines)


def readme(status: json, problems: json):
    """Generate README.md file

    1. Update time 2. Update AC status 3. Update solution table

    :param api: leetcode API class
    :return:
    """
    print('generating README.md file...')

    with open(Config.local_path + 'README.md', 'w+') as f:
        f.write('# Leetcode Solutions\n')
        f.write('This README file was build by [script/readme_from_scratch.py](%sscript/readme_from_scratch.py) file\n\n' % Config.github_url)
        f.write('Update Time:\t%s\n\n' % time.asctime(time.localtime()))

        f.write('Status:\t%d/%d\n' % (status['num_solved'], status['num_total']))

        f.write('## Solution Table\n')
        f.write(table(problems))

    print('generating finish')


def download(api, problems, language):
    wrong_list = []
    for problem in problems:
        # path = Config.local_path + '/latest_submissions/' + solution_name(problem, solution['lang'])
        path = Config.local_path + '/latest_submissions/' + solution_name(problem, language)
        if os.path.exists(path):
            print("solution %s exists" % solution_name(problem, language))
            continue

        try:
            for solution in api.submissions(problem['stat']['question__title_slug']):
                f = open(path, 'w+')
                print('downloading submission ', problem['stat']['question__title'])
                f.write(api.submission(solution['url']))
                f.close()
                time.sleep(random.randint(0, 3))


        except:
            wrong_list.append(problem)
            print('wrong in', problem['stat']['question__title'])

    if len(wrong_list) > 0:
        download(api, wrong_list, 'cpp')


def default_update():
    """Default update

    Update README.md and latest submissions

    :return:
    """
    api = API(Config.name, Config.pwd)
    status, problems = api.problems()

    readme(status, problems)
    download(api, problems, 'cpp')


if __name__ == '__main__':
    init('login.ini')  # read configurations from 'login.ini'
    default_update()  # update solution table and
