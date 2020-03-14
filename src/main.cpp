#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int bfs(vector<vector<int>> a, int i, int j){
	queue<pair<int,int>> q;
	vector<vector<bool>> d(n,vector<bool>(m,false));
	q.push(make_pair(i,j));
	d[i][j]=true;
	int count=1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int l=0;l<4;l++){
			int nx = x + dx[l];
			int ny = y + dy[l];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(d[nx][ny]==false && a[nx][ny]!=0){
					q.push(make_pair(nx,ny));
					d[nx][ny] = true;
					count++;
				}
			}
		}
	}
	return count;
}
bool seperated(vector<vector<int>> a){
	int cnt=0,sx,sy;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=0){
				cnt++;	
				if(cnt==1){
					sx=i; 
					sy=j;
				}
			}
		}
	}
	int cur = bfs(a,sx,sy);
	if(cnt==cur) return false;
	else return true;
}
vector<vector<int>> simul(vector<vector<int>> a){
	int count=0;
	vector<vector<int>> b = a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=0){
				count=0;
				for(int k=0;k<4;k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx>=0 && nx<n && ny>=0 && ny<m){
						if(a[nx][ny]==0) count++;	
					}
				}
				if(a[i][j]>=count) b[i][j]-=count;
				else b[i][j]=0;
			}
		}
	}
	return b;
}
bool allmelt(vector<vector<int>> a){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=0) return false;	
		}
	}
	return true;
}
int main() {
	freopen("a.txt","r",stdin);
	cin >> n >> m;
	static vector<vector<int>> a(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];	
		}
	}
	int year=0;
	while(true){
		if(allmelt(a)){
			cout << 0 << '\n';
			return 0;
		}
		if(seperated(a)) break;
		a = simul(a);	
		year++;	
	}
	cout << year << '\n';
	return 0;
}
