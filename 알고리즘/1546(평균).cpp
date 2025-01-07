#include <bits/stdc++.h>
using namespace std;

int main(){
    double max = -1;
    float score;
    int total = 0;
    float answer;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> score;
        total += score;
        if (score > max) {
            max = score;
        }
    }
    answer = total * 100.0 / n / max;
    cout << answer;
}