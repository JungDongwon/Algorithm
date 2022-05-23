vector<int> TopologicalSort(int N, vector<vector<int>>& P) {
  vector<vector<int>> dependency(N);                   // Adjacency List of Dependency
  vector<int> ans, indegree(N);               // indegree[i] denotes number of prerequisites for ith node
  for(auto& pre : P) 
      dependency[pre[1]].push_back(pre[0]),            // forming adjacency list graph
      indegree[pre[0]]++;                     

  queue<int> q;
  for(int i = 0; i < N; i++)
      if(indegree[i] == 0) q.push(i);         // we can start with courses having no prequisites

  while(size(q)) {
      auto cur = q.front(); q.pop();
      ans.push_back(cur);                     // cur has no remaining prerequisites, so we can take it now
      for(auto next : dependency[cur]) 
          if(--indegree[next] == 0)     // if there's a next node having 0 prequisite remaining,
              q.push(next);             // then we can take it
  }
  if(size(ans) == N) return ans;              // ordering exists where all courses can be finished
  return {};                                      
}

// reference: LeetCode
