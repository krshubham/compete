import sys

t = int(input())
for i in range(t):
	s = list(input());
	o = s.count('1');
	z = s.count('0');

	if(o == 1 or z == 1 and not(o == 1 and z==1)):
		print('Yes')
	else:
		print('No')
