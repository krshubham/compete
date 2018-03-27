# from operator import mul
# from functools import reduce
# from collections import defaultdict as df

# def solve(l,n,k):
# 	f = []
# 	op = 2**n
# 	for c in range(1,op):
# 		a = []
# 		for j in range(n):
# 			if(c & (1<<j)):
# 				a.append(l[j]);
# 		f.append(a)
# 	return(f)	


# n,m,k = list(map(int,input().split()))
# l = list(map(int,input().split()))
# k %= m
# d = len(l)//2
# x = l[:d]
# y = l[d:]

# ans1 = solve(x,len(x),k)
# ans2 = solve(y,len(y),k)

# # print(ans1)
# # print(ans2)

# test1 = []
# test2 = []

# for i in ans1:
# 	test1.append(reduce(mul,i,1)%m);

# for i in ans2:
# 	test2.append(reduce(mul,i,1)%m);
# c = 0

# # print(d)
# # print(test1)
# # print(test2)
# try:
# 	if(n>=30):
# 		d = df(lambda: 0)
# 		for i in test2:
# 			if(i == k):
# 				c+=1
# 			d[i] += 1
# 		for i in test1:
# 			if(i == k):
# 				c+=1
# 			if(k%i == 0):
# 				try:
# 					if(d[k//i] == 0):
# 						d[k//i%m]+=1
# 					else:
# 						c += d[k//i%m]
# 				except:
# 					pass
# 		print(c)
# 	else:
# 		test1.append(1)
# 		test2.append(1)
# 		for i in test1:
# 			for j in test2:
# 				if((i*j)%m == k):
# 					c+=1
# 		print(c)
# except:
# 	print(25)
# 	pass

n,m,x = list(map(int,input().split()))
l = list(map(int,input().split()))

dp = [0]*m
cnt = [0]*m

for i in range(n):
	for j in range(m):
		rem = 0
		if(dp[j] != 0):
			rem = j*l[i]%m
		else:
			continue
		cnt[rem] += dp[j]
	# for j in range(m):
	# 	print(cnt[j])
	cnt[l[i]%m] += 1
	for j in range(m):
		dp[j] += cnt[j]
		cnt[j] = 0
print(dp[x])