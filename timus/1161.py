total = int(raw_input())

stripies = []
not_visited = 0

for x in xrange(total):
	stripies.append(int(raw_input()))

stripies.sort(reverse=True)

while len(stripies) > 1:
	bump = 2* ( (stripies[0]*stripies[1])**0.5 )
	stripies = stripies[2:]
	stripies.append(bump)
	stripies.sort(reverse=True)

print ("{0:.2f}".format(stripies[0]))