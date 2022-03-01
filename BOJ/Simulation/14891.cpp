#include<bits/stdc++.h>

using namespace std;
int n;
int arr[5][9];

void rot(int num, int dir){
    // num 톱니바퀴 회전
    if (dir == 1){ // 시계방향
        for(int j=1;j<=8;j++){
            arr[num][9-j] = arr[num][8-j];
        }
        arr[num][0] = arr[num][8];
    }
    else if (dir == -1){ // 반시계방향
        arr[num][8] = arr[num][0];
        for(int j=1;j<=8;j++){
            arr[num][j-1] = arr[num][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    
    for (int i=1; i<=4; i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<8;j++){
            arr[i][j] = temp[j] - '0';
        }
    }
    cin >> n;
    for(int i=0;i<n;i++){
        int num, dir;
        cin >> num >> dir;

        int rot_status[5] = {0};
        rot_status[num] = dir;

        if (num == 1){
            for(int j=1;j<=3;j++){
                if (arr[j][2] == arr[j+1][6]) rot_status[j+1] = 0;
                else rot_status[j+1] = rot_status[j]*-1;
            }
        }
        else if(num == 2){
            // 3
            if (arr[2][2] == arr[3][6]) rot_status[3] = 0;
            else rot_status[3] = rot_status[2]*-1;
            // 4
            if (arr[3][2] == arr[4][6]) rot_status[4] = 0;
            else rot_status[4] = rot_status[3]*-1;
            //1
            if (arr[2][6] == arr[1][2]) rot_status[1] = 0;
            else rot_status[1] = rot_status[2]*-1;
        }
        else if(num == 3){
            // 4
            if (arr[3][2] == arr[4][6]) rot_status[4] = 0;
            else rot_status[4] = rot_status[3]*-1;
            //2
            if (arr[3][6] == arr[2][2]) rot_status[2] = 0;
            else rot_status[2] = rot_status[3]*-1;
            //1
            if (arr[2][6] == arr[1][2]) rot_status[1] = 0;
            else rot_status[1] = rot_status[2]*-1;
        }
        else if(num == 4){
            for(int j=3;j>=1;j--){
                if (arr[j+1][6] == arr[j][2]) rot_status[j] = 0;
                else rot_status[j] = rot_status[j+1]*-1;
            }
        }

        // 톱니바퀴 회전
        for(int j=1;j<=4;j++){
            rot(j,rot_status[j]); 
        }
        /*
        for(int k=1;k<=4;k++){
            for(int j=0;j<8;j++){
                cout << arr[k][j] << " ";
            }
            cout << endl ;
        }
        cout << endl;
        */
    }

    int answer = 0;
    if (arr[1][0] == 1) answer += 1;
    if (arr[2][0] == 1) answer += 2;
    if (arr[3][0] == 1) answer += 4;
    if (arr[4][0] == 1) answer += 8;

    cout << answer;
    return 0;
}