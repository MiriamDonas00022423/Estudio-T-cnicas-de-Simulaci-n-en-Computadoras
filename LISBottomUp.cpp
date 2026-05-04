#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> arr)
{

    int n = arr.size();
    // Solo de  una dimensión por lo que utilizo un vector
    vector<int> dp(n + 1, 1);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }

    return len;
}

int main()
{
    vector<int> arr{3, 10, 2, 1, 20};
    cout << LIS(arr) << endl;

    return 0;
}


