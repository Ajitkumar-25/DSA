#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
            pq.push(arr[i]);
        for (int i = k; i <=r; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};

int main()
{
    int n;
    cout << "enter size : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter the value of k : ";
    cin >> k;
    Solution obj;
    cout << obj.kthSmallest(arr, 0, n - 1, k);
    return 0;
}