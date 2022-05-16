vector<pair<int, int>> adj[101];
   
void dijkstra(vector<int>& signalReceivedAt, int source, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
    greater<pair<int, int>>> pq;
    pq.push({0, source});

    // Time for starting node is 0
    signalReceivedAt[source] = 0;

    while (!pq.empty()) {
        int currNodeTime = pq.top().first;
        int currNode = pq.top().second; 
        pq.pop();
         
        if (currNodeTime > signalReceivedAt[currNode]) {
            continue;
        }

        // Broadcast the signal to adjacent nodes
        for (pair<int, int> edge : adj[currNode]) {
            int time = edge.first;
            int neighborNode = edge.second;

            // Fastest signal time for neighborNode so far
            // signalReceivedAt[currNode] + time : 
            // time when signal reaches neighborNode
            if (signalReceivedAt[neighborNode] > currNodeTime + time) {
                signalReceivedAt[neighborNode] = currNodeTime + time;
                pq.push({signalReceivedAt[neighborNode], neighborNode});
            }
        }
    }
}
// Reference: Leetcode
