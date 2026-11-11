#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> z_function(const std::string& s) {
  int n = s.size();
  std::vector<int> z(n, 0);

  int l = 0;
  int r = 0;

  for (int i = 1; i < n; i++) {
    if (i <= r) {
      z[i] = std::min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }

    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  std::string s, p;
    std::cin >> s >> p;

    int lenP = (int)p.size();
    int lenS = (int)s.size();

    std::string t = p + "#" + s;

    std::vector<int> z = z_function(t);

    long long full = 0;   
    long long minus1 = 0;  
    long long minus2 = 0; 

    for (int i = lenP + 1; i < (int)t.size(); ++i) {
        int common = z[i];
        if (common >= lenP) {
            ++full;
        }
        if (common >= lenP - 1) {
            ++minus1;
        }
        if (common >= lenP - 2) {
            ++minus2;
        }
    }

    std::cout << full << ' ' << minus1 << ' ' << minus2 << '\n';

    return 0;
}
