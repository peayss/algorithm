#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x,y,w;
};

int arrive_x,arrive_y,r,c;
char arr[51][51];
int dist[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
deque<Node>dq;

int bfs(){
    while (!dq.empty()){
        int x = dq.front().x;
        int y = dq.front().y;
        int w = dq.front().w;
        dq.pop_front();

        if (x == arrive_x && y == arrive_y && w == 0) return dist[x][y] - 1;
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == 'X') continue;
            if (w && arr[nx][ny] != 'D') {
                dq.push_back({nx,ny,1});
                arr[nx][ny] = 'X';
            } else if (!w && !dist[nx][ny]){
                dist[nx][ny] = dist[x][y] + 1;
                dq.push_back({nx,ny,0});
            }
        }
            // cout << "arr 배열 -> " << '\n';
            // for (int q=0; q<r; q++){
            //     for (int p=0; p<c; p++){
            //         cout << arr[q][p] << " ";
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            // cout << "dist 배열 -> " << '\n';
            // for (int q=0; q<r; q++){
            //     for (int p=0; p<c; p++){
            //         cout << dist[q][p] << " ";
            //     }
            //     cout << '\n';
            // }
    }
    return -1;
}

int main(){
    cin >> r >> c;
    for (int i=0; i<r; i++){
        string s; cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
            if (s[j] == 'D'){
                arrive_x = i; 
                arrive_y = j;
            }
            if (s[j] == '*'){
                arr[i][j] = 'X';
                dq.push_front({i,j,1});
            }
            if (s[j] == 'S'){
                dist[i][j] = 1;
                dq.push_back({i,j,0});
            }
        }
    }
    int res = bfs();
    if (res == -1) cout << "KAKTUS";
    else cout << res;
}