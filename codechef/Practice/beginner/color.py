import sys

t = int(input())
for i in range(t):
	n = int(input());
	s = input();
	rr=0;rg=0;rb=0
	for i in s:
		if(i == 'R'):
			rr += 1;
		elif(i == 'G'):
			rg += 1;
		else:
			rb += 1;
	l = [rr,rg,rb];
	print(len(s) - max(l));
sys.exit(0);