#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[9][9];
vector<pair<int,int>> virus;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool inrange(int x, int y) { return 0 <= y && y < m && 0 <= x && x < n; }

int simulate(vector<int> &a){
    // 원래 배열 백업
    int copy_arr[9][9];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            copy_arr[i][j] = arr[i][j];
        }
    }
    int idx = 0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (copy_arr[i][j] != 0) continue;
            if (a[idx] == 1) {
                copy_arr[i][j] = 1;
                idx++;
            }
            else idx++;
        }
    }
    // 바이러스 벡터 백업
    queue<pair<int,int>> copy_virus;
    for(int i=0;i<virus.size();i++){
        copy_virus.push(virus[i]);
    }
    while(!copy_virus.empty()){
		int x = copy_virus.front().first;
		int y = copy_virus.front().second;
		copy_virus.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(inrange(nx,ny)){
				if(copy_arr[nx][ny]==0){
					copy_virus.push(make_pair(nx,ny));
					copy_arr[nx][ny] = 2;
				}
			}
		}
	}

    int temp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (copy_arr[i][j] == 0) temp++;
            //cout << copy_arr[i][j];
        }
        //cout << endl;
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    
    cin >> n >> m;
    int num_space = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back(make_pair(i,j));
            }
            else if (arr[i][j] == 0) num_space++;
        }
    }
    
    int answer = 0;
    vector<int> a(num_space,0);
    for (int i=0; i<3; i++) {
        a[i] = 1;
    }
    sort(a.begin(), a.end());
    do {
        int temp = simulate(a);
        answer = max(answer,temp);
    } while(next_permutation(a.begin(), a.end()));

    cout << answer;
    return 0;
}