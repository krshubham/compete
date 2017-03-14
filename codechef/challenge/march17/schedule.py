import re
import sys
t = int(input());
m = [];
for i in range(t):
	n,k = input().split(' ');
	n = int(n);k = int(k);
	string = input();
	for i in range(n,1,-1):
		match1 = re.search(r'1{'+str(i)+'}',string);
		match0 = re.search(r'0{'+str(i)+'}',string);
		if(match1):
			m.append(i);
		if(match0):
			m.append(i);
	print(min(m));
sys.exit(0);

