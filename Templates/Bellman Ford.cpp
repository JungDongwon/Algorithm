// Bellman Ford Algorithm with k-hops restriction.

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
  if (src == dst) return 0;
        
  vector<int> previous(n,INT_MAX);
  vector<int> current(n,INT_MAX);
  previous[src] = 0;
  
  for(int i=0;i<k+1;i++){
      for(auto flight : flights){
          int previous_node = flight[0];
          int current_node = flight[1];
          int cost = flight[2];

          if(previous[previous_node] != INT_MAX){
              current[current_node] = min(current[current_node],previous[previous_node]+cost);
          }
      }
      previous = current;
  }
  return current[dst] == INT_MAX ? -1 : current[dst];
}
