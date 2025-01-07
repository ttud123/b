#include <bits/stdc++.h>
using namespace std;

int visited[30] = {0};
int d[30][30];
int X[30]; // Mang danh dau vi tri xe bus (de con nho diem truoc la diem lao con cong khoang cach chu)
int n = 0, k = 0, load = 0, dmin = INT_MAX;
int curr = 0, best = INT_MAX;
int check(int v)
{
    // 3TH can check:
    // + diem dang dung neu > n: visited -> false
    //                          : neu v - n (diem don) == false -> false (di tiep lun khach co can xuong dau)
    // + diem dang dung neu < n: load + 1 > k -> false (qua tai rui)
    if (visited[v] == true)
        return false;
    if (v > n)
    {
        if (visited[v - n] == false)
            return false;
    }
    else
    {
        if (load + 1 > k)
            return false;
    }
    return true;
}


void updateBest() {
    if (curr + d[X[2 * n]][0] < best) { 
        best = curr + d[X[2 * n]][0];
    }
}


void tryy(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            X[k] = v;
            curr += d[X[k - 1]][X[k]];
            visited[v] = true;
            if (v > n)
                load -= 1;
            else
                load += 1;
            if (k == 2 * n)
            {
                updateBest();
            }
            else
            {
                if ((curr + dmin * (2 * n +  1 - k)) < best)
                tryy(k + 1);
            }
            // hoan tra
            if (v > n)
                load += 1;
            else
                load -= 1;
            curr -= d[X[k - 1]][X[k]];
            visited[v] = false;
        }
    }
}

int main()
{
    X[0] = 0;
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if (d[i][j] < dmin && d[i][j] != 0) dmin = d[i][j];
        }
    }
    tryy(1);
    cout << best;
}