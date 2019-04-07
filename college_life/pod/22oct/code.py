def main():
    n,m = list(map(int,input().split()))
    ones = []    
    for i in range(n):
        s = input()
        for j in range(len(s)):
            if(s[j] == '1'):
                ones.append((i,j))
    distances = {}
    for i in range(len(ones)):
        for j in range(i+1,len(ones)):
            x = abs(ones[i][0]-ones[j][0])+abs(ones[i][1]-ones[j][1])
            if x in distances:
                distances[x]+=1
            else:
                distances[x] = 1
    q = int(input())
    for _ in range(q):
        x = int(input())
        if x in distances:
            print(distances[x])
        else:
            print('0')


main()