#include <iostream>
#include <queue>
#define MAX 5000

using namespace std;

int main (){
    queue<int> q;
    int res[MAX];
    int n, k;
    int l=0;
    int count = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    
    while (!q.empty()){
        for (int i = 1; i < k; i++)
        {
            int y = q.front(); q.pop();
            q.push(y);
        }
        res[l++] = q.front();
        q.pop();
    }

    cout << "<";

    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
            cout << res[i];
        else
            cout << res[i] << ", ";
    }
    cout << ">";
}
