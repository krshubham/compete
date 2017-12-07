from itertools import combinations as c
length = int(input())
seq = list(map(int,input().split()))
print(sum(a & b for a, b in c(seq,2)))