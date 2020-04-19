#include <bits/stdc++.h>
using namespace std;

int w, h, l, u, r, d;
double facts[200010];
int fact_digits[200010];

void init() {
    facts[0] = facts[1] = 1;
    for(int i = 2; i < 200010; i++) {
        facts[i] = facts[i - 1] * i;
        fact_digits[i] = fact_digits[i - 1];
        while(facts[i] >= 2) {
            facts[i] /= 2;
            fact_digits[i]++;
        }
    }
}

const int DIGIT = 64;

pair<double, int> comb(int x, int y) {
    // x! / y! / (x - y)!;
    double ret = facts[x], rd = fact_digits[x];
    ret /= facts[y]; rd -= fact_digits[y];
    ret /= facts[x - y]; rd -= fact_digits[x - y];
    while(ret <= 0.5) {
        rd--;
        ret *= 2;
    }
    return make_pair(ret, rd);
}

pair<double, int> add_num(pair<double, int>& p1, pair<double, int>& p2) {
    if(p1.first == 0) return p2;
    if(p2.first == 0) return p1;
    if(p2.second - p1.second > DIGIT) {
        return p2;
    } else if(p1.second - p2.second > DIGIT) {
        return p1;
    } else {
        while(p1.second < p2.second) {
            p1.second++;
            p1.first /= 2;
        }
        while(p2.second < p1.second) {
            p2.second++;
            p2.first /= 2;
        }
        return make_pair(p1.first + p2.first, p1.second);
    }
}

pair<double, int> posp(int x, int y) {
    pair<double, int> p{0, 0};
    if(x == w) {
        p.first = 1;
        p.second = - (x - 1);
        for(int j = 2; j <= y; j++) {
            auto tp = posp(x - 1, j);
            tp.second--;
            p = add_num(p, tp);
        }
        return p;
    }
    if(y == h) {
        p.first = 1;
        p.second = - (y - 1);
        for(int j = 2; j <= x; j++) {
            auto tp = posp(j, y - 1);
            tp.second--;
            p = add_num(p, tp);
        }
        return p;
    }
    // number of equal p paths
    auto tp = comb(x + y - 2, x - 1);
    tp.second -= x + y - 2;
    return tp;
}

double solve() {
    if(w == 1 || h == 1) return 0;
    double tpv = 0;
    int tpd = 0;
    if(u > 1) {
        for(int i = l; i <= r; i++) {
            auto tp = posp(i, u - 1);
            if(i != w) tp.second--;
            if(tp.second - tpd > DIGIT) {
                tpv = tp.first;
                tpd = tp.second;
            } else if(tpd - tp.second > DIGIT) {
                continue;
            } else {
                while(tpd < tp.second) {
                    tpd++;
                    tpv /= 2;
                }
                while(tp.second < tpd) {
                    tp.second++;
                    tp.first /= 2;
                }
                tpv += tp.first;
            }
        }
    }
    if(l > 1) {
        for(int i = u; i <= d; i++) {
            auto tp = posp(l - 1, i);
            if(i != h) tp.second--;
            if(tp.second - tpd > DIGIT) {
                tpv = tp.first;
                tpd = tp.second;
            } else if(tpd - tp.second > DIGIT) {
                continue;
            } else {
                while(tpd < tp.second) {
                    tpd++;
                    tpv /= 2;
                }
                while(tp.second < tpd) {
                    tp.second++;
                    tp.first /= 2;
                }
                tpv += tp.first;
            }
        }
    }

    while(tpd > 0) {
        tpv *= 2;
        tpd--;
    }
    while(tpd < 0) {
        tpv /= 2;
        tpd++;
    }
    return 1 - tpv;
}

int main() {
    init();

    int T; cin >> T;
    for(int ka = 0; ka < T; ka++) {
        cin >> w >> h >> l >> u >> r >> d;
        printf("Case #%d: %.10lf\n", ka + 1, solve());
    }
}
