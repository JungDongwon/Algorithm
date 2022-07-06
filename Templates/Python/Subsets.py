# Problem: Find Subsets
# https://www.educative.io/courses/grokking-the-coding-interview/gx2OqlvEnWG

# Solution:

def find_subsets(nums):
  subsets = []
  subsets.append([])
  for num in nums:
    n = len(subsets)
    for i in range(n):
      set1 = list(subsets[i])
      set1.append(num)
      subsets.append(set1)

  return subsets

# Problem: Find Permutation
# https://www.educative.io/courses/grokking-the-coding-interview/B8R83jyN3KY

# Solution:

from collections import deque

def find_permutations(nums):
  permutations = deque()
  permutations.append([])
  for num in nums:
    n = len(permutations)
    for i in range(n):
      before = permutations.popleft()
      for j in range(len(before)+1):
        new = list(before)
        new.insert(j,num)
        permutations.append(new)

  return list(permutations)
