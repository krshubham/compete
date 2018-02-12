def solve(l,ans):
    c = 0
    for i in range(len(l) - 1, 1, -1):
        for j in range(i - 1, 0, -1):
            if l[i] % l[j] == 0:
                c += ans[j]
    return c

def answer(l):
    ans = [0]*len(l)
    for i in range(len(l)):
        for j in range(i + 1, len(l)):
            if l[j] % l[i] == 0:
                ans[j] += 1
    return solve(l,ans)

print answer([1, 2, 3, 4, 5, 6])