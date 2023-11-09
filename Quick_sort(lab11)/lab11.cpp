
#include <iostream>
#include <vector>

void Qsort(std::vector<int>& arr, int begin, int end)
{
    int i = begin;
    int j = end;
    int mid_element = arr[(end + begin)/2];

    while (i <= j)
    {

        while (arr[i] < mid_element)
        {
            i++;
        }

        while (arr[j] > mid_element)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);

            i++;
            j--;
        }
    }

    if (i < end)
    {
        Qsort(arr, i, end);
    }

    if (j >= begin)
    {
        Qsort(arr, begin, j);
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

    Qsort(arr, 0, arr.size() - 1);

    for (int i = 0; i <= n; i++)
    {
        std::cout << arr[i] << "\n";
    }
}
