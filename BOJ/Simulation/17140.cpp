#include<bits/stdc++.h>

using namespace std;
int r,c,k;
#define MAX 1001
int arr[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    
    cin >> r >> c >> k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> arr[i][j];
        }   
    }
    int time = 0;
    int n=3,m=3; // 행과 열
    int next_n, next_m;
    vector<int> count(MAX,0);
    vector<pair<int,int>> sort_count;
    while(arr[r][c] != k && time <= 100){
        if(n >= m){
            next_m = -1;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=MAX;j++){
                    count[j] = 0;
                }
                vector<pair<int,int>>().swap(sort_count);
                for(int j=1;j<=m;j++){
                    count[arr[i][j]]++;
                    arr[i][j] = 0;
                }
                for(int j=1;j<=MAX;j++){
                    if (count[j]!=0) sort_count.push_back(make_pair(count[j],j));
                }
                sort(sort_count.begin(),sort_count.end());
                int c=1;
                for(int j=0;j<sort_count.size();j++){
                    int num = sort_count[j].second;
                    int cnt = sort_count[j].first;
                    arr[i][c++] = num;
                    arr[i][c++] = cnt;
                }
                if (next_m == -1 || next_m < sort_count.size()*2) next_m = sort_count.size()*2;
            }
            m = next_m;
        }
        else{
            next_n = -1;
            for(int i=1;i<=m;i++){
                for(int j=0;j<=MAX;j++){
                    count[j] = 0;
                }
                vector<pair<int,int>>().swap(sort_count);
                for(int j=1;j<=n;j++){
                    count[arr[j][i]]++;
                    arr[j][i] = 0;
                }
                for(int j=1;j<=MAX;j++){
                    if (count[j]!=0) sort_count.push_back(make_pair(count[j],j));
                }
                sort(sort_count.begin(),sort_count.end());
                int c=1;
                for(int j=0;j<sort_count.size();j++){
                    int num = sort_count[j].second;
                    int cnt = sort_count[j].first;
                    arr[c++][i] = num;
                    arr[c++][i] = cnt;
                }
                if (next_n == -1 || next_n < sort_count.size()*2) next_n = sort_count.size()*2;
            }
            n = next_n;
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << arr[i][j] << " ";
            }   
            cout << endl;
        }
        cout << endl;
        */
        time++;
    }
    
    if (time > 100) cout << "-1" ;
    else cout << time;

    return 0;
}