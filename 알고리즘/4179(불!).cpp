#include <bits/stdc++.h>
using namespace std;

struct maze {
    int x, y, f;
};

char arr[1001][1001];
int dist[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
deque<maze>dq;
int r,c;

int bfs(){
    while (!dq.empty()){
        int x = dq.front().x;
        int y = dq.front().y;
        int f = dq.front().f;
        dq.pop_front();
        if (f == 0){
            if (x == 0 || y == 0 || x == r-1 || y == c-1) return dist[x][y];
        }

        for (int i=0; i<4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c || arr[next_x][next_y] == '#') continue;
            if (f){
                dq.push_back({next_x,next_y,1});
                arr[next_x][next_y] = '#';
            }
            else if (!dist[next_x][next_y]){
                dq.push_back({next_x,next_y,0});
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> r >> c;
    for (int i=0; i<r; i++){
        string s; cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
            if (s[j] == 'J'){
                dist[i][j] = 1;
                dq.push_back({i,j,0});
            }
            if (s[j] == 'F'){
                arr[i][j] = '#';
                dq.push_front({i,j,1});
            }
        }
    }
    int res = bfs();
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    if (res == -1) cout << "IMPOSSIBLE";
    else cout << res;
}