#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    int maxLog = log2(n);
    vector<vector<int>> st(n, vector<int>(maxLog, 0));
    for (int i = 0; i < n; i++)
    {
        st[i][0] = arr[i];
    }
    for (int j = 1; j <= maxLog; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int res = 0;
    int q = 0;
    int sum = 0;
    cin >> q;

    for (int l = 0; l < q; l++)
    {
        int L, R;
        cin >> L >> R;
        int j = ceil(log(R - L + 1));
        sum += min(st[L][j], st[R - (1 << j) + 1][j]);
    }
    cout << sum;
    // for (int j = 1; j <= maxLog; j++)
    // {
    //     cout << j << ": ";
    //     for (int i = 0; i + (1 << j) <= n; i++)
    //     {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
