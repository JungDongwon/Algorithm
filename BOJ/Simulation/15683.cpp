#include<bits/stdc++.h>

using namespace std;
int n, m;
int o_arr[9][9];
int dx[] = {0, 1, 0, -1}; // 0:동, 1:남, 2:서, 3:북
int dy[] = {1, 0, -1, 0};
bool inrange(int x, int y) { return 0 <= y && y < m && 0 <= x && x < n; }
vector<pair<int,int>> cctv;
int answer = 100;

void sim(int arr[][9], int num_cctv){
    if (num_cctv == cctv.size()){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (arr[i][j] == 0) cnt++;
            }
        }
        if (cnt < answer) answer = cnt; 
        return;
    }
    int copy_arr[9][9];
    int x,y;
    tie(x,y) = cctv[num_cctv];
    int cctv = o_arr[x][y];
    if (cctv == 1){
        for (int i=0;i<4;i++){
            // 원래 배열 백업
            for(int l=0;l<n;l++){
                for(int j=0;j<m;j++){
                    copy_arr[l][j] = arr[l][j];
                }
            }
            int nx = x+dx[i];
            int ny = y+dy[i];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[i];
                ny = ny+dy[i];
            }
            sim(copy_arr, num_cctv+1);
        } 
    }
    else if (cctv == 2){
        for (int i=0;i<2;i++){
            // 원래 배열 백업
            for(int l=0;l<n;l++){
                for(int j=0;j<m;j++){
                    copy_arr[l][j] = arr[l][j];
                }
            }
            int nx = x+dx[i];
            int ny = y+dy[i];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[i];
                ny = ny+dy[i];
            }
            nx = x+dx[i+2];
            ny = y+dy[i+2];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[i+2];
                ny = ny+dy[i+2];
            }
            sim(copy_arr, num_cctv+1);
        } 
    }
    else if (cctv == 3){
        for (int i=0;i<4;i++){
            // 원래 배열 백업
            for(int l=0;l<n;l++){
                for(int j=0;j<m;j++){
                    copy_arr[l][j] = arr[l][j];
                }
            }
            int nx = x+dx[i];
            int ny = y+dy[i];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[i];
                ny = ny+dy[i];
            }
            nx = x+dx[(i+1)%4];
            ny = y+dy[(i+1)%4];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[(i+1)%4];
                ny = ny+dy[(i+1)%4];
            }
            sim(copy_arr, num_cctv+1);
        } 
    }
    else if (cctv == 4){
        for (int i=0;i<4;i++){
            // 원래 배열 백업
            for(int l=0;l<n;l++){
                for(int j=0;j<m;j++){
                    copy_arr[l][j] = arr[l][j];
                }
            }
            int nx = x+dx[(i+1)%4];
            int ny = y+dy[(i+1)%4];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[(i+1)%4];
                ny = ny+dy[(i+1)%4];
            }
            nx = x+dx[(i+2)%4];
            ny = y+dy[(i+2)%4];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[(i+2)%4];
                ny = ny+dy[(i+2)%4];
            }
            nx = x+dx[(i+3)%4];
            ny = y+dy[(i+3)%4];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[(i+3)%4];
                ny = ny+dy[(i+3)%4];
            }
            sim(copy_arr, num_cctv+1);
        } 
    }
    else if (cctv == 5){
        for(int l=0;l<n;l++){
            for(int j=0;j<m;j++){
                copy_arr[l][j] = arr[l][j];
            }
        }
        for (int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            while(inrange(nx,ny)){
                if (copy_arr[nx][ny] == 6) break;
                copy_arr[nx][ny] = '#';
                nx = nx+dx[i];
                ny = ny+dy[i];
            }
        } 
        sim(copy_arr, num_cctv+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> o_arr[i][j];
            if (o_arr[i][j] >= 1 && o_arr[i][j] <= 5){
                cctv.push_back(make_pair(i,j));
            }
        }
    }
    sim(o_arr,0);
    cout << answer;    
    
    return 0;
}