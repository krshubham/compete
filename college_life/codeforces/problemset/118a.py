vowels = ['a','e','i','o','u','y'];
a = list(input());
for i in range(0,len(a)):
	if(a[i] in vowels):
		a[i] = '';
		
s = '';
for i in a:
	s += i;
print(s);