#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
	freopen("a.txt","r",stdin);
	int n,i;
	int a[3];
	int prevd[3], curd[3];
	int prevd1[3], curd1[3];
	cin >> n;
	cin >> prevd[0] >> prevd[1] >> prevd[2];
	prevd1[0]=prevd[0];
	prevd1[1]=prevd[1];
	prevd1[2]=prevd[2];
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> a[j];
			if(j==0){
				curd[j] = max(prevd[0],prevd[1]) + a[j];	
				curd1[j] = min(prevd1[0],prevd1[1]) + a[j];	
			}
			else if(j==2){
				curd[j] = max(prevd[1],prevd[2]) + a[j];	
				curd1[j] = min(prevd1[1],prevd1[2]) + a[j];	
			}
			else{
				curd[j] = max(prevd[2],max(prevd[0],prevd[1])) + a[j];	
				curd1[j] = min(prevd1[2],min(prevd1[0],prevd1[1])) + a[j];	
			}
		}
		for(int j=0;j<3;j++){
			prevd[j] = curd[j];
			prevd1[j] = curd1[j];
		}
	}
	printf("%d %d\n",max(prevd[0],max(prevd[1],prevd[2])), min(prevd1[0],min(prevd1[1],prevd1[2])));
}
