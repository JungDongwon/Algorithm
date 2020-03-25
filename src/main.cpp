#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("a.txt","r",stdin);
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];	
	}
	int ans=0;
	for(int i=n-1;i>=0;i--){
		if(k<a[i]) continue;
		else{
			while(1){
				k-=a[i];
				ans++;
				if(k<a[i]) break;
			}
		}
	}
	cout << ans <<'\n';
}
	