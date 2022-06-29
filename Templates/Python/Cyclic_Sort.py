# Problem: https://www.educative.io/courses/grokking-the-coding-interview/B8qXVqVwDKY

# Solution:

def cyclic_sort(nums):
  i = 0
  while i < len(nums):
    j = nums[i] - 1
    if nums[i] != nums[j]:
      nums[i], nums[j] = nums[j], nums[i]
    else:
      i += 1
  return nums
