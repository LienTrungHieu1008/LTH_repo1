#include <iostream>
using namespace std;

int linearSearchWithSentinel(int a[], int n, int k){
    int last = a[n - 1];// Lưu lại phần tử cuối mảng
    a[n - 1] = k;// Chèn key vào cuối mảng
    int i = 0;
    while(a[i] != k){
        i++;
    }
    a[n - 1] = last;
    if(i < n - 1 || a[n - 1] == k){//Kiểm lại với phần tử cuối của mảng ban đầu
        return i;
    }
    return -1;
}
int main(){
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    int f = linearSearchWithSentinel(a, n, k);
    if(f == n){
        cout << "Not found";
    }else{
        cout << f;
    }
    return 0;
}