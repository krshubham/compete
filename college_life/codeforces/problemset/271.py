a = int(input());
a+=1;
while(len(str(a)) != len(set(str(a)))):
	a += 1;
print(a);
