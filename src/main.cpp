#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 100000
int m,n;
int d[100001];
int main() {
	freopen("a.txt","r",stdin);
	int n,k;
	cin >> n >> k;
	memset(d,-1,sizeof(d));
	queue<int> q;
	d[n]=0;
	q.push(n);
	while(!q.empty()){
		int c = q.front();
		q.pop();
		if(c-1>=0){
			if(d[c-1]==-1){
				q.push(c-1);
				d[c-1]=d[c]+1;
			}
		}
		if(c+1<=MAX){
			if(d[c+1]==-1){
				q.push(c+1);
				d[c+1]=d[c]+1;
			}
		}
		if(c*2<=MAX){
			if(d[c*2]==-1){
				q.push(c*2);
				d[c*2]=d[c]+1;
			}
		}
	}
	cout << d[k] << '\n';
} 