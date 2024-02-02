#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr{};
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }

    int b = n / 2;

    while (b > 0)
    {
        for (int i = 0; i + b < arr.size(); i++) {
            for (int j = i; j >= 0 && arr[j] > arr[j + b]; j--) {
                std::swap(arr[j], arr[j + b]);
            }
        }
        b /= 2;
    }
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << "\n";
        }
    }
