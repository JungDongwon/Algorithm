#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
char a[31][31][31];
int d[31][31][31];
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main() {
	freopen("a.txt","r",stdin);
	while(1){
		int m,n,h,ax,ay,az;
		cin >> h >> n >> m;
		if(h==0 && m==0 && n==0) return 0;
		queue<tuple<int,int,int>> q;
		memset(d,-1,sizeof(d));
		for(int i=0;i<h;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<m;k++){
					char t;
					cin >> t;
					a[j][k][i]=t;
					if(t=='S'){
						q.push(make_tuple(j,k,i));
						d[j][k][i]=0;
					}
					if(t=='E'){
						ax=j;
						ay=k;
						az=i;
					}
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
					if(a[nx][ny][nz]!='#' && d[nx][ny][nz]==-1){
						q.push(make_tuple(nx,ny,nz));
						d[nx][ny][nz]=d[x][y][z]+1;
					}
				}
			}
		}
		int ans=d[ax][ay][az];
		if(ans!=-1) printf("Escaped in %d minutes(s).\n",ans);
		else printf("Trapped!\n");
	}
	
	
}