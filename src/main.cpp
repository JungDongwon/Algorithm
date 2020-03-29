#include <iostream>
#include <string>
using namespace std;
int main() {
	freopen("a.txt","r",stdin);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int i,sum=0;
		for(i=1;i<n;i++){
			sum+=i;
			if(sum>=k) break;
		}
		int b1 = i;
		int b2 = i-(sum-k+1);
		string s(n,'a');
		s[n-b1-1]='b';
		s[n-b2-1]='b';
		cout << s << '\n';
	}
}
	