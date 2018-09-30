from collections import deque
import os

path = os.getcwd() + '/bobo_town'


def find_bobo_path(path, GREAT_BOBO):
    to_check = deque()
    to_check.append(path)

    while to_check:
        next_path = to_check.popleft()
        in_dir = os.scandir(next_path)
        for item in in_dir:
            if item.name == GREAT_BOBO:
                return next_path + '/' + GREAT_BOBO
            if item.is_dir():
                new_path = next_path + '/' + item.name
                to_check.append(new_path)


bobo_path = find_bobo_path(path, 'bobo.txt')

if bobo_path is None:
    print('где же этот чертов бобо')
    exit(0)

print(open(bobo_path).read())
