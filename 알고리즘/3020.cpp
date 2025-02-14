#include <bits/stdc++.h>
using namespace std;

vector<int>arr;
vector<int>j; //종유석
vector<int>s; //석순
int j_count[10001]; //종유석 누적합
int s_count[10001]; //석순 누적합

int main(){
    int n,h;
    cin >> n >> h;
    for (int i=0; i<n; i++){
        int num; cin >> num;
        if (i%2==0) s.push_back(num);
        else j.push_back(num);
    }
    // sort(s.begin(), s.end());
    // sort(j.begin(), j.end());
    for (int i=0; i<s.size(); i++) cout << s[i] << " ";
    cout << '\n';
    for (int i=0; i<j.size(); i++) cout << j[i] << " ";

    


}




// int main(){
//     int n,h;
//     cin >> n >> h;
//     for (int i=0; i<n; i++){
//         int num; cin >> num;
//         if (i%2==1){
//             arr.push_back(num-h);
//             continue;
//         }
//         arr.push_back(num);
//     }
//     for (int i=0; i<n; i++) cout << arr[i] << " ";
//     cout << '\n';
//     int min = n+1; int cnt = 0; int min_count = 0;
//     for (int i=1; i<=h; i++){
//         cout << "i = " << i << " 일 때 -> ";
//         for (int j=0; j<n; j++){
//             if (arr[j] < 0) {
//                 if (i+arr[j] > 0) {
//                     cnt++;
//                     cout << "arr[j]<0 -> j: " << j << " cnt : " << cnt << '\n';
//                 }
//             }   
//             if (arr[j] >= i) {
//                 cnt++;
//                 cout << "j: " << j << " -> cnt : " << cnt << '\n';
//             }
//         }
//         if (min == cnt) min_count++;
//         if (min > cnt) {
//             min = cnt;
//             min_count = 0;
//             min_count++;
//         }
//         cnt = 0;
//         cout << "min: " << min << "\n";
//     }
//     cout << min << " " << min_count;
// }