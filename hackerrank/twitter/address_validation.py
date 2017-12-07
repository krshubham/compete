ip = ['This line has junk text.' , '121.18.19.20', '1:db8:0:0:0ff00:0042:8329']
for i in ip:
	if('.' in i):
		i = i.split('.')
		if(len(i) == 4):
			for j in i:
				if(int(j) < 0 or int(j) > 255):
					break
			else:
				print('IPv4')
				continue
	if(':' in i):
		i = i.split(':')
		if(len(i) == 8):
			for j in i:
				if(j < '0000' or j > 'ffff'):
					print(j)
					break
			else:
				print('IPv6')
				continue
	print('Neither')

	