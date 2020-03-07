#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
	freopen("a.txt","r",stdin);
	int start=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int tmp;
			cin >> tmp;
			if(tmp==0) tmp=9;
			start = start*10 + tmp;
		}
	}
	queue<int> q;
	map<int,int> d; // dist를 기록하는 저장소가 배열이 아니라 맵
	
	d[start]=0;
	q.push(start);
	while(!q.empty()){
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();
		int z = now.find('9');
		int x = z/3;
		int y = z%3;
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<3 && ny>=0 && ny<3){
				string next = now;
				swap(next[x*3+y],next[nx*3+ny]);
				int num = stoi(next);
				if(d.count(num)==0){
					d[num] = d[now_num] + 1;
					q.push(num);
				}
			}
		}
	}
	if(d.count(123456789)==0) cout << -1 << '\n';
	else cout << d[123456789] <<'\n';
} 