from functools import lru_cache

@lru_cache(None)
def cost(seq, m):
    return (seq[-1] - seq[0]) * m

@lru_cache(None)
def solve(seq):
    global count
    count += 1
    if len(seq) == 2:
        return 0, ()
    results = []
    for i in range(1, len(seq)-1):
        left, x, right = seq[:i+1], seq[i], seq[i:]
        val = cost(left, a) + cost(right, b)
        lval, lcuts = solve(left)
        rval, rcuts = solve(right)
        results.append((val + lval + rval, (x,) + lcuts + rcuts))
    return min(results)

count = 0

t = int(input())
for i in range(t):
    a,b  = map(int,input().split())
    n = int(input())
    seq = tuple(map(int,input().split()))

    val, cuts = solve(seq)
    print(val)