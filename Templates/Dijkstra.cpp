vector<pair<int, int>> adj[101];
   
void dijkstra(vector<int>& signalReceivedAt, int source, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
// weight가 모두 같으면 BFS와 동일함. 
// weight가 다르면, 
// Dijkstra will visit through the shortest path and will not visit the same node twice (More Efficient)
// BFS uses the normal queue, so all the path of the graph are visited to get the minimum distance.

// How to transform BFS to Dijkstra
// 1. Use priority queue instead of a normal queue.
// 2. Don't keep track on visited nodes, and instead track distance(weights) from the starting node.
