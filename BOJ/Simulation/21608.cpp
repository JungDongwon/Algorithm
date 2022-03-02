#include<bits/stdc++.h>
using namespace std;

int n;
int pref[410][4];
int arr[21][21] = {0};
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool inrange(int x, int y) { return 0 <= y && y < n && 0 <= x && x < n; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n;

    for(int l=0;l<n*n;l++){
        int st;
        cin >> st; 
        cin >> pref[st][0] >> pref[st][1] >> pref[st][2] >> pref[st][3]; 
        int max_pref_score = 0;
        int max_empty_score = 0;
        int max_x, max_y;
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int pref_score = 0;
                int empty_score = 0;
                if (arr[i][j] != 0) continue;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (!inrange(nx,ny)) continue;
                    for(int m=0;m<4;m++){
                        if(arr[nx][ny] == pref[st][m]) pref_score += 1;
                    }  
                    if(arr[nx][ny] == 0) empty_score += 1;
                }
                if (pref_score > max_pref_score){
                    max_pref_score = pref_score;
                    max_empty_score = empty_score;
                    max_x = i;
                    max_y = j;
                }
                else if (pref_score == max_pref_score && empty_score > max_empty_score){
                    max_empty_score = empty_score;
                    max_x = i;
                    max_y = j;
                }
                else if(pref_score == 0 && empty_score == 0 && max_pref_score == 0 && max_empty_score == 0 &&flag == 0){ 
                    max_x = i;
                    max_y = j;
                    flag = 1;
                }
                //cout << "pref: " << pref_score << endl;
                //cout << "empty: " << empty_score << endl;
            }
        }
        arr[max_x][max_y] = st;
        //cout << "st: " << st << " ";
        //cout << "max_pref: " << max_pref_score << endl;
        //cout << "max_empty: " << max_empty_score << endl;
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
    }

    // 정답 구하기
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int pref_score = 0;
            int st = arr[i][j];
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!inrange(nx,ny)) continue;
                for(int m=0;m<4;m++){
                    if(arr[nx][ny] == pref[st][m]) pref_score += 1;
                }  
            }
            if (pref_score == 1) answer += 1;
            else if (pref_score == 2) answer += 10;
            else if (pref_score == 3) answer += 100;
            else if (pref_score == 4) answer += 1000;
        }
    }
    cout << answer;
    return 0;
}