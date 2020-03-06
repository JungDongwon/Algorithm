#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int water[51][51];
int go[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main() {
	freopen("a.txt","r",stdin);
	int r,c;
	cin >> r >> c;
	vector<string> a(r);
	for(int i=0;i<r;i++){
		cin >> a[i];	
	}
	memset(water,-1,sizeof(water));
	memset(go,-1,sizeof(go));
	queue<pair<int,int>> q;
	int sx,sy,ex,ey;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]=='*'){
				q.push(make_pair(i,j));	
				water[i][j]=0;
			}
			else if(a[i][j]=='S'){
				sx = i;
				sy = j;
			}
			else if(a[i][j]=='D'){
				ex = i;
				ey = j;
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx<0 || nx>=r || ny<0 || ny>=c ) continue;
			if(water[nx][ny]!=-1) continue;
			if( a[nx][ny]=='X' || a[nx][ny]=='D' ) continue;
			water[nx][ny] = water[x][y] + 1;
			q.push(make_pair(nx,ny));	
		}
	}
	q.push(make_pair(sx,sy));
	go[sx][sy]=0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx<0 || nx>=r || ny<0 || ny>=c ) continue;
			if(go[nx][ny]!=-1) continue;
			if(a[nx][ny]=='X') continue;
			if(water[nx][ny]!=-1 && go[x][y]+1>=water[nx][ny]) continue;
			go[nx][ny] = go[x][y] + 1;
			q.push(make_pair(nx,ny));
		}
	}
	if(go[ex][ey]==-1) cout << "KAKTUS" << '\n';
	else cout << go[ex][ey] << '\n';
} 
