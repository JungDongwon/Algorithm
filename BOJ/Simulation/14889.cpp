#include<bits/stdc++.h>

using namespace std;
int n;
int arr[21][21];

int calculate(vector<int> &a){
    int start = 0;
    int link = 0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if (i == j) continue;
            if(a[i]==1 && a[j]==1){ // 스타트
                start += (arr[i][j] + arr[j][i]);
            }
            else if(a[i]==0 && a[j]==0){ // 링크
                link += (arr[i][j] + arr[j][i]);
            }
        }
    }
    if (start > link) return start-link;
    else return link-start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int answer = 987654321;
    vector<int> a(n,0);
    for (int i=0; i<n/2; i++) {
        a[i] = 1;
    }
    sort(a.begin(), a.end());
    do {
        //for(int i=0;i<a.size();i++){
        //    cout << a[i] << " ";
        //}
        int temp = calculate(a);
        //cout << temp << endl;
        answer = min(answer,temp);
        
    } while(next_permutation(a.begin(), a.end()));

    cout << answer;
    return 0;
}