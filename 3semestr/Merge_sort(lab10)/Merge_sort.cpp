
#include <iostream>
#include <vector>

void Merge_Sort(std::vector<int>& arr, int begin, int len) {
    if (len - begin < 2) {
        return;
    }
    if (len - begin == 2) {
        if (arr[begin] > arr[begin + 1]) {
            std::swap(arr[begin], arr[begin + 1]);
        }
        return;
    }
    Merge_Sort(arr, begin, begin + (len - begin) / 2);
    Merge_Sort(arr, begin + (len - begin) / 2, len);

    std::vector <int> temp;

    int begin1 = begin;
    int end1 = begin + (len - begin) / 2;
    int begin2 = end1;


    while (temp.size() < (len - begin)) {
        if ((begin1 >= end1) || ((begin2 < len) && (arr[begin2] < arr[begin1]))) {
            temp.push_back(arr[begin2]);
            ++begin2;
        }

        else {
            temp.push_back(arr[begin1]);
            ++begin1;
        }
    }

    for (int i = begin; i < len; i++) {
        arr[i] = temp[i - begin];
    }
}


int main()
{
    std::vector<int> arr{};
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::rand() % (n + 1));
    }

    Merge_Sort(arr, 0, arr.size());

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }
}

