import sys
import os
import shutil
dir_1 = sys.argv[1]
dir_2 = sys.argv[2]
for root, dirs, files in os.walk(dir_1):
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
print(dir_1)
print(dir_2)
