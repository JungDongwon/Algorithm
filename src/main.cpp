#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 100000
int m,n;
int d[100001];
int from[100001];

void print(int n, int m){
	if(n!=m){
		print(n,from[m]);	
	}
	cout << m << " ";
}

int main() {
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
				from[c-1]=c;
				d[c-1]=d[c]+1;
			}
		}
		if(c+1<=MAX){
			if(d[c+1]==-1){
				q.push(c+1);
				from[c+1]=c;
				d[c+1]=d[c]+1;
			}
		}
		if(c*2<=MAX){
			if(d[c*2]==-1){
				q.push(c*2);
				from[c*2]=c;
				d[c*2]=d[c]+1;
			}
		}
	}
	cout << d[k] << '\n';
	print(n,k);
	cout << '\n';
	
} 