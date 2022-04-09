#include<bits/stdc++.h>

using namespace std;
int n;
int arr[21][21];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<vector<int>> bfs(int a, int b, int size){
    queue<pair<int,int>> q;
    vector<vector<int>> d(21,vector<int>(21,0));
	q.push(make_pair(a,b));
	d[a][b]=1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<n){
				if(arr[nx][ny]<=size && d[nx][ny] == 0){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n;
    int sx, sy; // 상어 위치
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin >> c;
            if (c != 9){
                arr[i][j] = c;
            }
            else{
                sx = i;
                sy = j;
            }
        }
    }

    int answer = 0;
    int size = 2;
    int eat_count = 0;
    while(true){
        vector<vector<int>> fish_distance = bfs(sx,sy,size);
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << fish_distance[i][j];
            }
            cout << endl;
        }*/
        int min_distance = -1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if (arr[i][j] != 0 && arr[i][j] < size){
                    if (fish_distance[i][j]!=0 && fish_distance[i][j] != 1 && (min_distance == -1 || fish_distance[i][j] <= min_distance)){
                        min_distance = fish_distance[i][j];
                        sx = i;
                        sy = j;
                    } 
                }
            }
        }
        if (min_distance == -1) break; // 종료 조건
        else{
            arr[sx][sy] = 0;
            answer += (fish_distance[sx][sy]-1);
            eat_count++;
            if (eat_count == size){
                eat_count = 0;
                size++;
            }
        }
        /*
        cout << "sx,sy:" << sx << " " << sy << endl;
        cout << "size:" << size << endl;
        cout << "time:" << answer << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << arr[i][j];
            }
            cout << endl;
        }*/
    }
    cout << answer;
    return 0;
}