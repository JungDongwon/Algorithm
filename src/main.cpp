#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main() {
	freopen("a.txt","r",stdin);
	int n,m;
	cin >> m >> n;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<pair<int,int>> c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='C'){
				c.push_back(make_pair(i,j));
			}
		}
	}
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int,int>> q;
	q.push(make_pair(c[0].first,c[0].second));
	dist[c[0].first][c[0].second] = 0;
	while(!q.empty()){
		int x,y;
		tie(x,y) = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			while(1){
				if(nx<0 || nx>=n || ny<0 || ny>=m) break; // if( __ && __ ){ ~~} -> 이런식으로 짜면 while문 무한루프됨
				if(a[nx][ny]=='*') break; 
				if(dist[nx][ny]==-1){
					q.push(make_pair(nx,ny));
					dist[nx][ny] = dist[x][y] + 1;
				}	
				nx += dx[k];
				ny += dy[k];
		/*		if(dist[nx][ny]!=-1 || a[nx][ny]=='*') break; // 처음에 이렇게 짜서 틀림. dist에서 이미 지나간 곳을 교차해서 지나가는 경우를 간과한 코드. dist[][]가 -1이 아니어도 다음 인덱스는 -1일 수도 있으므로 break를 하면 안되고 nx,ny를 갱신해야함
				q.push(make_pair(nx,ny));
				dist[nx][ny] = dist[x][y] + 1;
				nx += dx[k];
				ny += dy[k];*/
			}
		}
	}
	cout << dist[c[1].first][c[1].second]-1 << '\n';
} 
