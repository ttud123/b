#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input n (rows) and m (columns)
    int n, m;
    cin >> n >> m;

    // Input the table and prepare prefix sum array
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // Compute prefix sum
            prefixSum[i][j] = a[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    // Input number of queries
    int Q;
    cin >> Q;

    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // Calculate sum of sub-table using prefix sum
        int result = prefixSum[r2][c2] 
                   - prefixSum[r1 - 1][c2] 
                   - prefixSum[r2][c1 - 1] 
                   + prefixSum[r1 - 1][c1 - 1];

        cout << result << endl;
    }

    return 0;
}
