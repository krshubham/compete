#the shittiest mistake in life is to hurry. Due to hurry I ended up making 4 WA for this ! :(! Lesson learnt
t = int(input())
for i in range(t):
    a = input().strip().split(' ');
    if(len(a) == 1):
        print(a[0].title())
    else:
        s = ""
        for i in range(0,len(a)):
            if(i != len(a)-1):
                s+= a[i][0].title()
                s+='. '
            else:
                s+=a[i].title()
        print(s)