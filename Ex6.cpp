#include <iostream>
using namespace std;

void findSumEle(int nums[], int n, int target){
    int l = 0, r = n - 1;// Sử dụng 3 chỉ số cho đầu và cuối mảng
    while(l < r){
        int sum = nums[l] + nums[r];
        if(sum == target){
            cout << "YES";
            return;
        }
        else if(sum > target){// Do mảng đã sắp xếp nên cần giảm r để giảm giá trị sum
            r--;
        }else{// Ngược lại với TH trêntrên
            l++;
        }
    }
    cout << "NO";
}
int main(){
    int n; cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target; cin >> target;
    findSumEle(nums, n, target);
    return 0;
}