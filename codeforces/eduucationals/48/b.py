import re
a,b,q = list(map(int,input().split()))
s = input()
t = input()


def occurrences(text, sub):
    return len(re.findall('(?={0})'.format(re.escape(sub)), text))

for _ in range(q):
    x,y = list(map(int,input().split()))
    print(occurrences(s[x:y],t))

