#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1000001];
int b,c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> b >> c;
    long long answer = n;

    for(int i=0;i<n;i++){
        if ((arr[i]-b) > 0){
            answer += (arr[i]-b)/c;
            if (((arr[i]-b)%c) != 0) answer += 1;
        }
    }

    cout << answer;
    return 0;
}