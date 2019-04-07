n = int(input())
s = input()
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

a = 1
b = 1
c = 1
d = 1
for i in numbers:
	if(i in s):
		a = 0
		break
for i in lower_case:
	if(i in s):
		b = 0
		break

for i in upper_case:
	if(i in s):
		c = 0
		break

for i in special_characters:
	if(i in s):
		d = 0
		break
x = a+b+c+d
y = x + n
if(y < 6):
	print(x + 6-y)
else:
	print(x)