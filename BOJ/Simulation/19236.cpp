#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1,-1,0,1,1,1,0,-1}; // 동, 북동, 북, 북서, 서, 남서, 남, 남동
int dy[] = {0,-1,-1,-1,0,1,1,1};
bool inrange(int x, int y) { return 0 <= x && x < 4 && 0 <= y && y < 4; }
vector<tuple<int,int,int>> Fish(17, make_tuple(0,0,0));
int arr[5][5] = {0}; // 0: 물고기 없음, >0: 물고기
int answer = 0;

void dfs(int arr[][5], vector<tuple<int,int,int>> Fish, int s_x, int s_y, int s_d, int result){

    int copy_arr[5][5] = {0};
    vector<tuple<int,int,int>> copy_Fish(17, make_tuple(0,0,0));
    // 이전 상태 백업
    for (int i=0;i<4;i++) { 
		for (int j = 0; j < 4; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	for (int i=0;i<=16;i++) {
		copy_Fish[i] = Fish[i];
	}

    // 상어 잡아먹기
    
    int victim = copy_arr[s_x][s_y];
    int vx,vy,vd;
    tie(vx,vy,vd) = copy_Fish[victim];
    s_d = vd;
    copy_Fish[victim] = make_tuple(-1,-1,vd);
    copy_arr[s_x][s_y] = 0; // 물고기 없음
    result += victim;
    if (answer < result) answer = result;
    cout << victim << " " << answer << endl;

    for(int i=1;i<=16;i++){
        int x,y,d;
        tie(x,y,d) = copy_Fish[i];
        if (x==-1 && y==-1) continue; // 죽은 물고기
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nd = d, cnt = 0;
        while( (!inrange(nx,ny) || (nx==s_x && ny==s_y)) && cnt < 8) {
            nx = x + dx[nd];
            ny = y + dy[nd];
            nd = (nd+1) % 8;
            cnt += 1;
        }
        if (cnt == 8) continue;
        if (copy_arr[nx][ny] == 0){ // 빈 칸
            copy_arr[nx][ny] = i;
            copy_arr[x][y] = 0; 
            copy_Fish[i] = make_tuple(nx,ny,nd);
        }
        else if (nx!=s_x && ny!=s_y){ // 상어 자리가 아니면, 물고기 바꾸기
            int tmp = copy_arr[nx][ny];
            copy_arr[nx][ny] = i;
            copy_arr[x][y] = tmp;
            int cx, cy, cd;
            tie(cx,cy,cd) = copy_Fish[tmp];
            cx = x;
            cy = y;
            copy_Fish[tmp] = make_tuple(cx,cy,cd);
            copy_Fish[i] = make_tuple(nx,ny,nd);
        }
        
        for(int k=0;k<4;k++){
            for(int l=0;l<4;l++){
                cout << copy_arr[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
    }

    // 상어 움직임  
    for (int i=1;i<=3;i++){
        int ns_x = s_x + dx[s_d]*i;
        int ns_y = s_y + dx[s_d]*i;
        if(inrange(ns_x,ns_y) && copy_arr[ns_x][ns_y]!=0){
            dfs(copy_arr,copy_Fish,ns_x,ns_y,s_d,result);
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

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            int a,b;
            cin >> a >> b;
            Fish[a] = make_tuple(i,j,b-1);
            arr[i][j] = a;
        }
    }

    int result = 0;
    int s_x = 0; 
    int s_y = 0;
    int s_d = 0;
    //dfs(arr,Fish,s_x,s_y,s_d,result);

int copy_arr[5][5] = {0};
    vector<tuple<int,int,int>> copy_Fish(17, make_tuple(0,0,0));
    // 이전 상태 백업
    for (int i=0;i<4;i++) { 
		for (int j = 0; j < 4; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	for (int i=0;i<=16;i++) {
		copy_Fish[i] = Fish[i];
	}

    // 상어 잡아먹기
    
    int victim = copy_arr[s_x][s_y];
    int vx,vy,vd;
    tie(vx,vy,vd) = copy_Fish[victim];
    s_d = vd;
    copy_Fish[victim] = make_tuple(-1,-1,vd);
    copy_arr[s_x][s_y] = 0; // 물고기 없음
    result += victim;
    if (answer < result) answer = result;
    cout << victim << " " << answer << endl;

    for(int i=1;i<=16;i++){
        int x,y,d;
        tie(x,y,d) = copy_Fish[i];
        if (x==-1 && y==-1) continue; // 죽은 물고기
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nd = d, cnt = 0;
        while( (!inrange(nx,ny) || (nx==s_x && ny==s_y)) && cnt < 8) {
            nx = x + dx[nd];
            ny = y + dy[nd];
            nd = (nd+1) % 8;
            cnt += 1;
        }
        if (cnt == 8) continue;
        if (copy_arr[nx][ny] == 0){ // 빈 칸
            copy_arr[nx][ny] = i;
            copy_arr[x][y] = 0; 
            copy_Fish[i] = make_tuple(nx,ny,nd);
        }
        else if (nx!=s_x && ny!=s_y){ // 상어 자리가 아니면, 물고기 바꾸기
            int tmp = copy_arr[nx][ny];
            copy_arr[nx][ny] = i;
            copy_arr[x][y] = tmp;
            int cx, cy, cd;
            tie(cx,cy,cd) = copy_Fish[tmp];
            cx = x;
            cy = y;
            copy_Fish[tmp] = make_tuple(cx,cy,cd);
            copy_Fish[i] = make_tuple(nx,ny,nd);
        }
        
        for(int k=0;k<4;k++){
            for(int l=0;l<4;l++){
                cout << copy_arr[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    cout << answer;

    return 0;
}