// DATE: 2020-10-18
// FILENAME: a.cpp
// AUTHOR: Yulin Shen
#include <bits/stdc++.h>
using namespace std;
constexpr long long md = 998244353;

int main() {
    int ka; cin >> ka;
    for(int k = 1; k <= ka; k++) {
        cout << "Case #" << k << ": ";
        string s; cin >> s;
        vector<int> ss, es;
        for(int i = 0; i + 4 <= s.size(); i++) {
            if(s.substr(i, 4) == "KICK") ss.push_back(i);
        }
        for(int i = 0; i + 5 <= s.size(); i++) {
            if(s.substr(i, 5) == "START") es.push_back(i);
        }
        sort(ss.begin(), ss.end());
        sort(es.begin(), es.end());
        long long cnt = 0;
        for(auto i: ss) {
            cnt += es.end() - lower_bound(es.begin(), es.end(), i);
        }
        cout << cnt << '\n';
    }
}
