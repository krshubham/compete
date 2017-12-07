p = input()
t = input()
p = bin(int(p,16))[2:]
t = bin(int(t,16))[2:]
print(str(hex(p.count(t)))[2:])