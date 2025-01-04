#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <bits/stdc++.h>
using namespace std;

void solution();

int n;
int visited[10];
int a[10];
int b[10];

bool check(int i){
    return !visited[i];
}

void Try(int k){
    for (int i = 1; i <= n; i++){
        if (check(i)){
            visited[i] = true;
            b[k] = a[i];

            if (k == n){
                for (int j = 1; j <= n; j++) cout << b[j] << " ";
                cout << endl;
            } else Try(k + 1);

            visited[i] = false;
        }
    }
}

int main(){
    for(int i = 1; i <= n; i++){
    }

    solution();
}


























void solution(){
	std::string u;
    std::string x;

    while (std::getline(std::cin, x)) {
        if (x == "end") {
            break;
        }
        u += x + "\n";
    }

    std::string eo = "D:\\Untitlled2.exe \"" + u + "\"";
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(eo.c_str(), "w"), pclose);

    fputs(u.c_str(), pipe.get());
    fflush(pipe.get());
}
