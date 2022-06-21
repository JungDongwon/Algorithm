def smallest_subarray_sum(s, arr):
  
  # window_start 와 변수들 초기화
  min_length = math.inf
  window_sum = 0
  window_start = 0
  
  # window_end 를 한 칸씩 옮김
  for window_end in range(0, len(arr)):
      window_sum += arr[window_end]
      
      # 조건에 맞을 때까지 window_start 를 옮기고 업데이트
      while window_sum >= s:
        min_length = min(min_length, window_end - window_start + 1)
        window_sum -= arr[window_start]
        window_start += 1
        
  # 답이 없는 경우
  if min_length == math.inf:
    return 0
  
  return min_length
