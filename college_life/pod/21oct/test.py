prize = float(input())
num = int(input())
players = []
for i in range(0,num):
    det = input().split()
    players.append((det[0],int(det[1])))
first = int(input())-1
name = input()
prize_dec = 0
while players[first][0]!=name:
    prize_dec+=1
    first = players[first][1]-1
prize = prize-(prize_dec*2/100)*prize
print(format(prize,'0.2f'))
