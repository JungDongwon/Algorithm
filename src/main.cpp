#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int a[101][101];
int d[101];
int main() {
	freopen("a.txt","r",stdin);
	int n,m,sx,sy;
	cin >> n >> sx >> sy >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		a[x][y]=1;
		a[y][x]=1;
	}
	queue<int> q;
	memset(d,-1,sizeof(d));
	q.push(sx);
	d[sx]=0;
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(a[c][i]==1 && d[i]==-1){
				q.push(i);
				d[i]=d[c]+1;
			}
		}
	}
	 cout << d[sy] << '\n';
}
