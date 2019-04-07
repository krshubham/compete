import sys
import _thread
import threading
import time

def print_time( threadName, delay):
   count = 0
   while count < 5:
      time.sleep(delay)
      count += 1
      print ("%s: %s" % ( threadName, time.ctime(time.time()) ))


class myThread (threading.Thread):
   def __init__(self, threadID, name, counter):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.counter = counter
   def run(self):
      print ("Starting " + self.name)
      print_time(self.name, self.counter, 5)
      print ("Exiting " + self.name)

def print_time(threadName, delay, counter):
   while counter:
      if exitFlag:
         threadName.exit()
      time.sleep(delay)
      print ("%s: %s" % (threadName, time.ctime(time.time())))
      counter -= 1


def sort_substr(s):
	s = ''.join(sorted([s[j:k] for j in range(len(s)) for k in range(j+1,len(s)+1)]))
	return(s)
s = list(map(str,input().split()))[0]
t = list(map(int,input().split()))[0]
g = 0
s = sort_substr(s)
for _ in range(t):
	a,b = list(map(int,input().split()))
	k = ((a*g)%b)+1
	g += ord(s[k-1])
	print(s[k-1])
sys.exit(0)