import sys

s1 = input()
s2 = input()
if(len(s2) < len(s1)):
    sys.exit(1)
mapping = {}
for i in range(len(s1)):
    try:
        mapped_letter = mapping[s1[i]]
        if(mapped_letter != s2[i]):
            print("False")
            sys.exit(0)
    except KeyError:
        mapping[s1[i]] = s2[i]
print("True")
