//sort 함수 필요없음!
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;

vector<int> arr;

int main()
{
    int n, sum = 0, req, max = 0, min = 0, mid, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        sum += a;

        if (a > max)
            max = a;
    }
    cin >> req;

    while (min <= max)
    {
        sum = 0; // 0으로 초기화!!
        mid = (min + max) / 2;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid)
                sum += arr[i];
            else
                sum += mid;
        }
        if (sum <= req)
        {
            result = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    cout << result;
}
