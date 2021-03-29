// DATE: 2021-03-27
// FILENAME: d.cpp
// AUTHOR: Yulin Shen (sylxjtu@outlook.com)
#include <bits/stdc++.h>
using namespace std;
constexpr long long md = 998244353;
constexpr long long maxn = 1e6 + 10;
// constexpr long long md = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

int t, n, q;
int cq;

int query(int x, int y, int z) {
    cq++;
    assert(cq <= q);
    printf("%d %d %d\n", x, y, z);
    fflush(stdout);
    int r; cin >> r; assert(r != -1); return r;
}

void solve() {
    cin >> t >> n >> q;
    while(t--) {
        cq = 0;
        int v = query(1, 2, 3);
        vector<int> ans;
        if(v == 1) {
            ans = vector<int>{2, 1, 3};
        } else if(v == 2) {
            ans = vector<int>{1, 2, 3};
        } else {
            ans = vector<int>{2, 3, 1};
        }
        vector<int> rnd;
        for(int i = 4; i <= n; i++) {
            rnd.push_back(i);
        }
        random_shuffle(rnd.begin(), rnd.end());
        for(auto i: rnd) {
            int l = 0, r = ans.size() + 1;
            while(true) {
                if(r - l == 1) {
                    ans.insert(ans.begin() + l, i);

                    break;
                }
                if(r - l == 2) {
                    if(l != 0) {
                        int val = query(ans[l - 1], ans[l], i);
                        assert(val != ans[l - 1]);
                        if(val == ans[l]) ans.insert(ans.begin() + l + 1, i);
                        else ans.insert(ans.begin() + l, i);
                    } else {
                        int val = query(ans[0], ans[1], i);
                        assert(val != ans[1]);
                        if(val == ans[0]) ans.insert(ans.begin(), i);
                        else ans.insert(ans.begin() + 1, i);
                    }

                    break;
                }
                if(r - l == 3) {
                    int val = query(ans[l], ans[l + 1], i);
                    if(val == ans[l]) ans.insert(ans.begin() + l, i);
                    else if(val == i) ans.insert(ans.begin() + l + 1, i);
                    else if(val == ans[l + 1]) ans.insert(ans.begin() + l + 2, i);
                    else assert(false);

                    break;
                }
                int mid1 = (l + l + r) / 3, mid2 = (l + r + r) / 3;
                int val = query(ans[mid1 - 1], ans[mid2 - 1], i);
                if(val == i) {
                    l = mid1;
                    r = mid2;
                } else if (val == ans[mid1 - 1]) {
                    r = mid1;
                } else {
                    l = mid2;
                }
            }
        }
        assert(ans.size() == n);
        for(int i = 0; i < n; i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
        fflush(stdout);
        int cv; cin >> cv; if(cv != 1) return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}

