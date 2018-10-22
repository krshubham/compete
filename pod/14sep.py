
def main():
    fnum = int(input())
    height = int(input())
    dia = int(input())
    k = int(input())
    l = []
    for i in range(k):
        x = int(input())
        y = int(input())
        if(x == dia):
            l.append(y)
    cost = 0;
    l.sort()
    while(len(l) > 1):
        x = l[0]
        l.pop(0)
        y = l[0]
        l.pop(0)
        cost += (x+y);
        l.append(x+y)
        l.sort()
    print(cost)
    return 0;

main()