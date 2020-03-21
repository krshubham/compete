from getpass import getpass
import sys
import urllib.request
import re
import operator
from collections import OrderedDict

username = input("username: ")
password = getpass(prompt="Password: ")

if username != "appdynamics" or password != "Appd@1234":
    sys.exit(1)

link = input("Enter the url: ")
contents = urllib.request.urlopen(link).read().decode('utf-8')
contents = re.split(r'[\W0-9_]+', contents)
nums = {}
for word in contents:
    word = word.lower()
    try:
        nums[word] = nums[word] + 1
    except KeyError:
        nums[word] = 1

nums = OrderedDict(sorted(nums.items(),key=lambda kv: kv[1], reverse=True))
i = 0;
for key in nums:
    if(i < 5):
        print(key)
        i+=1
