t = list(map(int,input().split()))
n,m,x,k = list(map(int,input().split()))
s = list(map(str,input().split()))[0]
a = 0;b = 0
for i in s:
	if(i == 'E'):
		a+=1
		continue
	b +=1
if(k < n or m*x < n):
	print('no')
cnt = 0 #d
mid = 0 #z
for i in range(1,m+1):
	if i%2 == 0:
		mid = min(a,x);
		 a = max(x-z,0LL);
	else:
		mid = min(b,x)
		b = max(y-mid,0);
	cnt += mid
