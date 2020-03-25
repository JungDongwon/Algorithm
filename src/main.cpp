#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("a.txt","r",stdin);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> s(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+a[i];
		s[i]=sum;
	}
	sum=0;
	for(int i=0;i<n;i++){
		sum+=s[i];	
		printf("%d",s[i]);
	}
	cout << sum << '\n';
}
	