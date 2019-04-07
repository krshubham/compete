import math

t = int(input())
for i in range(t):
    n,k=input().split(' ')
    n=int(n)
    k=int(k)
    z = pow(2,n)
    p=0
    q=z
    yo=k
    nt=n
    for i in range(1,n):
        if(yo%2==0):
            pp=pow(2,nt)
            xx=yo%pp
            yo = yo - (xx//2)
        else:
            pp=pow(2,nt)
            xx=yo%pp
            xx=pow(2,nt)-xx-1
            yo=yo+(xx)//2
        nt = nt-1
    print(yo)


