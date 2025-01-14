#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int s, p, a, c, g, t;
int start = 0, end = p, answer = 0, now = 0;
string pwd;

void solve(int prev, int start, int end){
    if (pwd[prev] == 'A') cnt[0]--;
    if (pwd[prev] == 'C') cnt[1]--;
    if (pwd[prev] == 'G') cnt[2]--;
    if (pwd[prev] == 'T') cnt[3]--;

    if (pwd[end] == 'A') cnt[0]++;
    if (pwd[end] == 'C') cnt[1]++;
    if (pwd[end] == 'G') cnt[2]++;
    if (pwd[end] == 'T') cnt[3]++;

    if (cnt[0] >= a && cnt[1] >= c && cnt[2] >= g && cnt[3] >= t) answer++;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> p >> pwd >> a >> c >> g >> t;

    for (int i=0; i<p; i++){
        if (pwd[i] == 'A') cnt[0]++;
        if (pwd[i] == 'C') cnt[1]++;
        if (pwd[i] == 'G') cnt[2]++;
        if (pwd[i] == 'T') cnt[3]++;
    }

    if (cnt[0] >= a && cnt[1] >= c && cnt[2] >= g && cnt[3] >= t) answer++;

    for (int i=0; i<s-p; i++){
        solve(i, i+1, i+p);
    }
    cout << answer;
}

//--Win[DNA[Start++] - 'A']; ++Win[DNA[++End] - 'A'];