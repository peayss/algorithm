#include <bits/stdc++.h>
using namespace std;

struct maze {
    int x, y;
};

int r,c,start_r,start_c,fire_r,fire_c;
int visited[1001][1001];
int f_visited[1001][1001];

int arr[1001][1001];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int next_x, next_y;
queue<maze>q;
queue<maze>f;

int cnt = 0, res = 0;
void bfs(){
    while(!q.empty() || !f.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        int f_x = f.front().x;
        int f_y = f.front().y;
        f.pop();
    
        for(int i=0; i<4; i++){ // 지훈이 이동
            next_x = x + dx[i];
            next_y = y + dy[i];
            // if (f_visited[next_x][next_y] && next_x != fire_r && next_y != fire_c) {
            //     return 0;
            // }
            if (next_x == r || next_y == c){
                res = visited[next_x][next_y];
                return;
            }
            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c) continue;
            if (visited[next_x][next_y] == 0 && arr[next_x][next_y] != -1 && !f_visited[next_x][next_y] && next_x != fire_r && next_y != fire_c){
                maze next = {next_x, next_y};
                q.push(next);
                visited[next_x][next_y] = visited[x][y] + 1;
                if (next_x == 0 || next_y == 0 || next_x == r-1 || next_y == c-1) {
                    // cout << "next_x : " << next_x << '\n';
                    // cout << "next_y : " << next_y << '\n';
                    res = visited[next_x][next_y];
                    return;
                }
            } else return;
        }
        
        for(int i=0; i<4; i++){ // 불 이동
            next_x = f_x + dx[i];
            next_y = f_y + dy[i];
            //cout << "f_x : " << f_x << '\n';
            //cout << "f_y : " << f_y << '\n';

            if (next_x < 0 || next_y < 0 || next_x >= r || next_y >= c) continue;
            if (f_visited[next_x][next_y] == 0 && arr[next_x][next_y] != -1){
                // cout << "next_x : " << next_x << '\n';
                // cout << "next_y : " << next_y << '\n';
                // cout << "dx[i] : " << dx[i] << '\n';
                // cout << "dy[i] : " << dy[i] << '\n';

                maze next = {next_x, next_y};
                f.push(next);
                f_visited[next_x][next_y] = 1;
            }
        }
        // 디버깅
        // for (int i=0; i<r; i++){
        //     for (int j=0; j<c; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int i=0; i<r; i++){
        //     for (int j=0; j<c; j++){
        //         cout << f_visited[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }
}

int main(){
    cin >> r >> c;
    for (int i=0; i<r; i++){
        string s; cin >> s;
        for (int j=0; j<c; j++){
            if (s[j] == '#') arr[i][j] = -1;
            if (s[j] == 'J') {
                start_r = i; 
                start_c = j;
            }
            if (s[j] == 'F') {
                fire_r = i;
                fire_c = j;
            }
        }
    }
    // for (int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    visited[start_r][start_r] = 1;
    q.push({start_r,start_c});
    f_visited[fire_r][fire_c] = 1;
    f.push({fire_r,fire_c});
    bfs();
    if (res == 0) cout << "IMPOSSIBLE";
    else cout << res;
}