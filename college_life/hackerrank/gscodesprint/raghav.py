from re import match
orderbook = {}
def checkoid(var):
	if match("^\d+?\.\d+?$", var) is None:
		var = int(var)
		if(var >= 1 and var <= 2**63 -1):
			return True
		else:
			return False

def checktimestamp(var,lastts):
	if match("^\d+?\.\d+?$", var) is None:
		if(int(var) >= int(lastts)):
			lastts = max(int(lastts),int(var))
			return True
		else:
			return False

def checkSymbol(var):
	return var.isalpha()

def checkot(var):
	if(var != 'M' and var != 'L' and var != 'I'):
			return False
	return True

def checkside(var):
	if(var != 'B' and var != 'S'):
		return False
	return True

def checkprice(var):
	if match("^\d+?\.\d+?$", var) is None:
		return False
	return True

def checkquantity(var):
	if match("^\d+?\.\d+?$", var) is None:
		var = int(var)
		return (var >= 1 and var <= 2**63 -1)
	else:
		return False

def main():
	t = list(map(int,input().split()))[0]
	lastts = 0
	for _ in range(t):
		actions = list(map(str,input().split(',')))
		if(actions[0] == 'N'):
			try:
				oid = actions[1]
				ts = actions[2]
				symbol = actions[3]
				orderType = actions[4]
				side = actions[5]
				price = actions[6]
				quantity = actions[7]
			except:
				print('{} - Reject - 303 - Invalid order details'.format(oid))
				continue
			if(checkquantity(quantity) and checkprice(price) and checkside(side) and checkot(orderType) and checkSymbol(symbol) and checktimestamp(ts,lastts) and checkoid(oid)):
				try:
					order = orderbook[oid]
					print('{} - Reject - 303 - Invalid order details'.format(oid))
				except KeyError:
					orderbook[oid] = 'test'
					print('{} - Accept'.format(oid))
			else:
				print('{} - Reject - 303 - Invalid order details'.format(oid))

main()