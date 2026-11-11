#include <iostream>
#include <vector>


int main() {
    int n;
    long long m, p;
    std::cin >> n >> p >> m;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<long long> pw(2*n+1);
    pw[0] = 1;
    for (int i = 1; i < 2*n; ++i) {
        pw[i] = (pw[i-1]*p) % m;
    } 

    std::vector<long long> pref(2*n+1, 0);
    for (int i = 0; i < n; ++i) {
        long long t_a = (a[i] * pw[2*i]) % m;
        pref[2*i+1] = (pref[2*i] + t_a) % m;
        long long t_b = (b[i] * pw[2*i+1]) % m;
        pref[2*i+2] = (pref[2*i+1] + t_b) % m;
    }

    std::cout << pref[2*n] << '\n';
}