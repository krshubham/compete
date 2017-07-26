import math
def is_prime(a):
    return all(a%i for i in range(2, a))



def answer(n):
    l=[]
    num=2
    while(len(l)<=(n+6)):
        if(is_prime(num)):
            nis=str(num)
            li=list(nis)
            l.extend(li)
        num=num+1
    ans=l[n:n+5]
    s=''.join(ans)
    return s

a = answer(0)
print(a)
a = answer(3)
print(a)
