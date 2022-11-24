#include <iostream>
using namespace std;

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

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

    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
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
    int n;
    cout << "Enter the size of array :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    buildheap(arr, n);
    printheap(arr, n);
}