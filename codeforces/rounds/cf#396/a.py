import sys

a = input();
b = input();

alen = len(a);
blen = len(b);

if(a == b):
	print(-1);
	sys.exit(0);
else:
	print(blen) if blen>alen else print(alen);
