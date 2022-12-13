#include <iostream>
#include <deque>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::deque<char> dq;
        char c;
        for (int i = 0; i < n; i++) {
            std::cin >> c;
            dq.push_back(c);
        }
        while (dq.size() > 1 && (dq.front() == '0' && dq.back() == '1' || dq.front() == '1' && dq.back() == '0')) {
            dq.pop_front();
            dq.pop_back();
        }
        std::cout << dq.size() << std::endl;
    }
    return 0;
}