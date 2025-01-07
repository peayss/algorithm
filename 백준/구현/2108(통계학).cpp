#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int main(){
    int n;
    int arr[MAX];
    cin >> n;
    double total;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
    }
    sort(arr, arr+n);
    int count[MAX]; int max = -1; int max_idx = -1; int cnt = 0;
    for (int i=0; i<n; i++){
        count[i] = upper_bound(arr, arr+n, arr[i]) - lower_bound(arr, arr+n, arr[i]);
        if (count[i] > max) max = count[i];
    }
    for (int i=0; i<n; i++){
        if (cnt == 2) break;
        if (count[i] == max && arr[max_idx] != arr[i]){
            cnt++; 
            max_idx = i;
        }
    }
    double average = total/n;
    cout.precision(2);
    int first_answer = round(average);
    if (first_answer == -0) first_answer = 0;
    cout << first_answer << "\n";
    cout << arr[n/2] << "\n";
    cout << arr[max_idx] << "\n";
    cout << arr[n-1] - arr[0];
}

