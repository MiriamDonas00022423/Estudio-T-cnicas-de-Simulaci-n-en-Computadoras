#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void build_spf(vector<int> &spf, int N)
{

    for (int i = 1; i <= N; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorizar(int x, vector<int> &spf)
{
    vector<int> factors;
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x = x / spf[x];
    }

    return factors;
}

int main()
{

    int N, Q;
    cin >> N >> Q;
    vector<pair<vector<int>, int>> nums;

    vector<int> spf(N + 1);
    build_spf(spf, N);
    for (int x = 1; x <= N; x++)
    {
        vector<int> factors = factorizar(x, spf);
        nums.push_back({factors, x});
    }

    sort(nums.begin(), nums.end());

    while (Q--)
    {
        int K;
        cin >> K;
        cout << nums[K - 1].second << endl;
    }

    cout << endl;
}