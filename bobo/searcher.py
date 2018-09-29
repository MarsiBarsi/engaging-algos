import os

path = os.getcwd() + '/bobo_town'


def find_bobo_path(path, GREAT_BOBO):
    in_dir = os.scandir(path)
    for item in in_dir:
        if item.name == GREAT_BOBO:
            return path + '/' + GREAT_BOBO
        if item.is_dir():
            new_path = path + '/' + item.name
            result = find_bobo_path(new_path, GREAT_BOBO)
            if result:
                return result


bobo_path = find_bobo_path(path, 'bobo.txt')

if bobo_path is None:
    print('где же этот чертов бобо')
    exit(0)

print(open(bobo_path).read())
