#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

vector<int> value;
int F[MAX];

int main(){
    int n,k;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        value.push_back(num);
    }
    for (int i=1; i<=k; i++) F[i] = MAX;
    for (int i=0; i<n; i++){
        for (int j=value[i]; j<=k; j++){
            F[j] = min(F[j], F[j-value[i]] + 1);
        }
    }
    if (F[k] == 10001) cout << -1;
    else cout << F[k];
}   