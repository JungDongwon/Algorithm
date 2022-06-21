def pair_with_targetsum(arr, target_sum):
  
  # left포인터, right포인터 초기화
  left, right = 0, len(arr) - 1
  
  # left < right일 때,
  while(left < right):
    current_sum = arr[left] + arr[right]
    
    # 완료 조건
    if current_sum == target_sum:
      return [left, right]
    
    # 상황에 따라 포인터 이동
    if target_sum > current_sum:
      left += 1  
    else:
      right -= 1 
      
  return [-1, -1]
