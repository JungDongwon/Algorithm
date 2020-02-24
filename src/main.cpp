#include <iostream>
#include <queue>
using namespace std;
int m,n;
int a[1001][1001];
int d[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
queue<pair<int,int>> q;
int cnt=0;
int main() {
	freopen("a.txt","r",stdin);
	cin >> m >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int t;
			cin >> t;
			a[i][j] = t;
			if(t==0) cnt++;
			if(t==1){
				q.push(make_pair(i,j));
				d[i][j]=1;	
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(d[nx][ny]==0 && a[nx][ny]==0){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(d[i][j]==0 && a[i][j]!=-1){
				cout << "-1" << '\n';
				return 0;
			}
			ans = max(ans,d[i][j]);	
		}
	}
	cout << ans-1 << '\n';
	
} 