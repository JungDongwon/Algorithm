#include<bits/stdc++.h>
using namespace std;

int A[501][501] = {0}, n;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
bool inrange(int x, int y) { return 0 <= y && y < n && 0 <= x && x < n; }
int arr[5][5] = { 
    {0, 0, 2, 0, 0},
    {0,10, 7, 1, 0},
    {5, 0, 0, 0, 0},
    {0,10, 7, 1, 0},
    {0, 0, 2, 0, 0}
};
void Turn() {
    int tmp[5][5] = { };
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) tmp[i][j] = arr[i][j];
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) arr[4-j][i] = tmp[i][j];
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
            cin >> A[i][j];
        }
    }

    int cx = n/2;
    int cy = n/2;
    int dir = 0; // 0 -> 1 -> 2 -> 3 -> 0 ...
    int len = 1; // 1 -> 1 -> 2 -> 2 -> ...
    int answer = 0;
    bool flag = false;

    while(1){
        if(flag) break;
        for (int i=0;i<len;i++){
            cx += dx[dir];
            cy += dy[dir];
            if (cx==0 && cy==0) flag=true;
            int val = A[cx][cy]; // 토네이도 위치 
            for (int j=-2;j<3;j++){
                for(int k=-2;k<3;k++){
                    int curx = cx+j;
                    int cury = cy+k;
                    int curvalue = val * arr[j+2][k+2] / 100;
                    A[cx][cy] -= curvalue;
                    if(!inrange(curx,cury)) answer += curvalue;
                    else A[curx][cury] += curvalue;
                    
                }
            }
           
            if(inrange(cx+dx[dir],cy+dy[dir])) A[cx+dx[dir]][cy+dy[dir]] += A[cx][cy]; 
            else answer += A[cx][cy];
            A[cx][cy] = 0;
        }
        /*
        cout << cx << " " <<cy << endl;
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        dir = (dir+1)%4;
        if ((dir == 0 || dir == 2) && len < n-1){
            len += 1;
        }
        Turn();
    }
    cout << answer;
    return 0;
}