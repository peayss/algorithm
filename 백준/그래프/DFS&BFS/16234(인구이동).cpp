// visited, unite 배열 초기화
// unite.size() = 1이면 인구이동 x
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

struct nation {
    int x, y;
};

int arr[MAX][MAX]; // NxN 땅
int visited[MAX][MAX];

int N,L,R; // N크기의 땅, 인구차이 L이상 R이하

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int bfs(int r, int c){
    queue<nation> q;
    vector<nation> unite; // 연합 국가 위치 저장
    nation start = {r,c};
    q.push(start);
    unite.push_back(start);

    visited[r][c] = 1;
    int total = arr[r][c];

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
            if (!visited[next_x][next_y]){
                int difference = abs(arr[x][y] - arr[next_x][next_y]);
                if (difference >= L && difference <= R){
                    visited[next_x][next_y] = 1;
                    nation next = {next_x, next_y};
                    unite.push_back(next);
                    q.push(next);
                    total += arr[next_x][next_y];
                }
            }
        }
    }

    if (unite.size() == 1) return 0; // 인구이동 x

    int people = total/unite.size();
    for (int z=0; z<unite.size(); z++){
        int x = unite[z].x;
        int y = unite[z].y;
        arr[x][y] = people;
    }
    return 1;
}

int main(){
    cin >> N >> L >> R;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int days = 0, flag = 0;

    while(1){
        flag = 0;
        memset(visited, 0, sizeof(visited));

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if(!visited[i][j]){
                    if(bfs(i,j)){
                        flag = 1;
                    };
                }
            }
        }
        if (!flag) break;
        days++;
    }
    cout << days;
}