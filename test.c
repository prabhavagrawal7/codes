#include <iostream>
#include <vector>
#include <cmath>

int getMinimumCost(std::vector<int> arr) {
    int cost = 0;
    int max_cost = 0;
    int f_index = 0, s_index = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        int first = arr[i];
        int second = arr[i + 1];
        if (std::abs(second - first) > max_cost) {
            max_cost = std::abs(second - first);
            f_index = i;
            s_index = i + 1;
        }
    }

    int mid = (arr[f_index] + arr[s_index]) / 2;
    cost += (arr[f_index] - mid) * (arr[f_index] - mid);
    cost += (arr[s_index] - mid) * (arr[s_index] - mid);

    for (int i = 0; i < arr.size() - 1; i++) {
        if (i == f_index) {
            continue;
        }
        int first = arr[i];
        int second = arr[i + 1];
        cost += (first - second) * (first - second);
    }

    return cost;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int result = getMinimumCost(arr);
    std::cout << "Minimum cost: " << result << std::endl;
    return 0;
}
