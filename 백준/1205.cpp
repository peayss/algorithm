#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int score[MAX];

int main() {
    int n, new_score, p;
    cin >> n >> new_score >> p;
    for (int i=1; i<=n; i++){
        int s;
        cin >> score[i];
    }
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (score[i] > new_score){
            cnt++;
        }
    }
    if (cnt == p) cout << - 1;
    else if (cnt == p - 1 && new_score == score[p]) cout << - 1;
    else cout << cnt+1;
}