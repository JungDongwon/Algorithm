#include<bits/stdc++.h>

using namespace std;
int n, k, l;
int arr[101][101] = {0};
queue<pair<int,char>> trans;
int dx[] = {0, 1, 0, -1}; // 동, 남, 서, 북
int dy[] = {1, 0, -1, 0};
bool inrange(int x, int y) { return 0 <= y && y < n && 0 <= x && x < n; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 

    cin >> n >> k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        arr[x-1][y-1] = 1; // 사과는 1
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int x;
        char c;
        cin >> x >> c; 
        trans.push(make_pair(x,c));
    }

    deque<pair<int,int>> snake; // 뱀
    snake.push_back(make_pair(0,0)); // 시작점 (0,0)
    int curtime = 0; // 경과 시간
    int curdir = 0; // 동쪽
    while(1){
        curtime++;
        int x = snake.front().first;
        int y = snake.front().second;
        int nx = x + dx[curdir];
        int ny = y + dy[curdir];
        if(!inrange(nx,ny)) break; // 벽에 부딛치는 경우
        if (count(snake.begin(), snake.end(), make_pair(nx,ny)) != 0) break; // 몸에 부딛치는 경우
        if (arr[nx][ny] == 1){ // 사과 먹는 경우
            snake.push_front(make_pair(nx,ny));
            arr[nx][ny] = 0;
        } 
        else{ // 사과 안먹는 경우
            snake.push_front(make_pair(nx,ny));
            snake.pop_back();
        }
        int transtime = trans.front().first;
		char transdir = trans.front().second;
        if (curtime == transtime) {
            trans.pop();
            if (transdir == 'D'){
                curdir = (curdir+1) % 4;
            }
            else{
                curdir = (curdir+3) % 4;
            }
        }
        //cout << "nx: " << nx << " ny: " << ny << endl;
        //cout << "curtime: " << curtime << " curdir: " << curdir << endl;
    }

    cout << curtime;
    return 0;
}