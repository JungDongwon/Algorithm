#include<bits/stdc++.h>

using namespace std;
int r,c,t;
int arr[51][51];
int c_clockx[] = {0, -1, 0, 1};
int c_clocky[] = {1, 0, -1, 0};
int clockx[] = {0, 1, 0, -1};
int clocky[] = {1, 0, -1, 0};
int inrange(int x, int y){return (x>=0 && x<r && y>=0 && y<c);}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> r >> c >> t;
    vector<int> cleaner; // 공기 청정기의 행
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
            if (arr[i][j] == -1) cleaner.push_back(i);
        }
    }
    while(t--){
        // 미세먼지 확산
        int temp[51][51]={0};
        int left[51][51]={0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int cur = arr[i][j];
                for(int k=0;k<4;k++){
                    int nx = i + clockx[k];
                    int ny = j + clocky[k];
                    if(arr[nx][ny]!=-1 && inrange(nx,ny)){
                        temp[nx][ny] += int(cur/5);
                        left[i][j] += int(cur/5);
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j] += temp[i][j];
                arr[i][j] -= left[i][j];
            }
        }
        /*
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        // 공기 청정기 작동
        int x = cleaner[0];
        int y = 1;
        int nx=x,ny=y;
        int spread[51][51]={0};
        for(int k=0;k<4;k++){
            while(true){
                nx = x + c_clockx[k];
                ny = y + c_clocky[k];
                if (!inrange(nx,ny)) break;
                if (arr[nx][ny]==-1){
                    arr[x][y] = 0;
                    break;
                }
                spread[nx][ny] = arr[x][y];
                arr[x][y] = 0;
                x = nx;
                y = ny;
            }
            
        }
        x = cleaner[1];
        y= 1;
        nx=x;
        ny=y;
        for(int k=0;k<4;k++){
            while(true){
                nx = x + clockx[k];
                ny = y + clocky[k];
                if (!inrange(nx,ny)) break;
                if (arr[nx][ny]==-1){
                    arr[x][y] = 0;
                    break;
                }
                spread[nx][ny] = arr[x][y];
                arr[x][y] = 0;
                x = nx;
                y = ny;
            }
            
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (spread[i][j] != 0){
                    arr[i][j] = spread[i][j];
                }
            }
        }
        /*
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
    }
    int answer = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (arr[i][j]!=-1) answer += arr[i][j];
        }
    }
    cout << answer;
    
    return 0;
}