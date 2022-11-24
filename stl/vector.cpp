#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> v;

   vector<int> a(5,1);

   
   cout<<"print "<<endl;
for(int i:a)
{
    cout<<i<<" ";
}
cout<<endl;
   cout<<"capacity "<<v.capacity()<<endl;
   
   v.push_back(8);
    cout<<"capacity "<<v.capacity()<<endl;
      v.push_back(10);
    cout<<"capacity "<<v.capacity()<<endl;
      v.push_back(45);
    cout<<"capacity "<<v.capacity()<<endl;
    cout<<"size "<<v.size()<<endl;
    cout<<"First "<<v.front()<<endl;
    cout<<"Last "<<v.back()<<endl;

cout<<"befor pop"<<endl;
for(int i:v)
{
    cout<<i<<" ";
}
cout<<endl;
v.pop_back();
cout<<"after pop"<<endl;
for(int i:v)
{
    cout<<i<<" ";
}
cout<<v.size()<<" "<<v.capacity()<<endl;
v.clear();
cout<<v.size()<<" "<<v.capacity()<<endl;

}