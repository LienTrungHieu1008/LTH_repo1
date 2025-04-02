#include <iostream>
using namespace std;

int minLenSub(int a[], int n, int target) {
    int minLen = n + 1;  // Lấy độ dài dãy + 1 để kiểm tra ở cuối
    int sum = 0, l = 0;
    
    for (int r = 0; r < n; r++) {
        sum += a[r];

        // Khi tổng >= target, thu hẹp cửa sổ từ bên trái
        while (sum >= target) {
            if(r - l + 1 < minLen){
                minLen = r - l + 1;
            }
            sum -= a[l]; // Loại phần tử bên trái khỏi tổng
            l++;
        }
    }

    return (minLen == n + 1) ? 0 : minLen; // Trả về 0 nếu không tìm được
}

int main() {
    int n; 
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    cout << minLenSub(nums, n, target) << endl;
    return 0;
}
