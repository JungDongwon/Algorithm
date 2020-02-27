#include <iostream>
#include <cstring>
#include <tuple>
#include <deque>
using namespace std;
int a[101][101];
int d[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main() {
	freopen("a.txt","r",stdin);
	int m,n;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);	
		}
	}
	memset(d,-1,sizeof(d));
	deque<pair<int,int>> q;
	d[1][1]=0;
	q.push_back(make_pair(1,1));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m){
				if(a[nx][ny]==0 && d[nx][ny]==-1){
					q.push_front(make_pair(nx,ny));	
					d[nx][ny] = d[x][y];
				}
				if(a[nx][ny]==1 && (d[nx][ny]==-1 || d[nx][ny]>d[x][y]+1)){
					q.push_back(make_pair(nx,ny));	
					d[nx][ny] = d[x][y] + 1;
				}
			}	
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",d[i][j]);	
		}
		printf("\n");
	}
	
	cout << d[n][m] << '\n';
	
	
} 