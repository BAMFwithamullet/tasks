#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int left;
    int right;
};

int main () {
    int n;
    std::cin >> n;

    std::vector<Node> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i].left >> t[i].right;
    }

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int cur_v = q.front().first;
        int cur_h = q.front().second;
        q.pop();

        if (t[cur_v].left == -1 && t[cur_v].right == -1) {
            std::cout << cur_h << '\n';
            return 0;
        }

        if (t[cur_v].left != -1) q.push({t[cur_v].left, cur_h + 1});
        if (t[cur_v].right != -1) q.push({t[cur_v].right, cur_h + 1});

    }

}