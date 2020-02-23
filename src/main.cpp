#include <iostream>
using namespace std;
int a[1001];
int d[1001]; // d[i] : i로 끝나는 수열 중 가장 긴 것
int main() {
	freopen("a.txt","r",stdin);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];	
	}
	
	for(int i=1;i<=n;i++){
		d[i]=1;
		for(int j=1;j<=i;j++){
			if( a[j]<a[i] && d[i] < d[j] + 1 ){
				d[i] = d[j] + 1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans = max(ans,d[i]);	
	}
	cout << ans << '\n';
} 