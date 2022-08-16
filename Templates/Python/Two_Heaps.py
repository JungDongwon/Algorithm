// Problem: Calculate the median of a number stream
  
// Solution: 

from heapq import *

class MedianOfAStream:
  minHeap = []
  maxHeap = []
  def insert_num(self, num):
    if not self.maxHeap or -self.maxHeap[0] >= num:
      heappush(self.maxHeap,-num)
    else:
      heappush(self.minHeap,num)
    if len(self.maxHeap) > len(self.minHeap) + 1:
      heappush(self.minHeap,-heappop(self.maxHeap))
    elif len(self.maxHeap) < len(self.minHeap):
      heappush(self.maxHeap,-heappop(self.minHeap))

  def find_median(self):
    if len(self.maxHeap) == len(self.minHeap):
      return (self.minHeap[0] - self.maxHeap[0]) / 2.0
    return -self.maxHeap[0] / 1.0
