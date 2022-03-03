#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[501][501];
int shapes[19][4][2] = { {{0,0}, {0,1}, {0,2}, {0,3}},
{{0,0}, {1,0}, {2,0}, {3,0}},
{{0,0}, {0,1}, {1,0}, {1,1}},
{{0,0}, {1,0}, {2,0}, {2,1}},
{{0,1}, {1,1}, {2,0}, {2,1}},
{{0,0}, {0,1}, {0,2}, {1,0} },
{{0,0}, {0,1}, {0,2}, {1,2} },
{{0,0}, {0,1}, {1,1}, {2,1}},
{{0,0}, {0,1}, {1,0}, {2,0} },
{{0,2}, {1,0}, {1,1}, {1,2}},
{{0,0}, {1,0}, {1,1}, {1,2}},
{{0,0}, {1,0}, {1,1}, {2,1}},
{{0,1}, {1,0}, {1,1}, {2,0} },
{{0,1}, {0,2}, {1,0}, {1,1} },
{{0,0}, {0,1}, {1,1}, {1,2}},
{{0,0}, {0,1}, {0,2}, {1,1} },
{{0,1}, {1,0}, {1,1}, {1,2}},
{{0,1}, {1,0}, {1,1}, {2,1}},
{{0,0}, {1,0}, {1,1}, {2,0} }};
bool inrange(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) { 
    return 0 <= y1 && y1 < m && 0 <= x1 && x1 < n && 0 <= y2 && y2 < m && 0 <= x2 && x2 < n && 0 <= y3 && y3 < m && 0 <= x3 && x3 < n && 0 <= y4 && y4 < m && 0 <= x4 && x4 < n; 
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
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<19;k++){
                int x1 = i + shapes[k][0][0];
                int y1 = j + shapes[k][0][1];
                int x2 = i + shapes[k][1][0];
                int y2 = j + shapes[k][1][1];
                int x3 = i + shapes[k][2][0];
                int y3 = j + shapes[k][2][1];
                int x4 = i + shapes[k][3][0];
                int y4 = j + shapes[k][3][1];
                if (!inrange(x1,y1,x2,y2,x3,y3,x4,y4)) continue;
                int temp = arr[x1][y1] + arr[x2][y2] + arr[x3][y3] + arr[x4][y4];
                answer = max(temp,answer);
            }
        }
    }
    
    cout << answer;
    return 0;
}