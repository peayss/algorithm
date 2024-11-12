// union-find 활용
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

vector<int> party[MAX];
vector<int> truth;
int parent[MAX];
int n, m, total, truth_num;

// 부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}
// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
// 같은 부모를 가지는 지 확인하는 함수
int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}
int main(){
    cin >> n >> m;
    cin >> truth_num;

    for (int i = 0; i < truth_num; i++){
        int p;
        cin >> p;
        truth.push_back(p);
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++){
        int num;
        cin >> num;
        int first;
        cin >> first;
        party[i].push_back(first);
        for (int j = 1; j < num; j++){
            int next;
            cin >> next;
            unionParent(parent, first, next);
            first = next;
            party[i].push_back(next);
        }
    }

    for (int i=1; i<truth.size(); i++)
        unionParent(parent, truth[0], truth[i]);

    int cnt = m, flag = 0;
    for (int i = 0; i < m; i++){
        flag = 0;
        for (int j = 0; j < party[i].size(); j++){
            if (flag) break;
            for (int z = 0; z < truth.size(); z++){
                if (findParent(parent, party[i][j], truth[z])){
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) cnt--;
    }
    cout << cnt;
}