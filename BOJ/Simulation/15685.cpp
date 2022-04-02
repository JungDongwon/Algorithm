#include<bits/stdc++.h>

using namespace std;
int n;
int arr[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void sim(int x, int y, int d, int g){
    vector<pair<int,int>> dragon;
    dragon.push_back(make_pair(x,y));
    // 0세대 끝점 (nx,ny)
    int nx = x + dx[d];
    int ny = y + dy[d];
    dragon.push_back(make_pair(nx,ny));
    while(g--){
        vector<pair<int,int>> temp;
        tie(nx,ny) = dragon.back();
        //cout << "endpoint: " << nx << " " << ny << endl;
        dragon.pop_back();
        for (const auto &item : dragon) { // 모든 점 원점으로 이동
            //cout << "dragon: " << item.first << " " << item.second << endl;
            temp.push_back(make_pair(-(item.second-ny)+nx,item.first-nx+ny));
        }
        dragon.push_back(make_pair(nx,ny));
        while (!temp.empty()) { 
            tie(nx,ny) = temp.back();
            temp.pop_back();
            //cout << "temp: " << nx << " " << ny << endl;
            dragon.push_back(make_pair(nx,ny));
        }
    }
    while (!dragon.empty()) { 
        tie(nx,ny) = dragon.back();
        //cout << nx << " " << ny << endl;
        dragon.pop_back();
        arr[nx][ny] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n;
    while(n--){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        sim(x,y,d,g);
    }
    int answer = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if (arr[j][i]==1 && arr[j+1][i]==1 && arr[j][i+1]==1 && arr[j+1][i+1]==1) answer+=1;
        }
    }
    cout << answer;

/*
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout << arr[j][i];
        }
        cout << endl;
    }
*/
    return 0;
}