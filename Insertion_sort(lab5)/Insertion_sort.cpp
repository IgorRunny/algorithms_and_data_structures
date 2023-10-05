#include <iostream>
#include <vector>
#include <random>

int main()
{
    std::vector<int> arr{};
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }
}
