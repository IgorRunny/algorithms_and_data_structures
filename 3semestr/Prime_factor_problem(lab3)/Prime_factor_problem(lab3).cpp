#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> X = {};
    unsigned int x = INT_MAX;
    setlocale(LC_ALL, "ru");
    std::cout << "Hello World!\n";
    /*std::cout << "¬ведите число: ";
    std::cin >> x;*/
    int n3 = log(x) / log(3);
    int n5 = log(x) / log(5);
    int n7 = log(x) / log(7);
    for (int i = 0; i <= n3 + 1; i++)
    {
        for (int ii = 0; ii <= n5 + 1; ii++)
        {
            for (int iii = 0; iii <= n7 + 1; iii++)
            {
                int t = pow(3, i) * pow(5, ii) * pow(7, iii);
                if (t <= x)
                    X.push_back(t);
            }
        }
    }
    std::sort(begin(X), end(X));
    for (int i = 0; i < X.size(); i++)
    {
        std::cout << X[i] << "\n";
    }
}