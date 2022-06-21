int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<bool> contains(n);

    int min_cost = 0;
    int usedEdges = 0;
    minheap.push({0,0});
    while(usedEdges < n){
        int weight,cur_node;
        tie(weight,cur_node) = minheap.top();
        minheap.pop();

        if (contains[cur_node]) continue;

        contains[cur_node] = true;
        min_cost += weight;
        usedEdges++;

        for(int next_node=0;next_node<n;next_node++){
            if(!contains[next_node]){
                int next_weight = abs(points[cur_node][0] - points[next_node][0]) + abs(points[cur_node][1] - points[next_node][1]);
                minheap.push({next_weight,next_node});
            }
        }
    }
    return min_cost;

}
