t = int(input())

for i in range(t):
	a = input();
	l = set([i for i in input().split(" ")]);
	j = set([i for i in input().split(" ")]);
	ns = l.intersection(j);
	print(len(ns));