import subprocess
import os
import sys

def validate(verbstring):
    try:
        verbsegments = verbstring.split(" ")
        int(verbsegments[0], 16) and int(verbsegments[1], 16) and int(verbsegments[2], 16)
        return verbsegments
    except Exception as e:
        print("One or more verb strings was invalid.")
        exit()
if os.geteuid() != 0:
    print("You must run this script with sudo.")
    exit()

if len(sys.argv) == 1:
    print("Usage: ./applyverbs.py path_to_verbs")
    exit()

try:
    f = open(sys.argv[1], "r")
except Exception as e:
    print(str(e))
    exit()

verbstrings = f.read().splitlines()
verbsegments = list(map(validate, verbstrings))

print("Applying verbs...")
for verbsegment in verbsegments:
    args = ['hda-verb', '/dev/snd/hwC0D0', *verbsegment]
    subprocess.call(args, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
f.close()
print("Verbs applied!")
