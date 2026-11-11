#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_function(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    int m = t.size();

    std::string p = t + "#" + s;

    std::vector<int> z = z_function(p);

    int c = 0;
    int idx = m + 1;

    for (int i = idx; i < p.size(); ++i) {
        if (i + z[i] == p.size()) {
        int cur = std::min(z[i], m);
        if (cur > c) c = cur;
        }
    }

    std::cout << n + m - c << '\n';

}