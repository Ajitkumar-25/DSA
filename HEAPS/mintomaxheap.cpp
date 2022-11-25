#include <iostream>
using namespace std;

void maxheapify(int arr[], int i, int n)
{
    int largest = i;
    int lft = 2 * i + 1;
    int rt = 2 * i + 2;
    if (lft < n && arr[lft] > arr[largest])
        largest = lft;
    if (rt < n && arr[rt] > arr[largest])
        largest = rt;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, largest, n);
    }
}

void convertmintomax(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(arr, i, n);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Min Heap array : ";
    print(arr, N);

    convertmintomax(arr, N);

    cout << "\nMax Heap array : ";
    print(arr, N);

    return 0;
}
