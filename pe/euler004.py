def is_palindrome(n) :
    return str(n) == str(n)[::-1]
 
pal = []
largest = 0
for a in range(100, 1000) :
    for b in range(100, 1000) :
        c = a*b
        if is_palindrome(c):
        	pal.append(c)
print pal