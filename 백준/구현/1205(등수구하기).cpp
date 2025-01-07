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
    int cnt = 0; int rank = 1;
    for (int i=1; i<=n; i++){
        if (score[i] > new_score){
            rank++;
        } else if (score[i] < new_score){
            break;
        }
        cnt++;
    }
    if (cnt == p) rank = -1;
    if (n == 0) rank = 1;
    cout << rank;
}