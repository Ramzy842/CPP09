#include <cstdlib>
#include "PmergeMe.hpp"
#define MAX 100

bool isDup(int num, int arr[])
{
    for (int x = 0; !(arr[x] > 100 || arr[x] < 0); x++)
    {
        if (arr[x] == num)
            return true;
    }
    return false;
}

int getUniqueNumber(int arr[])
{
    int num = (rand() % (100 - 0 + 1));
    if (!isDup(num, arr))
        return num;
    else
        return getUniqueNumber(arr);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int n;
    int arr[MAX];
    std::cout << "Enter a number: ";
    std::cin >> n;
    for (int x = 0; x < n; x++)
    {
        int num = getUniqueNumber(arr);
        arr[x] = num;
    }
    for (int x = 0; x < n; x++)
    {
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;

    for (int x = 0; x < n; x++)
    {
        for (int y = x + 1; y < n; y++)
        {
            if (arr[y] < arr[x])
            {
                int temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;
    return 0;
}