t = int(input())
for i in range(t):
    a = input()
    if('21' in a or int(a)%21 == 0):
        print("The streak is broken!")
    else:
        print("The streak lives still in our heart!")