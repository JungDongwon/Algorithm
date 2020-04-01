#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("a.txt","r",stdin);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	//1 1 2 3 6 7 30
	int sum=0;
	for(int i=0;i<n;i++){
		if(sum+2<=a[i]) break;
		sum+=a[i];
	}
	cout << sum+1 <<'\n';
	return 0;
}
	