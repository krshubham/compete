s = input()
c = 0
while("ab" in s):
	c+=1
	c %= 1000000007
	s = s.replace("ab","bba",1)
print(c%1000000007)