import os
import random
from shutil import copyfile, rmtree

path = os.getcwd() + '/bobo_town'
bobo_path = os.getcwd() + '/bobo.txt'

depth = random.randint(5, 10)
width = random.randint(2, 4)

def cleanup(path):
    if os.path.exists(path) and os.path.isdir(path):
        rmtree(path)

def generate_dirs(path, depth, width):
    for i in range(width):
        os.makedirs(path + '/' + str(i))
        if (depth - 1 > 0):
            generate_dirs(path + '/' + str(i), depth - 1, width)


def plant_bobo(path, depth, width, bobo_path):
    bobo_home = path
    for i in range(random.randint(1, depth)):
        bobo_home += '/' + str(random.randint(1, width - 1))
    print(bobo_home)
    copyfile(bobo_path, bobo_home + '/bobo.txt')



cleanup(path)
generate_dirs(path, depth, width)
plant_bobo(path, depth, width, bobo_path)