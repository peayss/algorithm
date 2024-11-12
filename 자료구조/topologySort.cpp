#include <bits/stdc++.h>
#define MAX 10
using namespace std;

vector<int> a[MAX]; // 노드 정보 저장
int result[MAX]; // 결과 배열
int n, inDegree[MAX]; // 진입 차수 저장

void topologySort(){
    queue<int> q;
    // 진입 차수가 0인 노드를 큐에 삽입
    for(int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    // 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문한다
    for (int i=1; i<=n; i++){
        if(q.empty()) return;

        int x = q.front(); q.pop();
        result[i] = x;
        for (int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if (--inDegree[y]==0) q.push(y);
        }
    }
    for (int i=1; i<=n; i++) cout << result[i] << " ";
}
int main(){
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;
    topologySort();
}