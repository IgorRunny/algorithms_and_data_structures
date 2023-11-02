// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    int scale_of_notation = 10;

    std::vector<int> arr{};
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }
    std::vector<std::vector<int>> temp(scale_of_notation);

    int maxN = 0;

    for (int i = 0; i < n; i++) {
        int tmp = (std::to_string(arr[i])).length();
        if (maxN < tmp)
            maxN = (std::to_string(arr[i])).length();
    }

    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j < n; j++) {
            int digit = static_cast<int>(arr[j] / pow(scale_of_notation, i)) % scale_of_notation;

            temp[digit].push_back(arr[j]);
        }
        int num = 0;
        for (int k = 0; k < scale_of_notation; k++) {
            for (int l = 0; l < temp[k].size(); l++) {

                if (!temp[k].empty()) {
                    arr[num] = temp[k][l];
                    num++;
                }
            }
        }

        for (int i = 0; i < scale_of_notation; i++) {
            temp[i] = {};
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }
}

