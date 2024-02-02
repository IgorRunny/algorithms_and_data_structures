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

    for (int i = 0; i < n - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_i])
            {
                min_i = j;
            }
        }
        if (min_i != i)
        {
            std::swap(arr[i], arr[min_i]);
        }

    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }
}
