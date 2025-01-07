#include <bits/stdc++.h>
using namespace std;
// cho mot tam kim loai w * h
// cho n la so tam kim loai can cat ra
// => check xem co cat duoc khong
// noi chung gio cu thu vao tat ca cac cho co the dat, backtrack ma, no nhu kieu vet can vjp
// k chay tu 0 de dem so mieng thui
int k, h, w, n;
int W[11], H[11];
int mark[11][11] = {0};

void success()
{
    cout << "1";
    exit(0);
}

void doMark(int vx, int vy, int v0, int k, int value)
{
    int wk = W[k], hk = H[k];
    if (v0 == 1)
    {
        wk = H[k];
        hk = W[k];
    }
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            mark[i][j] = value;
        }
    }
}

bool check(int vx, int vy, int v0, int k)
{
    int wk = W[k], hk = H[k];
    if (v0 == 1)
    {
        wk = H[k];
        hk = W[k];
    }
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            if (mark[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void tryy(int k)
{
    // v0 se dai dien cho co quay 90 do hay khum
    for (int v0 = 0; v0 <= 1; v0++)
    {
        int wk = W[k], hk = H[k];
        if (v0 == 1)
        {
            wk = H[k];
            hk = W[k];
        }
        for (int vx = 0; vx <= w - wk; vx++)
        {
            for (int vy = 0; vy <= h - hk; vy++)
            {
                if (check(vx, vy, v0, k))
                {
                    doMark(vx, vy, v0, k, 1);
                    if (k == n - 1)
                    {
                        success();
                    }
                    else
                        tryy(k + 1);
                    doMark(vx, vy, v0, k, 0);
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            mark[i][j] = 0;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> H[i] >> W[i];
    }
    tryy(0);
    cout << "0";
}