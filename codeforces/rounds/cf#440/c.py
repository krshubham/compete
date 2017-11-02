l = [4,6,8,9]
c = 0
for i in range(4,1000001):
	for j in l:
		if(i%j == 0):
			c+=1
# print(c == len([i for i in range(4,1000000)]))
print(c)
