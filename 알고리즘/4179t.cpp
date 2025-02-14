#include <bits/stdc++.h>
using namespace std;

struct maze {
    int x, y;
};

int r,c;

char arr[1001][1001]; // 미로 정보
int fire_time[1001][1001]; // 불 시간 배열
int j_time[1001][1001]; // 지훈 시간 배열
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

queue<maze>jh;
queue<maze>f;

void fire_bfs(){ // 불 이동 
    while (!f.empty()){
        int f_x = f.front().x;
        int f_y = f.front().y;
        f.pop();

        for (int i=0; i<4; i++){
            int next_x = f_x + dx[i];
            int next_y = f_y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c || arr[next_x][next_y] == '#') continue;
            if (fire_time[next_x][next_y] == -1){
                // cout << "next_x : " << next_x << '\n';
                // cout << "next_y : " << next_y << '\n';
                // cout << "dx[i] : " << dx[i] << '\n';
                // cout << "dy[i] : " << dy[i] << '\n';
                f.push({next_x, next_y});
                fire_time[next_x][next_y] = fire_time[f_x][f_y] + 1;
            }
        }
    }
    
}
int bfs(){ // 지훈 이동
    while (!jh.empty()){
        int x = jh.front().x;
        int y = jh.front().y;
        jh.pop();

        if (x == 0 || y == 0 ||x == r-1 ||y == c-1) return j_time[x][y] + 1;

        for (int i=0; i<4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c || arr[next_x][next_y] == '#') continue;
            if (j_time[next_x][next_y] == -1){
                if (fire_time[next_x][next_y] == -1 || fire_time[next_x][next_y] > j_time[x][y]+1)
                jh.push({next_x, next_y});
                j_time[next_x][next_y] = j_time[x][y] + 1;
            }
        }
    }
    return -1;
}
int main(){
    memset(fire_time, -1, sizeof(fire_time));
    memset(j_time, -1, sizeof(j_time));
    cin >> r >> c;
    for (int i=0; i<r; i++){
        string s; cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
            if (s[j] == 'J'){
                j_time[i][j] = 0;
                jh.push({i,j});
            }
            if (s[j] == 'F'){
                fire_time[i][j] = 0;
                j_time[i][j] = 0;
                f.push({i,j});
            }
        }
    }
    fire_bfs();
    // for (int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout << fire_time[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int res = bfs();
    //     for (int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout << j_time[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    if (res == -1) cout << "IMPOSSIBLE";
    else cout << res;
}