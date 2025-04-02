#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int k){
    for(int i = 0; i < n; i++){
        if(a[i] == k){//Kiểm tra nếu đúng key trả về idx
            return i;
        }
    }
    return -1;
}
int main(){
    int n, k; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    cout << linearSearch(a, n, k);
}