#include <iostream>
#include <vector>
using namespace std;
long long a[200001];
long long b[200001];// long long 주의
int main() {
	freopen("a.txt","r",stdin);
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		a[i]=t;
		b[t]+=1;
	}
	long long total=0;
	for(int i=1;i<=n;i++){
		total+=b[i]*(b[i]-1)/2;		
	}
	
	for(int i=0;i<n;i++){
		cout << total-(b[a[i]]-1) << '\n';	
	}
}