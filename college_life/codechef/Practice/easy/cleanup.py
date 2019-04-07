t = int(input())
for i in range(t):
	m=[int(i) for i in input().split()];
	n=[int(i) for i in input().split()];

	li=list(range(1,m[0]+1));

	for i in n:
		if i in li:
			li.remove(i);
	C=[];
	S=[];
	for i in range(len(li)):
		if i%2==0:
			C.append(str(li[i]));
		else:
			S.append(str(li[i]));
	print (' '.join(C));
	print (' '.join(S));