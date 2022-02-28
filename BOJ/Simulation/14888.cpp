#include<bits/stdc++.h>

using namespace std;
int n;
int arr[12];
int op[4];
long long maxanswer = -1000000001, minanswer = 1000000001;

void calc_max(long long number, int idx, int plus, int minus, int multiply, int divide){
    if (idx == n){
        maxanswer = max(number, maxanswer);
        return;
    }
    
    if (plus > 0){
        calc_max(number+arr[idx],idx+1,plus-1,minus,multiply,divide);
    }
    if(minus > 0){
        calc_max(number-arr[idx],idx+1,plus,minus-1,multiply,divide);
    }
    if(multiply > 0){
        calc_max(number*arr[idx],idx+1,plus,minus,multiply-1,divide);
    }
    if(divide > 0){
        calc_max(number/arr[idx],idx+1,plus,minus,multiply,divide-1);
    }
}

void calc_min(long long number, int idx, int plus, int minus, int multiply, int divide){
    if (idx == n){
        minanswer = min(number, minanswer);
        return;
    }

    if (plus > 0){
        calc_min(number+arr[idx],idx+1,plus-1,minus,multiply,divide);
    }
    if(minus > 0){
        calc_min(number-arr[idx],idx+1,plus,minus-1,multiply,divide);
    }
    if(multiply > 0){
        calc_min(number*arr[idx],idx+1,plus,minus,multiply-1,divide);
    }
    if(divide > 0){
        calc_min(number/arr[idx],idx+1,plus,minus,multiply,divide-1);
    }
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
        cin >> arr[i];
    }
    for(int i=0;i<4;i++){
        cin >> op[i];
    }
    
    calc_max(arr[0],1,op[0],op[1],op[2],op[3]);
    calc_min(arr[0],1,op[0],op[1],op[2],op[3]);

    cout << maxanswer << '\n' << minanswer;
    return 0;
}