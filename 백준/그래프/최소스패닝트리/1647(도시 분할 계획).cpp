#include <bits/stdc++.h>

using namespace std;
int n, m, total, cnt;

struct city {
    int a, b, c;
};

bool cmp (city a, city b){
    return a.c < b.c;
}

vector <city> v;
int parent[100001];

// 부모 노드를 찾는 함수
int getParent(int parent[], int x){
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}
// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a<b) parent[b] = a;
    else parent[a] = b;
}
// 같은 부모를 가지는 지 확인하는 함수
int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        city tmp = {a,b,c};
        v.push_back(tmp);
    }
    for (int i=1; i<=n; i++)
        parent[i] = i;

    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<v.size(); i++){
        if (cnt == n-2) break;
        if (!findParent(parent, v[i].a, v[i].b)){
            total += v[i].c;
            cnt++;
            unionParent(parent, v[i].a, v[i].b);
        }
    }
    cout << total;
}