#include <iostream>
using namespace std;

bool isSorted(int a[], int n){
    if(n == 1 || n ==0) return true;
    if(a[0] > a[1]) return false;
    return isSorted(a + 1, n - 1);
}
int main(){
    int a[] = {1, 3, 5, 6, 8};
    int n = sizeof(a) / sizeof(int);
    if(isSorted(a, n)){
        cout << "Sorted" << endl;
    }else{
        cout << "Not sorted" << endl;
    }
    return 0;
}