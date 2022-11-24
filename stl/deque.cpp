#include<iostream>
#include<deque>
using namespace std;
int main()
{
deque<int> d;
d.push_back(10);
d.push_front(26);
d.push_front(30);
d.push_front(20);

cout<<endl;
cout<<"element at first index "<<d.at(1)<<endl;
cout<<d.size();
cout<<endl;
d.erase(d.begin(),d.begin()+2);
cout<<d.size();
}