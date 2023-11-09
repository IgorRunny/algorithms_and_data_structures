
#include <iostream>
# include <vector>
void HeapBuild(std::vector<int>& arr, int lenght, int position)
{
    int main_positoin = position;
    int left_position = 2 * position + 1;
    int right_position = 2 * position + 2;

    if (left_position < lenght && arr[left_position] > arr[main_positoin])
    {
        main_positoin = left_position;
    }

    if (right_position < lenght && arr[right_position] > arr[main_positoin])
    {
        main_positoin = right_position;
    }

    if (main_positoin != position)
    {
        std::swap(arr[position], arr[main_positoin]);

        HeapBuild(arr, lenght, main_positoin);
    }

}

void HeapSort(std::vector<int>& arr, int lenght)
{
    for (int i = lenght / 2 - 1; i >= 0; i--)
    {
        HeapBuild(arr, lenght, i);
    }

    for (int i = lenght - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);

        HeapBuild(arr, i, 0);
    }
}

int main()
{
    std::vector<int> arr;
    int n;
    std::cin >> n;

    for (int i = 0; i <= n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }

    HeapSort(arr, n);

    for (int i = 0; i <= n; i++)
    {
        std::cout << arr[i] << "\n";
    }
}
