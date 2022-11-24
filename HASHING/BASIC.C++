#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> m;

     //1st method
     pair<string,int>p1=make_pair("babbar",3);
     m.insert(p1);

     //second method
     pair<string,int>p2("babbari",2);
     m.insert(p2);

     //3rd mathod
     m["mera"]=1;
     m["mera"]=5;
   
   //searching
   cout<<m["mera"]<<endl;
   cout<<m.at("babbari")<<endl;

   //agar 26 line ko 25 se pehle likhe to error dega
   cout<<m["hi"]<<endl;//ye statement agr koi unknown entry hogi to usko by default vreate krke 0 de deta hai
   cout<<m.at("hi")<<endl;
//size
   cout<<m.size()<<endl;

    //to check present or  not
    cout<<m.count("yo")<<endl;  //count 0 dega agrr absent hai 1 dega agrr present hai
    cout<<m.count("babbar")<<endl;  //count 0 dega agrr absent hai 1 dega agrr present hai
      
      
       //erase
   m.erase("mera");
   cout<<m.size()<<endl;//size pehle 4 tha ab 3 ho gya
   

    return 0;
}
