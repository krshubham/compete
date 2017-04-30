import re

t = int(input())

regex = '1*'
for i in range(t):
	s = input()
	s = s.split('0');
	a = [x for x in s if x!=''];
	if(len(a) != 1):
		print('NO')
	else:
		print('YES')