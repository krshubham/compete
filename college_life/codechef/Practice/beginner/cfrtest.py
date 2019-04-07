a = int(input());
for i in range(a):
	n = int(input());
	l = [i for i in input().split(" ")];
	print(len(set(l)));