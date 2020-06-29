#include <bits/stdc++.h>

using namespace std;
int main() {
	freopen("a.txt","r",stdin);
	int c;
	int m,n;
	int ans=0;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];	
	}
	int s = 0, l = 0, r = 0;
	while(1){
		if(s > m) {
			s-=a[l++];
		}
		else if(r == n) break;
		else s += a[r++];
		if(s == m){
			ans++;
		}
	}
	cout << ans << '\n';
}
