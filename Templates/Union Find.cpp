
// Implementation of Disjoint Set using Union-Find data structure optimized with both “path compression” and “union by rank”.
// Time Complexity 
// *  Constructor: O(N) 
// *  Find(): O(a(N)) ~ O(1)
// *  Union(): O(a(N)) ~ O(1)
// *  Connectivity:  O(a(N)) ~ O(1)
// Space Complexity: O(N)

class UnionFind {
private:
  vector<int> root;
  vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y) {
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
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// reference: Leetcode
