from math import sqrt, pow
import sys

def distance(a, b):
  return pow(a[0] - b[0],2) + pow(a[1] - b[1],2)

def bruteMin(points, current=float("inf")):
  if len(points) < 2: return current
  else:
    head = points[0]
    del points[0]
    newMin = min([distance(head, x) for x in points])
    newCurrent = min([newMin, current])
    return bruteMin(points, newCurrent)

def divideMin(points):
  half = len(sorted(points))/2
  minimum = min([bruteMin(points[:half]), bruteMin(points[half:])])
  nearLine = filter(lambda x: x[0] > half - minimum and x[0] < half + minimum, points)
  return min([bruteMin(nearLine), minimum])

t = int(input())

pts = [];
for i in range(t):
  a,b,c = raw_input().split()
  if(a == '+'):
    pts.append((int(b),int(c)))
    if(len(pts) == 1):
      print(0)
    else:
      print(int(divideMin(pts)))

  elif(a == '-'):
    pts.remove((int(b),int(c)))
    if(len(pts) == 1):
      print(0)
    else:
      print(int(divideMin(pts)))
sys.exit(0)
