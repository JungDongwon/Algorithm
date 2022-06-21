def solve_knapsack(profits, weights, capacity):
  # dp  배열 -1로 초기화
  dp = [[-1 for x in range(capacity+1)] for y in range(len(profits))]
  
  return knapsack_recursive(dp, profits, weights, capacity, 0)


def knapsack_recursive(dp, profits, weights, capacity, currentIndex):

  # 종료 조건/완료 조건
  if capacity <= 0 or currentIndex >= len(profits):
    return 0
  
  if dp[currentIndex][capacity] == -1:
    # 해당 아이템을 선택하는 경우
    profit1 = 0
    if weights[currentIndex] <= capacity:
      profit1 = profits[currentIndex] + knapsack_recursive(
        dp, profits, weights, capacity - weights[currentIndex], currentIndex + 1)
    
    # 해당 아이템을 선택하지 않는 경우
    profit2 = knapsack_recursive(
      dp, profits, weights, capacity, currentIndex + 1)
    
    # 두 경우를 합함
    dp[currentIndex][capacity] = max(profit1, profit2)
    
  return dp[currentIndex][capacity]
