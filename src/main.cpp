#include <iostream>
#include <cstring>
using namespace std;
int a[101][101];
int d[101][101];
int c[101];
int n;
void dfs(int x){
	for(int i=0;i<n;i++){
		if(a[x][i]==1 && c[i]==0){
			c[i]=1;
			dfs(i);
		}
	}
}
int main() {
	freopen("a.txt","r",stdin);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];	
		}
	}
	for(int i=0;i<n;i++){
		memset(c,0,sizeof(c));
		dfs(i);
		for(int j=0;j<n;j++){
			if(c[j]==1) d[i][j]=1;	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << d[i][j] << " ";	
		}
		cout << '\n';
	}
}
