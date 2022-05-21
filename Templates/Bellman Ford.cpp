// Bellman Ford Algorithm with k-hops restriction.

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
  vector<int> dist(n,INT_MAX);
  dist[src] = 0;
  for(int i=0;i<k+1;i++){
      vector<int> temp(dist);
      for(auto flight : flights){       // flight = [src, dst, weight]
          if(dist[flight[0]] != INT_MAX){
              temp[flight[1]] = min(temp[flight[1]],dist[flight[0]]+flight[2]);
          }
      }
      dist = temp;
  }
  return dist[dst] == INT_MAX ? -1 : dist[dst];
}
