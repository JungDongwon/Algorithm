#include<bits/stdc++.h>

using namespace std;
int n;
int t[16];
int p[16];
int d[16] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> p[i];
    }

    for(int i=1;i<=n;i++){
        // i번째 일한 경우
        if (t[i]+i <= n+1){
            d[t[i]+i] = max(d[t[i]+i], d[i]+p[i]);
        }
        // i번째 일을 한한 경우
        d[i+1] = max(d[i+1],d[i]);
    }

    cout << d[n+1];
    return 0;
}