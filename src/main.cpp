#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
char a[12][6];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int ans=0;
bool explode(int i, int j){
	queue<pair<int,int>> q;
	vector<vector<bool>> d(12,vector<bool>(6));
	int cnt=0;
	q.push(make_pair(i,j));
	d[i][j]=true; cnt++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0 && nx<12 && ny>=0 && ny<6){
				if(a[nx][ny]==a[x][y] && d[nx][ny]==false){
					q.push(make_pair(nx,ny));
					d[nx][ny]=true;
					cnt++;
				}
			}
		}
	}
	if(cnt>=4){
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(d[i][j]==true) a[i][j]='.';	
			}
		}
		return true;
	}
	return false;
}
void simul(){
	for(int j=0;j<6;j++){
		string s = "";
		for(int i=11;i>=0;i--){
			if(a[i][j]=='.') continue;
			s+=a[i][j];
			a[i][j]='.';
		}
		for(int i=0;i<s.size();i++){
			a[11-i][j] = s[i];
		}
	}
}
int main() {
	freopen("a.txt","r",stdin);
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin >> a[i][j];
		}
	}
	while(true){
		bool cur = false;
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(a[i][j]!='.') {
					if(explode(i,j)){
						cur=true;
					}
				}
			}
		}
		if(cur) ans++;
		else{
			cout << ans << '\n';
			return 0;
		}
		simul();		
	/*	for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				cout << a[i][j];
			}
			cout << '\n';
		}
		cout << '\n';*/
	}
}