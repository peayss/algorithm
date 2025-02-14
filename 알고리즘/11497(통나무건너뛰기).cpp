// 난이도는 가장 높은 통나무에 따라 정해짐
#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int temp[10001];
vector<int>res;

int main(){
    int t,n,l;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        for (int j=0; j<n; j++){
            int num; cin >> num;
            arr[j] = num;
        }
        sort(arr,arr+n);
        int e = 0, o = n-1;
        for (int z=0; z<n; z++){
            // 번갈아가면서 대입
            if (z%2==0){
                temp[e++] = arr[z];
            } else temp[o--] = arr[z];
        }
        int max = -1;
        for (int a=0; a<n-1; a++){
            if (abs(temp[a]-temp[a+1]) > max) max = abs(temp[a]-temp[a+1]);
        }
        res.push_back(max);
        memset(arr,0,sizeof(arr));
        memset(temp,0,sizeof(temp));
    }
    for (int i=0; i<t; i++){
        cout << res[i] << '\n';
    }
}


// int main(){
//     int t,n,l;
//     cin >> t;
//     for (int i=0; i<t; i++){
//         cin >> n;
//         for (int j=0; j<n; j++){
//             int num; cin >> num;
//             arr[j] = num;
//         }
//         sort(arr,arr+n);
//         res.push_back(arr[n-1]-arr[n-3]);
//         memset(arr,0,sizeof(arr));
//     }
//     for (int i=0; i<t; i++){
//         cout << res[i] << '\n';
//     }
// }