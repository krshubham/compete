import re
s = input();
p = re.search('h+[a-z]*e[a-z]*l[a-z]*l+[a-z]*o+[a-z]*',s)
if(p):
	print('YES');
else:
	print('NO');