#include <iostream>
#include <queue>
using namespace std;
int n,m;
int a[100][100];
int d[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int main() {
	freopen("a.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	d[0][0]=1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(d[nx][ny]==0 && a[nx][ny]==1){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
	cout << d[n-1][m-1] << '\n';
	
	
} 