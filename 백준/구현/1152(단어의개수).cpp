#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int count = 1;
    // cin >> a;
    getline(cin, a);
    if (a[0] == ' '){
        count = 0;
    }
    int l = a.length();
    for (int i=0; i<l; i++){
        if (a[i] == ' ' && i != l-1)
            count++;
    }
    cout << count;
}