#include <vector>
using namespace std;

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
