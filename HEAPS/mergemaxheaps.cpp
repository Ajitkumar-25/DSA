#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[leftchild] > arr[largest])
        largest = leftchild;
    if (rightchild < n && arr[rightchild] > arr[largest])
        largest = rightchild;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildheap(int arr[], int n)
{

    for (int i = n/2-1; i >=0; i--)
    {
        heapify(arr, n, i);
    }
}

void merge(int merged[], int arr1[], int arr2[], int m, int n)
{
    for (int i = 0; i < m; i++)
        merged[i] = arr1[i];
    for (int i = 0; i < n; i++)
        merged[i + m] = arr2[i];
    buildheap(merged, m + n);
}
void printheap(int arr[], int n)
{
    cout << "array representation of max heap is as follows : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int m;
    int n;
    int arr1[m], arr2[n];
    cout << "enter the size of 1st array: ";
    cin >> m;
    cout << "enter the elements of 1st array ";
    for (int i = 0; i < m; i++)
        cin >> arr1[i];
    cout << "enter the size of 2nd array: ";
    cin >> n;
    cout << "enter the elements of 2nd array ";
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    int merged[m + n];
    merge(merged, arr1, arr2, m, n);
    printheap(merged, m + n);
    return 0;
}