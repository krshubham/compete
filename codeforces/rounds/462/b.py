def main():
	k = list(map(int,input().split()))[0]
	if(k <= 36):
		if(k == 0):
			print(1)
		elif(k%2 == 0):
			for i in range(k//2):
				print(8,end='')
		else:
			powa = lol(k)
			ans = ""
			for i in powa:
				if(i%2 == 0):
					for j in range(i//2):
						ans += '8'
				else:
					ans += str('4')
			print(ans)
	else:
		print(-1)

def lol(x):
    powa = []
    i = 1
    while i <= x:
        if i & x:
            powa.append(i)
        i <<= 1
    return powa

main()