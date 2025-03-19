#include <iostream>
#include <string>
using namespace std;

void try(int n, string str)
{
    if (n == 0)
    {
        cout << str;
        return;
    }
    for (char c = '0'; c <= '1'; c++)
    {
        str += c;
        try(n - 1, str);
        str.pop_back();
    }
}
int main()
{
}