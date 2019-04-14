# LeetCode Solution Table Build Script

## Usage

`readme.py`

build README.md with solution table
- edit configuration in readme.py
    - necessary:
        - edit `root`(local project root) and `url`(github repository url) in `__main__`
        - write your own `README.set_solution_dict()` method
    - optional:
        - solution table style in `README.table()` method
        - readme style in `README.readme()` method
- run readme.py
    ```shell
    $ cd leetcode
    $ python script/readme.py
    ```