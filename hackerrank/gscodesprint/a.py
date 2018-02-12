import re
t = list(map(int,input().split()))[0]
book = {}
lastts = 0
def check(var,vt):
	if(vt == 'oid'):
		if re.match("^\d+?\.\d+?$", var) is None:
			var = int(var)
			if(var >= 1 and var <= 2**63 -1):
				return True
		else:
			return False
	elif(vt == 'ts'):
		if re.match("^\d+?\.\d+?$", var) is None:
				if(int(var) >= int(lastts)):
					return True
				else:
					return False
	elif(vt == 'symbol'):
		return var.isalpha()
	elif(vt == 'orderType'):
		if(var != 'M' and var != 'L' and var != 'I'):
			return False
	elif(vt == 'side'):
		if(var != 'B' and var != 'S'):
			return False
	elif(vt == 'price'):
		if re.match("^\d+?\.\d+?$", var) is None:
			return False
	elif(vt == 'quantity'):
		if re.match("^\d+?\.\d+?$", var) is None:
			var = int(var)
			return (var >= 1 and var <= 2**63 -1)
		else:
			return False
	return True
for _ in range(t):
	action = list(map(str,input().split(',')))
	cmd = action[0]
	'''
	order_id: int
	ts: int
	symbol: str
	orderType: {M,L,I}
	Side: {B,S}
	Price: float
	Quantity: int
	'''
	if(cmd == 'N'):
		try:
			oid = action[1]
			ts = action[2]
			symbol = action[3]
			orderType = action[4]
			side = action[5]
			price = action[6]
			quantity = action[7]
		except:
			print('{} - Reject - 303 - Invalid order details'.format(oid))
			continue
		if(check(oid,'oid') and check(ts,'ts') and check(symbol,'symbol') and check(orderType,'orderType') and check(side,'side') and check(price,'price') and check(quantity,'quantity')):
			try:
				x = book[oid]
				print('{} - Reject - 303 - Invalid order details'.format(oid))
			except KeyError:
				#The order doesn't exist now
				# print('The Key doesn\'t exist')
				book[oid] = {
					'ts': ts,
					'symbol': symbol,
					'orderType': orderType,
					'side': side,
					'price': price,
					'quantity': quantity
				}
				# print(oid,end=' ')
				# print('-',end=' ')
				# print('Accept')
				lastts = max(int(lastts),int(ts))
				print('{} - Accept'.format(oid))
		else:
			# print(check(oid,'oid'))
			# print(check(ts,'ts'))
			# print(check(symbol,'symbol'))
			# print(check(orderType,'orderType')) 
			# print(check(side,'side'))
			# print(check(price,'price'))
			# print(check(quantity,'quantity'))
			print('{} - Reject - 303 - Invalid order details'.format(oid))
	if(cmd == 'A'):
		try:
			oid = action[1]
			ts = action[2]
			symbol = action[3]
			orderType = action[4]
			side = action[5]
			price = action[6]
			quantity = action[7]
		except:
			print('{} - Reject - 303 - Invalid order details'.format(oid))
			continue
		if(check(oid,'oid') and check(ts,'ts') and check(symbol,'symbol') and check(orderType,'orderType') and check(side,'side') and check(price,'price') and check(quantity,'quantity')):
			try:
				x = book[oid]
				x['ts'] = ts
				if(x['symbol'] != symbol or x['orderType'] != orderType or side != x['side']):
					print('{} - AmendReject - 101 - Invalid amendment details'.format(oid))
				else:
					lastts = max(int(lastts),int(ts))
					book[oid]['price'] = price
					book[oid]['quantity'] = quantity
					book[oid]['ts'] = ts
					print('{} - AmendAccept'.format(oid))
			except KeyError:
				print('{} - AmendReject - 404 - Order does not exist'.format(oid))
				continue
		else:
			print('{} - AmendReject - 101 - Invalid amendment details'.format(oid))
	if(cmd == 'X'):
		oid = action[1]
		ts = action[2]
		# There will not be any scenario when ts will be wrong for a cancel action
		if(check(oid,'oid') and check(ts,'ts')):
			try:
				x = book[oid]
				lastts = max(int(lastts),int(ts))
				del book[oid]
				print('{} - CancelAccept'.format(oid))
			except KeyError:
				print('{} - CancelReject - 404 - Order does not exist'.format(oid))
				continue
	# if(cmd == 'M'):
	# 	if(len(action) == 3):
	# 		print('Symbol is present')
	# 	else:
	# 		#only ts
	# 		