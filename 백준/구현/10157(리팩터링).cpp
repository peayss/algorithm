#include <bits/stdc++.h>
using namespace std;

int c, r, k;
int dx[4] = {0, 1, 0, -1}; // 방향 배열 (우, 하, 좌, 상)
int dy[4] = {1, 0, -1, 0};
bool board[1001][1001];    // 방문 여부 확인 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    cin >> r >> c >> k;

    if (c * r < k) {
        cout << 0;
        return 0;
    }

    int x = 1, y = 1;  
    int direction = 0; // 현재 방향 (0: 우, 1: 하, 2: 좌, 3: 상)
    int num = 1;      

    board[x][y] = true; 

    while (num < k) {
        int nx = x + dx[direction]; 
        int ny = y + dy[direction]; 

        if (nx > r || nx <= 0 || ny > c || ny <= 0 || board[nx][ny]) {
            direction = (direction + 1) % 4; // 이동 불가 시 방향 전환
            continue;
        }

        x = nx;
        y = ny;
        board[x][y] = true;
        num++;
    }

    cout << x << ' ' << y;
    return 0;
}