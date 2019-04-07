
def main():
    n = int(input())
    if(n == 1):
        print("impossible")
        return(0)
    num_lines = 2*n-1
    num_stars = n
    num_spaces = 1
    for _ in range(n):
        for i in range(num_stars):
            print('*',end='')
        for i in range(num_spaces):
            print(' ',end='')
        for i in range(num_stars):
            print('*',end='')
        print()
        num_spaces+= 2
        num_stars-=1
    num_stars+=1
    num_spaces-=2
    for _ in range(n-1):
        num_spaces -= 2
        num_stars+=1
        for i in range(num_stars):
            print('*',end='')
        for i in range(num_spaces):
            print(' ',end='')
        for i in range(num_stars):
            print('*',end='')
        print()
    return(0)


main()