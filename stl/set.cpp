#include<iostream>
#include<set>
using namespace std;
int main()
{ set<int>s;
s.insert(15);
s.insert(6);
s.insert(25);
s.insert(1);
for(auto x:s)
cout<<x<<" ";
    return 0;
}