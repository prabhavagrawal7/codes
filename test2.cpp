#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
std::vector<T> operator+(std::vector<T> A, std::vector<T> B)
{
    std::vector<T> ans;

    if (A.size() != B.size())
    {
        throw std::invalid_argument("Vector sizes must match");
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        ans.push_back(A[i] + B[i]);
    }

    return ans;
}

int main()
{
    std::vector<int> lps = {1, 2, 3, 4};
    std::vector<int> additionalVector = {5, 6, 7, 8};

    std::vector<int> result = lps + additionalVector;

    for (int val : result)
    {
        std::cout << val << " ";
    }

    return 0;
}
