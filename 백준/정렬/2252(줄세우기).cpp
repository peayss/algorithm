#include <bits/stdc++.h>
using namespace std;

vector<int> student[100001]; // 학생 정보 저장
int result[32001]; // 결과 배열
int n, m, inDegree[32001]; // 진입 차수 저장

void topologySort(){
    queue<int> q;
    // 진입 차수가 0인 노드를 큐에 삽입
    for(int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    // 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문한다
    for (int i=0; i<n; i++){
        if(q.empty()) return;

        int x = q.front(); q.pop();
        result[i] = x;
        for (int j=0; j<student[x].size(); j++){
            int y = student[x][j];
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
        student[a].push_back(b);
        inDegree[b]++;
    }
    topologySort();
}