t = int(input())

l = []
done = False
for i in range(t):
	a = input()
	if(a[0] == a[1] and (a[0] == 'O' and a[1] == 'O') and not(done)):
		done = True
		l.append("++" + a[2] + a[3] + a[4])
	elif(a[3] == a[4] and (a[3] == 'O' and a[4] == 'O') and not(done)):
		done = True
		l.append(a[0] + a[1] + a[2] + "++")
	else:
		l.append(a)
if(done):
	print("YES")
	for i in l:
		print(i)
else:
	print("NO")
