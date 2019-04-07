import sys
s = input()
l = ["Danil", "Olya", "Slava","Ann","Nikita"]
c = 0
for i in l:
	if(i in s):
		if(s.count(i) == 1):
			c+=1
		else:
			print("NO")
			sys.exit(0)
if(c == 1):
	print("YES")
else:
	print("NO")