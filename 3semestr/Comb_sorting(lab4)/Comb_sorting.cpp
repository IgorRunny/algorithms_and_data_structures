#include <iostream>
#include <vector>
#include <random>

int main()
{
    double factor = 1.247;
    std::vector<int> arr{};
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }

    double step = n;
    while (step > 1) {
        step /= factor;
        for (int i = 0; i + step < arr.size(); i++) {
            if (arr[i] > arr[i + step]) {
                std::swap(arr[i], arr[i + step]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }
}
