#include <iostream>
#include <string>
using namespace std;

void generate(int n, string str){
    if(str.length() == n){
        cout << str << endl;
        return;
    }
    generate(n, str + '0');
    generate(n, str + '1');
}
int main()
{
    int n; cin >> n;
    generate(n, "");
    return 0;
}