#include <iostream>
#include <queue>
using namespace std;
int main()
{ // it will make min heap as default
    priority_queue<int, vector<int>, greater<int>> pq;
    // it will make max heap as default
    // priority_queue<int>pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size() << " ";
    cout << pq.top() << " ";
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
