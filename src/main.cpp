#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int a[51][51];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int bfs(int i, int j){
	queue<pair<int,int>> q;
	vector<vector<bool>> d(n,vector<bool>(m,false));
	vector<vector<int>> cnt(n,vector<int>(m,-1));
	q.push(make_pair(i,j));
	d[i][j]=true;
	cnt[i][j]=0;
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
					cnt[nx][ny] = cnt[x][y]+1;
				}
			}
		}
	}
	int cur=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
				cur = max(cur,cnt[i][j]);
		}
	}
	return cur;
}
int main() {
	freopen("a.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			if(s[j]=='W') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1){
				int cur = bfs(i,j);
				ans = max(cur,ans);
			}
		}
	}	
	cout << ans << '\n';
}