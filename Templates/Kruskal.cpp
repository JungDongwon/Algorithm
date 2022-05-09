vector<int> root;
vector<int> rank;

int find(int x){
    if (root[x] == -1){
        return x;
    }
    return root[x] = find(root[x]);
}

bool _union(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            rank[rootX] += 1;
        }
        return true;
    }
    return false;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    root = vector<int> (n,-1);
    rank = vector<int> (n,1);
    vector<pair<int,pair<int,int>>> allEdges;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            allEdges.push_back({weight,{i,j}});
        }
    }
  
    sort(allEdges.begin(), allEdges.end());
  
    int min_cost = 0;
    int usedEdges = 0;
    for(int i=0;i<allEdges.size() && usedEdges<n-1;i++){
        int n1 = allEdges[i].second.first;
        int n2 = allEdges[i].second.second;
        int weight = allEdges[i].first;
        if (_union(n1,n2)){
            min_cost += weight;
            usedEdges++;
        }
    }
    return min_cost;
}
