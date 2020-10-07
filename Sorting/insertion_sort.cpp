#include <vector>
using namespace std;

/* 
if data size <= 100, useful
example : std::sort();
*/

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}

template <typename T>
void insertionSort(T *arr, T *end)
{
    int left = arr;
    int right = (end - 1 - arr); 
    for (int i = left + 1; i < right; ++i)
    {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}
