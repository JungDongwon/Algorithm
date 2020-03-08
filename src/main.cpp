#include <iostream>
#include <queue>
using namespace std;
int dist[100001];
bool check[100001];
int cnt[100001];
int main() {
	freopen("a.txt","r",stdin);
	int n,k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dist[n]=0;
	check[n]=true;
	cnt[n]=1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int next : {now-1, now+1, now*2}){
			if(next>=0 && next<=100000){
				if(!check[next]){
					q.push(next);
					dist[next] = dist[now]+1;
					check[next] = true;
					cnt[next]=cnt[now];
				}
				else if(dist[next]==dist[now]+1){
					cnt[next]+=cnt[now];		
				}
			}
		}
	}
	cout << dist[k] << '\n' << cnt[k] << '\n';
} 