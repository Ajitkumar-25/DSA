#include <iostream>
using namespace std;
int fun1ton(int n)
{
    if (n == 0)
        return 0;

    else
        cout << n;
    fun1ton(n - 1);
}

int funcnto1(int n)
{
    if (n <= 0)
        return 0;
    else
        funcnto1(n - 1);
    cout << n;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}
int pallindrome(string s)
{
    if (s.length() == 0)
        return 1;
    else
    {
        if (s[0] == s[s.length() - 1])
        {
            return pallindrome(s.substr(1, s.length() - 2));
        }
        else
            return 0;
    }
}

int getsum(int n)
{
    if (n == 0)
        return 0;
    else
        return n % 10 + getsum(n / 10);
}

void subset(string s)
{
    if (s.length() == 0)
        return;
    else
    {
        cout << s << endl;
        subset(s.substr(1));
    }
}
void towerofhanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    else
    {
        towerofhanoi(n - 1, a, c, b);
        cout << "move from " << a << " to " << c << endl;
        towerofhanoi(n - 1, b, a, c);
    }
}
int main()
{
    fun1ton(7);
    cout << endl;
    funcnto1(7);
    cout << endl;
    cout << fact(5);
    cout << endl;
    cout << fibonacci(5);
    cout << endl;
    cout << sum(5);
    cout << endl;
    string s = "abbba";
    cout << pallindrome(s);
    cout << endl;
    cout << getsum(234);
    cout << endl;
    subset("abc");
    char a = 'A', b = 'B', c = 'C';
    towerofhanoi(2, a, b, c);
}