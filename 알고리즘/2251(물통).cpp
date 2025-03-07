#include <bits/stdc++.h>
using namespace std;

struct Node{
    int A,B,C;
};
int to[6] = {0,0,1,1,2,2};
int from[6] = {1,2,0,2,0,1};
int visited[201][201][201];
int now[3];
priority_queue<int, vector<int>, greater<int>>res;
queue<Node>q;

int a,b,c;

void bfs(){
    while (!q.empty()){
        int _a = q.front().A;
        int _b = q.front().B;
        int _c = q.front().C;
        q.pop();        
        
        if (_a == 0) res.push(_c);
        for (int i=0; i<6; i++){
            int cur[3] = {_a, _b, _c};
            cur[to[i]] += cur[from[i]];
            cur[from[i]] = 0;

            if (cur[to[i]] > now[to[i]]) {
                cur[from[i]] = cur[to[i]] - now[to[i]];
                cur[to[i]] = now[to[i]];
            }
            if (!visited[cur[0]][cur[1]][cur[2]]){
                visited[cur[0]][cur[1]][cur[2]] = 1;
                q.push({cur[0],cur[1],cur[2]});
            }
        }
    }
}
int main(){
    cin >> now[0] >> now[1] >> now[2];
    q.push({0, 0, now[2]}); // 0 0 10 부터 시작
    visited[0][0][now[2]] = 1;
    bfs();
    while (!res.empty()){
        cout << res.top() << " "; res.pop();
    }
}