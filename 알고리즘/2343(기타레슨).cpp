#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,m,sum,maxLec=0;
vector<int>lec;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int l; cin >> l;
        lec.push_back(l);
        sum += l;
        if (l > maxLec) maxLec = l;
    }
    // 9 ~ 45 사이
    ll min = maxLec, max = sum, middle, result;

    while (min <= max)
    {
        int cnt = 1; // 블루레이 세는 개수
        int temp_sum = 0;
        middle = (min + max) / 2;
        // cout << "min -> " << min << '\n';
        // cout << "mid -> " << middle << '\n';
        // cout << "max -> " << max << '\n';

        for (int i=0; i<n; i++){
            if (temp_sum + lec[i] > middle){
                cnt++;
                temp_sum = 0;
            } 
            temp_sum += lec[i];
        }
        if (cnt <= m) {
            result = middle;
            max = middle - 1;
        } else {
            min = middle + 1;
        }
    }
    cout << result;
}