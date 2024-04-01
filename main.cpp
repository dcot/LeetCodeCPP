#include <bits/stdc++.h>
#include "lc994.h"
using namespace std;
void func(vector<int>& z) {
    cout << &z;
    cout << z[0];
}
int main() {
    auto p = make_unique<lc994>();
    vector<vector<int>> v = {{1,2}};
    int cnt = p->orangesRotting(v);
    cout<<cnt;
    return 0;
}




