#include <bits/stdc++.h>

using namespace std;

struct mst{
    int a, b, c;
};

vector<mst> vec;
int parent[10001];
int v, e, total;

bool cmp (mst a, mst b){
    return a.c < b.c; 
}

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
int main (){
    cin >> v >> e;
    //a,b,c를 한 번에 저장
    for (int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        mst temp = {a,b,c};
        vec.push_back(temp);
    }
    for (int i=1; i<=v; i++){
        parent[i] = i;
    }
    sort (vec.begin(), vec.end(), cmp);
    
    for (int i=0; i<vec.size(); i++){
        if (findParent(parent, vec[i].a, vec[i].b) == 0){
            total += vec[i].c;
            unionParent(parent, vec[i].a, vec[i].b);
        }
    }
    cout << total;
}