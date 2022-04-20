#include<bits/stdc++.h>

using namespace std;
int n,m;
int arr[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int,int>> viruses;
int num_empty = 0;
int inrange(int x, int y){return (x>=0 && x<n && y>=0 && y<n);}

int sim(vector<int> a){
    queue<pair<int,int>> q;
    int d[51][51]={0};
    for(int i=0;i<a.size();i++){
        if(a[i] == 1) {
            q.push(viruses[i]);
            d[viruses[i].first][viruses[i].second] = 1;
        }
    }
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(inrange(nx,ny)){
				if(d[nx][ny]==0 && arr[nx][ny] != 1){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
    int max_time = 0;
    int spread = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (arr[i][j] == 0 && d[i][j] != 0){
                spread++;
                if(max_time < d[i][j]-1) max_time = d[i][j]-1;
            }
        }
    }
    if (spread == num_empty) return max_time;
    else return -1;
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
        for(int j=0;j<n;j++){
            int c;
            cin >> c;
            if (c == 2) viruses.push_back(make_pair(i,j));
            else if (c == 0) num_empty++;
            arr[i][j] = c;
            
        }
    }
    int answer = -1;
    vector<int> a(viruses.size(),0);
    for (int i=0; i<m; i++) {
        a[i] = 1;
    }
    sort(a.begin(), a.end());
    do {
        int temp = sim(a);
        if (temp == -1) continue;
        else if (answer == -1 || temp < answer){
            answer = temp;
        }
    } while(next_permutation(a.begin(), a.end()));

    cout << answer;
    return 0;
}