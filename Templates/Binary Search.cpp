int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1; // Consideration 1 : left, right 범위
  
  while(left < right){
    int mid = left + (right - left) / 2;
    
    if (condition(mid)) { right = mid; } // Consideration 3 : condition이 무엇인가?
    else { left = mid + 1}
  }

  return left; // Consideration 2 : 문제에서 원하는 정답이 무엇인가? (ex. left, left-1)
}

// * Solutions for Considerations... 
// Consideration 1 : Set up the boundary to include all possible elements
// Consideration 2 : After exiting the while loop, left is the minimal k satisfying the condition function
// Consideration 3 : Experiences
