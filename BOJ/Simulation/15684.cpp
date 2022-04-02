#include<bits/stdc++.h>

using namespace std;
int n, m, h;
int arr[31][11] = {0};

bool go(int a[][11]){
    for(int i=1;i<=n;i++){
        int cur = i;
        for(int j=1;j<=h;j++){
            if (a[j][cur]==1) cur+=1;
            else if (a[j][cur]==2) cur-=1;
        }
        if (cur != i) return false;
    }
    return true;
}

bool sim(int x1, int y1, int x2, int y2, int x3, int y3){
    int copy_arr[31][11] = {0};
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            copy_arr[i][j] = arr[i][j];
        }
    }
    copy_arr[x1][y1] = 1;
    copy_arr[x1][y1+1] = 2;
    copy_arr[x2][y2] = 1;
    copy_arr[x2][y2+1] = 2;
    copy_arr[x3][y3] = 1;
    copy_arr[x3][y3+1] = 2;

    bool result = go(copy_arr);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> m >> h;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[a][b+1] = 2;
    }

    int answer = -1;
    if(go(arr)){
        cout << "0";
        return 0;
    }
    int x1, x2, x3, y1, y2, y3;
    for(x1=1;x1<=h;x1++){
        for(y1=1;y1<=n-1;y1++){
            if( arr[x1][y1]==1 || arr[x1][y1]==2 || arr[x1][y1+1]==1) continue;
            for(x2=x1;x2<=h;x2++){
                for(y2=1;y2<=n-1;y2++){
                    if( arr[x2][y2]==1 || arr[x2][y2]==2 || arr[x2][y2+1]==1) continue;
                    if (x1==x2 && (y1==y2+1 || y2==y1+1)) continue;
                    for(x3=x2;x3<=h;x3++){
                        for(y3=1;y3<=n-1;y3++){
                            if( arr[x3][y3]==1 || arr[x3][y3]==2 || arr[x3][y3+1]==1) continue;
                            if (x1==x3 && (y1==y3+1 || y3==y1+1)) continue;
                            if (x2==x3 && (y2==y3+1 || y3==y2+1)) continue;
                            
                            if(sim(x1,y1,x2,y2,x3,y3)){
                                int ans = 3;
                                if(x1==x2 && y1==y2) ans-=1;
                                if(x1==x3 && y1==y3) ans-=1;
                                if(x3==x2 && y3==y2) ans-=1;
                                if(x1==x3 && x1==x2 && y1==y3 && y1==y2) ans+=1;
                                if (answer==-1 || answer > ans) answer = ans;
                            }
                        }
                    }               
                }
            }
        }
    }
    cout << answer;


    return 0;
}