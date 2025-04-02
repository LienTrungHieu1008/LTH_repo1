// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int threeSum(int* nums, int n, int*** res) {
//     sort(nums, nums + n);
//     int maxRes = n * (n - 1) * (n - 2) / 6;// Tổ hợp chập 3
//     int** tmp = new int* [maxRes];
//     int resCnt = 0;
//     for(int i = 0; i < n - 2; i++) {
//         if(i > 0 && nums[i] == nums[i - 1]) {
//             continue; 
//         }
//         int j = i + 1;
//         int k = n - 1;
//         while(j < k) {
//             int total = nums[i] + nums[j] + nums[k];
//             if(total > 0) {
//                 k--;
//             } else if(total < 0) {
//                 j++;
//             } else {
//                 int* tri = new int [3];
//                 tri[0] = nums[i];
//                 tri[1] = nums[j];
//                 tri[2] = nums[k];
//                 tmp[resCnt++] = tri;
//                 j++;
//                 while(nums[j] == nums[j - 1] && j < k) {
//                     j++;
//                 }
//             }
//         }
//     } 
//     *res = new int*[resCnt];
//     for(int i = 0; i < resCnt; i++) {
//         (*res)[i] = tmp[i];
//     }
//     delete[] tmp;
    
//     return resCnt;
// }
// int main() {
//     int nums[] = {-1, 0, 1, 2, -1, -4};
//     int n = sizeof(nums) / sizeof(int);
//     int** res;
//     int cnt = threeSum(nums, n, &res);
//     cout << "[";
//     for(int i = 0; i < cnt; i++) {
//         cout << "[" << res[i][0] << ", " 
//              << res[i][1] << ", " 
//              << res[i][2] << "]";
//         if(i < cnt - 1) cout << ", ";
//     }
//     cout << "]" << endl;
//     for(int i = 0; i < cnt; i++) {
//         delete[] res[i];
//     }
//     delete[] res;
//     return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int threeSum(int nums[], int n, int res[MAX][3]) {
    sort(nums, nums + n); // Sắp xếp mảng
    int resCnt = 0;
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Bỏ qua phần tử trùng lặp của i không kể TH đầu của i
        int j = i + 1, k = n - 1;
        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) {
                k--;
            } else if (total < 0) {
                j++;
            } else {
                // Lưu kết quả
                if (resCnt < MAX) { 
                    res[resCnt][0] = nums[i];
                    res[resCnt][1] = nums[j];
                    res[resCnt][2] = nums[k];
                    resCnt++;
                }

                j++;
                while (j < k && nums[j] == nums[j - 1]) j++; // Bỏ qua phần tử trùng lặp của j
                // Không cần bỏ qua phần tử trùng lặp của k vì j đã chạy đến cuối
            }
        }
    }
    return resCnt;
}
int main() {
    int n; cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res[MAX][3]; 
    int cnt = threeSum(nums, n, res);
    cout << "[";
    for (int i = 0; i < cnt; i++) {
        cout << "[" << res[i][0] << ", " 
             << res[i][1] << ", " 
             << res[i][2] << "]";
        if (i < cnt - 1) cout << ", ";//Sửa dúng định dạng
    }
    cout << "]" << endl;

    return 0;
}
