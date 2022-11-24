#include <iostream>
using namespace std;

void maxheapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxheapify(arr, n, largest);
    }
}
void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(arr, n, i);
    }
}
void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}
void printarray(int arr[], int n)
{
    cout << "Sorted order is : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cout << "Enter no of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    heapsort(arr, n);
    printarray(arr, n);
    return 0;
}