// 1. 높이 n이하인 영역은 물에 잠기면 그 영역을 0으로 만든다
// 2. 0보다 큰 영역 중 dfs를 이용해서 섬의 개수를 센다
// 3. 가장 높은 높이까지 while문을 돌려서 최대 영역의 개수를 센다
// 즉, 비의 양 경우를 0~최대높이까지 
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int next_x, next_y;
int cnt;

void print() {
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
void flood(int rain){ // 비의 양에 따라 물에 잠기게 하는 함수
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] <= rain) arr[i][j] = 0;
        }
    }
}

void dfs(int x, int y) { // 영역 개수 세는 함수
    for (int i = 0; i < 4; i++){
        next_x = x + dr[i];
        next_y = y + dc[i];

        if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;

        if (arr[next_x][next_y] > 0 && !visited[next_x][next_y]){
            visited[next_x][next_y] = 1;
            dfs(next_x, next_y);
        }
    }
}

int main() {
    cin >> n;
    int max_num = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
            if (max_num < arr[i][j]) max_num = arr[i][j];
        }
    }

    int max_area = 0;
    // **비의 양은 0부터 계산
    for (int k=0; k<=max_num; k++){ // **0부터 9까지
        cnt = 0;
        flood(k);
        //print();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] > 0 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (max_area < cnt) max_area = cnt;
        memset(visited, 0, sizeof(visited));
    }
    cout << max_area;
}