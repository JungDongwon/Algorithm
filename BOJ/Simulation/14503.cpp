#include<bits/stdc++.h>

using namespace std;
int n, m;
int arr[51][51] = {0};
int dx[] = {-1, 0, 1, 0}; // 북동남서
int dy[] = {0, 1, 0, -1};
bool inrange(int x, int y) { return 0 <= y && y < m && 0 <= x && x < n; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 

    cin >> n >> m;
    int r,c,d;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    int answer = 0;
    int flag = 1;
    while(1){
        // 현재 위치 청소
        if (flag == 1){
            arr[r][c] = 2; // 2: 청소한 위치
            answer++;
            flag = 0;
        }
        int cnt = 0;
        for(int k=0;k<4;k++){
            int nd = (d+3) % 4;
            int nx = r + dx[nd];
            int ny = c + dy[nd];
            if (inrange(nx,ny) && arr[nx][ny] == 0) {
                r = nx;
                c = ny;
                d = nd;
                flag = 1;
                break;
            }
            else{
                d = nd;
                cnt++;
            }
        }
        if (cnt == 4) { // 네 방향 모두 X
            int nd = (d+2) % 4;
            int nx = r + dx[nd];
            int ny = c + dy[nd];
            if (!inrange(nx,ny)) break;
            if (arr[nx][ny] == 1) break;
            r = nx;
            c = ny;
        }
        
    }

    cout << answer;
    return 0;
}