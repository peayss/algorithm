// 안쪽 for문이 몇 번 수행됐는 지 구해야함
// vector<pair<int, int> >A; -> A.push_back({value,i});
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int, int> >A(N);
    for (int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    int max = 0;
    for (int i=0; i<N; i++){
        if (max < A[i].second - i) max = A[i].second - i; 
    }
    cout << max + 1;
}