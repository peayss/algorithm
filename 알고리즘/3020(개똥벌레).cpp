#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<int> j;

int main(){
    int n,h; cin >> n >> h;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        if (i%2==0) s.push_back(t);
        else j.push_back(t);
    }
    sort(s.begin(),s.end());
    sort(j.begin(),j.end());

    int min = 999999999, cnt = 0;
    for (int i=1; i<=h; i++){
        //cout << "i가 -> " << i << '\n';
        int s_num = s.size() - (lower_bound(s.begin(), s.end(), i) - s.begin());
        //cout << "s_num -> " << s_num << '\n';
        int j_num = j.size() - (lower_bound(j.begin(), j.end(), h-i+1) - j.begin());
        //cout << "j_num -> " << j_num << '\n';
        if (s_num + j_num < min) {
            min = s_num + j_num;
            cnt = 1;
        } else if (s_num + j_num == min) cnt++;
    }
    cout << min << " " << cnt;

}