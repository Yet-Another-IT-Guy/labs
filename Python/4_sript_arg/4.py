import sys
import os
import shutil
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-i', '--inputdir')
parser.add_argument('-o', '--outputdir')
parser.add_argument('-r', '--recursive', type=bool, default=False)
args = parser.parse_args()
dir_1 = args.inputdir
dir_2 = args.outputdir
if not os.path.exists(dir_1):
    print("Directory does not exist")
    sys.exit(2)
if not os.path.exists(dir_2):
    os.mkdir(dir_2)
recur = args.recursive
def move_files(dir_1, dir_2, recur):
    for root, dirs, files in os.walk(dir_1):
        if not recur:
            del dirs[:]
        for name in files:
            curr = os.path.join(root, name)
            if not "." in name:
              extension = "without_extension"
            else:
                extension = name[name.rfind(".")+1:]
            new_dir = os.path.join(dir_2, extension)
            if not os.path.exists(new_dir):
                os.mkdir(new_dir)
            shutil.move(curr, os.path.join(new_dir, name))
           #if not recur:
             #   print("Pop")
              #  return
move_files(dir_1, dir_2, recur)
