#include <bits/stdc++.h>
using namespace std;

struct maze {
    int x, y, broken;
};

int m, n, res;
int arr[1001][1001];
int visited[1001][1001][2];
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,1,0,-1};

queue<maze> q;

int bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int broken = q.front().broken;
        q.pop();

        if (x == n-1 && y == m-1) return visited[n-1][m-1][broken];

        for(int i=0; i<4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;

            // 벽을 부수지않고 이동
            if (visited[next_x][next_y][broken] == 0 && arr[next_x][next_y] == 0){
                visited[next_x][next_y][broken] = visited[x][y][broken] + 1;
                maze next = {next_x, next_y, broken};
                q.push(next);
            }
            // 벽을 만났고 벽을 아직 부수지않았을 때 -> 벽을 부숨
            if (broken == 0 && visited[next_x][next_y][broken] == 0 && arr[next_x][next_y] == 1) {
                visited[next_x][next_y][1] = visited[x][y][broken] + 1;
                maze next = {next_x, next_y, 1};
                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp-'0';
        }
    }
    visited[0][0][0] = 1;
    maze start = {0,0,0};
    q.push(start);
    
    int res = bfs();
    cout << res;
}