// 위상정렬
#include <bits/stdc++.h>
using namespace std;

vector<int> question[100001]; // 문제 정보 저장
int result[32001]; // 결과 배열
int n, m, inDegree[32001]; // 진입 차수 저장

void topologySort(){
    priority_queue<int, vector<int>, greater<int>> q;
    // 진입 차수가 0인 노드를 큐에 삽입
    for(int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    // 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문한다
    for (int i=0; i<n; i++){
        if(q.empty()) return;

        int x = q.top(); q.pop();
        result[i] = x;
        for (int j=0; j<question[x].size(); j++){
            int y = question[x][j];
            if (--inDegree[y]==0) q.push(y);
        }
    }
    for (int i=0; i<n; i++) cout << result[i] << " ";
}
int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        question[a].push_back(b);
        inDegree[b]++;
    }
    topologySort();
}
