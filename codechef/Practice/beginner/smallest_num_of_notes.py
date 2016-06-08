n = int(input())
for i in range(0,n):
	a = int(input())
	num = a//100 + (a%100)//50 + (a%100%50)//10 + (a%100%50%10)//5 + (a%100%50%10%5)//2 + (a%100%50%10%5%2)//1
	print(num)