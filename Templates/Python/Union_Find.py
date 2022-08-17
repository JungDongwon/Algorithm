class UnionFind:
    def __init__(self,size):
        self.root = [-1]*size
        self.rank = [1]*size
        
    def find(self,x):
        if self.root[x] == -1:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x] 
    
    def union(self,x,y):
        rootX = self.find(x);
        rootY = self.find(y);
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX;
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY;
            else:
                self.root[rootY] = rootX;
                self.rank[rootX] += 1;
                
    def IsConnected(self,x, y):
        return self.find(x) == self.find(y)
            
