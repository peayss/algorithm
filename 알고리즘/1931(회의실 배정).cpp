#include <bits/stdc++.h>
using namespace std;

struct Node {
    int start;
    int end;
    Node (int _start, int _end){
        start = _start;
        end = _end;
    }
    bool operator<(const Node &n) const{
        if (end == n.end) return start < n.start; // 시작 시간 작은거부터
        return end < n.end; // 끝나는 시간 짧은거부터
    }
};
vector<Node>arr;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int s,e;
        cin >> s >> e;
        arr.push_back(Node(s,e));
    }
    
    sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        cout << arr[i].start << " " << arr[i].end << '\n';
    }
    // int max = 0;
    // for (int i=0; i<n; i++){
    //     int start = arr[i].start;
    //     int end = arr[i].end;
    //     int cnt = 1;
    //     cout << "start : " << start << '\n';
    //     cout << "end : " << end << '\n';
    //     for (int j=i+1; j<n; j++){
    //         if (arr[j].end >= start){
    //             cout << arr[j].start << arr[j].end << '\n';
    //             cnt++;
    //             start = arr[j].start;
    //         }
    //     }
    //     cout << "cnt : " << cnt << '\n';
    //     if (max < cnt) max = cnt;
    //}
    //cout << max;
    int cnt = 1;
    int start = arr[0].start;
    int end = arr[0].end;
    for (int i=1; i<n; i++){
        if (arr[i].start >= end){
            cnt++;
            end = arr[i].end;
            start = arr[i].start;
        }
    }
    cout << cnt;
}