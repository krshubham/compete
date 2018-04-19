import re

pattern = '^a+b+c+$'
s = list(map(str,input().split()))[0]

# print(str(re.match(pattern,s)))

if re.match(pattern,s):
	if(s.count('c') == s.count('b') or s.count('c') == s.count('a')):
		print('YES')
	else:
		print('NO')
else:
	print('NO')