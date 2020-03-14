#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int a[51][51];
bool d[51][51];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	d[i][j]=true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int l=0;l<4;l++){
			int nx = x + dx[l];
			int ny = y + dy[l];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(d[nx][ny]==false && a[nx][ny]==1){
					q.push(make_pair(nx,ny));
					d[nx][ny] = true;
				}
			}
		}
	}
}
int main() {
	freopen("a.txt","r",stdin);
	int t;
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(d,false,sizeof(d));
		int k;
		cin >> n >> m >> k;
		for(int i=0;i<k;i++){
			int x,y;
			cin >> x >> y;
			a[x][y]=1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1 && d[i][j]==false){
					bfs(i,j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
} 
