#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int n1, n2;
int num1[MAX], num2[MAX];
int main() {
    cin >> n1;
    for (int i=0; i<n1; i++){
        cin >> num1[i];
    }
    cin >> n2;
    for (int i=0; i<n2; i++){
        cin >> num2[i];
    }
    
    sort(num1, num1+n1);

    for (int i=0; i<n2; i++){
        cout << upper_bound(num1, num1+n1, num2[i])- lower_bound(num1, num1+n1, num2[i]) << " ";
    }
}