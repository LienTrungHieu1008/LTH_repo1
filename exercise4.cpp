#include<iostream>
using namespace std;
void move(char from, char to){
    cout << from << "->" << to << endl;
}
void tower(int n, char from, char to, char tmp){
    if(n == 1){
        move(from, to);
        return;
    }
    tower(n - 1, from, tmp, to);
    move(from, to);
    tower(n - 1, tmp, to, from);
}
int main(){
    int n; cin >> n;
    tower(n, 'A', 'B', 'C');
    return 0;
}