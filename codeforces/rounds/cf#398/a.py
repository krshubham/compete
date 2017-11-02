a = int(input());
l = [int(i) for i in input().split(' ')];
p = [];
m = max(l);
for i in l:
	# print('i is: ',i);
	if(i==m):
		j = i;
		if(j-1 in p):
			print(i,end=' ');
		else:
			print(i);
		while(j-1 in p):
			if(j-1 in p):
				if(j-2 in p):
					print(j-1,end=' ');
				else:
					print(j-1);
			else:
				print(j-1);
			j = j-1;
			p.remove(j);
		m = j-1;
	else:
		print();
		p.append(i);
		# print(p);
	# print('max value is',m);
		
