#include <iostream>
#define MAX 1000000
using namespace std;
int n,m;
int broken[10] = {false};
int possible(int c){
	if(c==0){
		if(broken[0]) return 0;
		else return 1;
	}
	int len=0;
	while(c>0){
		int t = c%10;
		if(broken[t]) return 0;	
		len++;
		c/=10;
	}
	return len;
}
int main() {
	freopen("a.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int t;
		cin >> t;
		broken[t]=true;
	}
	int ans=abs(n-100);
	for(int i=0;i<=MAX;i++){
		int c = i;
		int r = possible(c);
		if(r==0) continue;
		ans = min(r+abs(n-c),ans);
	}
	cout << ans <<'\n';
}