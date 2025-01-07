#include <bits/stdc++.h>
using namespace std;

void print(int* check, int n){
    for (int i = 0; i < n; i++){
        cout << check[i];
    }
    cout << "\n";
}

void tryy(int* check, int n, int k){
    for (int i = 0; i <= 1; i++) {
        check[k] = i;
        if (k == n - 1){
            print(check, n);
        }
        else {
            tryy(check, n, k + 1);
        }
    }
}



int main() {
    int n = 5;
   
    int check[n] = {0};
    tryy(check, n, 0);
}