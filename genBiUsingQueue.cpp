#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<string> binaryGen(int n)
{
    queue<string> q;
    vector<string> res;
    q.push("1");
    while(n--)
    {
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

int main(){
    vector<string> res = binaryGen(12);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}