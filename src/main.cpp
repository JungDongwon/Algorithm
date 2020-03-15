#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int a[101][101][101];
int d[101][101][101];
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
int cntwall=0;
int main() {
	freopen("a.txt","r",stdin);
	int m,n,h;
	cin >> m >> n >> h;
	queue<tuple<int,int,int>> q;
	memset(d,-1,sizeof(d));
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int t;
				cin >> t;
				a[j][k][i]=t;
				if(t==1){
					q.push(make_tuple(j,k,i));
					d[j][k][i]=0;
				}
				if(t==-1) cntwall++;
			}
		}
	}
	while(!q.empty()){
		int x,y,z;
		tie(x,y,z)=q.front();
		q.pop();
		for(int k=0;k<6;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + dz[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m && nz>=0 && nz<h){
				if(a[nx][ny][nz]==0 && d[nx][ny][nz]==-1){
					q.push(make_tuple(nx,ny,nz));
					d[nx][ny][nz]=d[x][y][z]+1;
				}
			}
		}
	}
	int ans=0,curwall=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				ans=max(d[j][k][i],ans);	
				if(d[j][k][i]==-1) curwall++;
			}
		}
	}
	if(cntwall==curwall) cout << ans << '\n';
	else cout << -1 << '\n';
	
}
