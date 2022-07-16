# Problem: https://www.educative.io/courses/grokking-the-coding-interview/JYB20zgR32o

# Solution: 

from heapq import *
from collections import deque

def schedule_tasks(tasks, k):
  n = len(tasks)
  freq = {}
  for task in tasks:
    if task not in freq:
      freq[task] = 0
    freq[task] += 1
  max_heap = []
  for task,f in freq.items():
    heappush(max_heap,(-f,task))
  intervalCount = 0
  queue = deque()
  while n > 0:
    if max_heap:
      f,task = heappop(max_heap)
      n -= 1
      queue.append((f+1,task))
    else:
      queue.append((0,0))
    if len(queue) == k+1:
      f,task = queue.popleft()
      if -f > 0:
        heappush(max_heap,(f,task))
    intervalCount += 1

  return intervalCount


def main():
  print("Minimum intervals needed to execute all tasks: " +
        str(schedule_tasks(['a', 'a', 'a', 'b', 'c', 'c'], 2)))
  print("Minimum intervals needed to execute all tasks: " +
        str(schedule_tasks(['a', 'b', 'a'], 3)))


main()

