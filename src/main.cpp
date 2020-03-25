#include<bits/stdc++.h>
using namespace std;
bool ss(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;	
	}
	return a.second<b.second;
}

int main() {
	freopen("a.txt","r",stdin);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	int ans=0;
	int k=0; //끝나는 시간
	sort(a.begin(),a.end(),ss);
	for(int i=0;i<n;i++){
		if(k<=a[i].first){ // sort 가 되있으므로 그냥 순서대로 보면서 가장 처음 만족하는 n이 최소가 될 수 있는 n이다.
			k=a[i].second;
			ans++;
		}
	}
	
	cout << ans << '\n';
}
	