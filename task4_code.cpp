#include <iostream>
#include <string>
#include <vector>

const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;
const long long P1 = 31;
const long long P2 = 37;

struct Hasher {
    long long mod, p;
    std::vector<long long> h, pw;

    Hasher(const std::string& s, long long mod_, long long p_) : mod(mod_), p(p_) {
        int n = s.size();
        h.assign(n + 1, 0);
        pw.assign(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            long long c = s[i] - 'a' + 1;
            h[i + 1] = (h[i] * p + c) % mod;
            pw[i + 1] = (pw[i] * p) % mod;
        }
    }

    long long get(int l, int r) const {
        long long res = (h[r] - h[l - 1] * pw[r - l + 1]) % mod;
        if (res < 0) res += mod;
        return res;
    }
};

int main() {
  std::string s;
    std::cin >> s;

    Hasher hasher1(s, MOD1, P1);
    Hasher hasher2(s, MOD2, P2);

    int q;
    std::cin >> q;

    while (q--) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;

        if (r1 - l1 != r2 - l2) {
            std::cout << "No\n";
            continue;
        }

        if (hasher1.get(l1, r1) == hasher1.get(l2, r2) &&
            hasher2.get(l1, r1) == hasher2.get(l2, r2)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}
