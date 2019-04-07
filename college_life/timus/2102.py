MAX_PRIME = 1953125

def primes_sieve(limit):
    a = [True] * limit
    a[:3] = False, False, True
    yield 2
    for i in range(3, limit, 2):
        if a[i]:
            yield i
            for n in range(i*i, limit, 2 * i):
                a[n] = False

def factorization(n, primes):
    simple_dividers = (p for p in primes if n % p == 0)
    for p in simple_dividers:
        while n % p == 0:
            n //= p
            yield p
    if n != 1:
        yield n

def main():
    n = int(input())
    primes = primes_sieve(MAX_PRIME)
    dividers = list(factorization(n, primes))
    if len(dividers) == 20:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()