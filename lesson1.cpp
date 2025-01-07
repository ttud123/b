#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> log;

public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int maxLog = log2(n) + 1;

        // Khởi tạo bảng log
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        // Khởi tạo Sparse Table
        st.assign(n, vector<int>(maxLog));
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = log[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> arr = {2, 4, 6, 1, 6, 8, 7, 3, 3, 5, 8, 9, 1, 2, 6, 4};
    SparseTable st(arr);

    // Các truy vấn
    cout << "Minimum from index 1 to 5: " << st.query(1, 5) << endl; // Output: 1
    cout << "Minimum from index 0 to 9: " << st.query(0, 9) << endl; // Output: 1
    cout << "Minimum from index 6 to 10: " << st.query(6, 10) << endl; // Output: 3

    return 0;
}
