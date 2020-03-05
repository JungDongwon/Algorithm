#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int a[1001][1001];
int d[1001][1001][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main() {
	freopen("a.txt","r",stdin);
	int m,n;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);	
		}
	}
	queue<tuple<int,int,int>> q;
	d[1][1][0] = 1;
	q.push(make_tuple(1,1,0));
	while(!q.empty()){
		int x,y,z;
		tie(x,y,z) = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m){
				if(a[nx][ny]==0 && d[nx][ny][z]==0){
					d[nx][ny][z] = d[x][y][z]+1;
					q.push(make_tuple(nx,ny,z));
				}
				if(z==0 && a[nx][ny]==1 && d[nx][ny][z+1]==0){
					d[nx][ny][z+1] = d[x][y][z]+1;
					q.push(make_tuple(nx,ny,z+1));
				}
				
			}	
		}
	}
	if (d[n][m][0] != 0 && d[n][m][1] != 0) {
        cout << min(d[n][m][0], d[n][m][1]);
    } else if (d[n][m][0] != 0) {
        cout << d[n][m][0];
    } else if (d[n][m][1] != 0) {
        cout << d[n][m][1];
    } else {
        cout << -1;
    }
    cout << '\n';
} 