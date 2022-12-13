#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int x = 0, y = 0;
        for (char move : s) {
            if (move == 'L') {
                x--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            }
            if (x == 1 && y == 1) {
                std::cout << "YES" << std::endl;
                break;
            }
        }
        if (x != 1 || y != 1) {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}



