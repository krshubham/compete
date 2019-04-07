n = int(input())
typed = {}
total_time = 0
for i in range(n):
    left = False
    right = False
    time_for_word = 0
    s = input()
    if s in typed:
        total_time += typed[s]//2
        continue
    if s[0] == 'd' or s[0] == 'f':
        left = True
    else:
        right = True
    time_for_word += 2
    for i in range(1,len(s)):
        if s[i] == 'f' or s[i] == 'd':
            if right:
                time_for_word += 2
            else:
                time_for_word += 4
            left = True
            right = False
        else:
            if left:
                time_for_word += 2
            else:
                time_for_word += 4
            left = False
            right = True
    typed[s] = time_for_word
    total_time += time_for_word
print(total_time)
