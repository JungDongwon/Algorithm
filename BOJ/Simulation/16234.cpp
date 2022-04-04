#include<bits/stdc++.h>

using namespace std;
int n,l,r;
int arr[51][51];
int after_arr[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int inrange(int x, int y){return (x>=0 && x<n && y>=0 && y<n);}

int bfs(int x, int y){
    queue<pair<int,int>> q;
    int d[51][51] = {0};
    int num_allies = 0;
    int allies_pop = 0;
	q.push(make_pair(x,y));
	d[x][y]=1;
    num_allies += 1;
    allies_pop += arr[x][y];
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(inrange(nx,ny)){
                int thr = abs(arr[x][y] - arr[nx][ny]);
				if(d[nx][ny]==0 && thr >= l &&  thr <= r){
					q.push(make_pair(nx,ny));
					d[nx][ny] = 1;
                    num_allies += 1;
                    allies_pop += arr[nx][ny];
				}
			}
		}
	}
    after_arr[x][y] = int(allies_pop/num_allies);

    return num_allies;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    while (true){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bfs(i,j) == 1) cnt++;
            }
        }
        if (cnt == n*n) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = after_arr[i][j];
            }
        }
        answer++;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << after_arr[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << answer;
    
    return 0;
}