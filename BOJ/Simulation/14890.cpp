#include<bits/stdc++.h>

using namespace std;
int n, l;
int arr[101][101];
int dx[] = {0, 1, 0, -1}; // 0:동, 1:남, 2:서, 3:북
int dy[] = {1, 0, -1, 0};

bool check(vector<int> a){
    vector<int> used(n,0);
    for(int i=0;i<n-1;i++){
        if (a[i] == a[i+1]) continue;
        else if (a[i]-a[i+1] == 1){
            if (i+1+l > n) return false;
            for(int j=0;j<l;j++){
                if (a[i+1+j] != a[i+1] || used[i+1+j] == 1) return false;
                used[i+1+j] = 1;

            }
        }
        else if(a[i+1]-a[i] == 1){
            if (i+1-l < 0) return false;
            for(int j=0;j<l;j++){
                if (a[i-j] != a[i] || used[i-j] == 1) return false;
                used[i-j] = 1;
            }
        }
        else return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    // 행 검사
    for(int i=0;i<n;i++){
        vector<int> row(n);
        for(int j=0;j<n;j++){
            row[j] = arr[i][j];
        }
        if(check(row)) {
            //cout << i;
            answer++;
        }
    }
    // 열 검사
    for(int i=0;i<n;i++){
        vector<int> col(n);
        for(int j=0;j<n;j++){
            col[j] = arr[j][i];
        }
        if(check(col)){
            //cout << i;
            answer++;
        } 
    }
    cout << answer;

    return 0;
}