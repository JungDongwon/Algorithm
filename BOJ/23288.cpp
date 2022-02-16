#include<bits/stdc++.h>

using namespace std;
int n,m,k;
bool inrange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int Map[21][21]={}; 
int dice[] = {2,1,5,6,4,3};

int Roll(int dir){ // 밑면에 있는 숫자를 반환
    int tmp[6] = {};
    for (int i=0;i<6;i++) tmp[i] = dice[i];
    if (dir == 0){ // 동쪽
        dice[0] = tmp[0];
        dice[5] = tmp[1];
        dice[2] = tmp[2];
        dice[4] = tmp[3];
        dice[1] = tmp[4];
        dice[3] = tmp[5];
    } 
    else if (dir == 1) { // 남쪽
        dice[1] = tmp[0];
        dice[2] = tmp[1];
        dice[3] = tmp[2];
        dice[0] = tmp[3];
        dice[4] = tmp[4];
        dice[5] = tmp[5];
    }
    else if (dir == 2) { // 서쪽
        dice[0] = tmp[0];
        dice[4] = tmp[1];
        dice[2] = tmp[2];
        dice[5] = tmp[3];
        dice[3] = tmp[4];
        dice[1] = tmp[5];
    } 
    else if (dir == 3) { // 북쪽
        dice[3] = tmp[0];
        dice[0] = tmp[1];
        dice[1] = tmp[2];
        dice[2] = tmp[3];
        dice[4] = tmp[4];
        dice[5] = tmp[5];
    }
    return dice[3];
}

int bfs(int x, int y, int target){
    queue<pair<int,int>> q;
    int d[21][21]={0};
	q.push(make_pair(x,y));
	d[x][y]=1;
    int num_target = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(d[nx][ny]==0 && Map[nx][ny]==target){
					q.push(make_pair(nx,ny));
					d[nx][ny] = 1;
                    num_target += 1;
				}
			}
		}
	}
    return num_target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    int dir = 0;
    int x = 0;
    int y = 0;
    int answer = 0;

    while(k){
        //cout << "x,y,dir" << x << " " << y << " " << dir << endl;
        if(!inrange(x + dx[dir],y + dy[dir])){
            if (dir == 0) dir = 2;
            else if (dir == 1) dir = 3;
            else if (dir == 2) dir = 0;
            else if (dir == 3) dir = 1;
        }
        x = x + dx[dir];
        y = y + dy[dir];
        int A = Roll(dir);
        int B = Map[x][y];
        int num_B = bfs(x,y,B);
        //cout << "A,B,num_B" << A << " " << B << " " << num_B << endl;
        answer += (B * num_B);
        if (A>B) {
            dir = (dir + 1) % 4;
        }
        else if (A<B) {
            dir = (dir + 3) % 4;
        }
        k -= 1;
    }
    cout << answer;
    return 0;
}