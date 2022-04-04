#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> people;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int calculate(vector<int> a){
    int total_distance = 0;
    for(int i=0;i<people.size();i++){
        int p_x,p_y;
        tie(p_x,p_y) = people[i]; // 집 좌표
        int min_distance = -1;
        for(int j=0;j<a.size();j++){
            if (a[j] == 1){
                int c_x,c_y;
                tie(c_x,c_y) = chicken[j]; // 치킨집 좌표
                int distance = (abs(p_x-c_x) + abs(p_y-c_y));
                if (min_distance == -1 || distance < min_distance) min_distance = distance;
            }
        }
        total_distance += min_distance;
    }
    return total_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("result.txt", "w", stdout);
    #endif 
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int c;
            cin >> c;
            if (c == 1) people.push_back(make_pair(i,j));
            else if (c == 2) chicken.push_back(make_pair(i,j));
        }
    }

    int answer = -1;
    vector<int> a(chicken.size(),0);
    for (int i=0; i<m; i++) {
        a[i] = 1;
    }
    sort(a.begin(), a.end());
    do {
        int temp = calculate(a);
        if (answer == -1 || answer > temp) answer = temp;
    } while(next_permutation(a.begin(), a.end()));

    cout << answer;
    
    return 0;
}