from collections import Counter

n = input()

l = map(int,raw_input().split(" "))

l1 = Counter(l).keys()

if 0 in l1:
    print len(l1)-1
else:
    print len(l1)