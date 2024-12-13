#include <bits/stdc++.h>
#define MAX 301
using namespace std;

struct chess{
    int x,y;
};

int arr[MAX][MAX];
int dist[MAX][MAX];

int l, now_x, now_y, reach_x, reach_y;
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int bfs(int r, int c){
    queue<chess> q;
    chess start = {r,c};
    q.push(start);

    arr[r][c] = 1;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (x == reach_x && y == reach_y) return dist[x][y];
        for(int i=0; i<8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= l || next_y >= l) continue;
            if (!arr[next_x][next_y]){
                arr[next_x][next_y] = 1;
                dist[next_x][next_y] = dist[x][y]+1;
                chess next = {next_x, next_y};
                q.push(next);
            }
        }
    }
    return -1;
}
int main(){
    vector<int>answer;
    int t;
    cin >> t;
    while (t--){
        memset(dist, 0, sizeof(dist));
        memset(arr, 0, sizeof(arr));
        cin >> l;
        cin >> now_x >> now_y >> reach_x >> reach_y;
        if (now_x == reach_x && now_y == reach_y) answer.push_back(0);
        else answer.push_back(bfs(now_x,now_y));
    }
    for (int i=0; i<answer.size(); i++) cout << answer[i] << '\n';
}