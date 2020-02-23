#include <iostream>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int main(){
	freopen("a.txt","r",stdin);
	int i,j,n,m,t;
	cin >> n >> m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%1d",&t);
			a[i][j]=t;
			if ( i==1 || j==1 ) d[i][j]=t;
		}
	}	
	for(i=2;i<=n;i++){
		for(j=2;j<=m;j++){
			if(a[i][j]==0) continue;
			d[i][j] = min(d[i-1][j-1],min(d[i-1][j],d[i][j-1])) + 1;
		}
	}
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			ans = max(ans,d[i][j]);
		}
	}
	cout << ans*ans << '\n';
} 

	
