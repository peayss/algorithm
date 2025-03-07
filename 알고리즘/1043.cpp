#include <bits/stdc++.h>
using namespace std;

int parent[51];
vector<int>party[51];
vector<int>truth;

int getParent(int node){
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}
void unionParent(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}
bool isCycle(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,t; 
    cin >> n >> m >> t;
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=0; i<t; i++) {
        int p; cin >> p;
        truth.push_back(p);
    }
    for (int i=0; i<m; i++){
        int num; cin >> num;
        for (int j=0; j<num; j++){
            int p; cin >> p;
            party[i].push_back(p);
        }
    }
    if (t == 0) {
        cout << m;
        return 0;
    }
    // 진실을 아는 사람들끼리 union해주기
    for (int i=0; i<t-1; i++){
        if (!isCycle(truth[i], truth[i+1])){
            unionParent(truth[i], truth[i+1]);
        }
    }
    for (int i=0; i<m; i++){
        for (int i=0; i<m; i++){
            if (party[i].size() > 1){
                for(int j=0; j<party[i].size()-1; j++){
                    if (!isCycle(party[i][j], party[i][j+1])){
                        unionParent(party[i][j], party[i][j+1]);
                    }
                }
            }
        }
    }
    int cnt = 0;
    int res = parent[truth[0]];
    for (int i=0; i<m; i++){
        int flag = 0;
        for(int j=0; j<party[i].size(); j++){
            if (parent[party[i][j]] == res) flag = 1;
        }
        if (!flag) cnt++;
    }
    //for (int i=1; i<=n; i++) cout << parent[i] << " ";
    cout << cnt;
}