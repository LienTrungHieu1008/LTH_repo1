#include <iostream>
#include <vector>
using namespace std;

int shipWithInDay(int weights[], int n, int days){
    int min_cap = 0, max_cap = 0;
    // Tìm sức chứa tối thiểu và tối đa
    for(int i = 0; i < n; i++){
        if(weights[i] > min_cap) min_cap = weights[i];
        max_cap += weights[i];
    }
    // Tìm kiếm nhị phân
    while(min_cap <= max_cap){
        int m = min_cap + (max_cap - min_cap) / 2;
        int cur_weight = 0;
        int cur_day = 1;
        for(int i = 0; i < n; i++){
            if(cur_weight + weights[i] <= m){//Vẫn đủ để chở
                cur_weight += weights[i];
            }else{// Không còn đủ nên tăng ngày lên
                cur_day++;
                cur_weight = weights[i];
            }
        }
        if(cur_day <= days){// Nếu ngày đã bằng ngày yêu cầu nhưng cần tìm sức chứa nhỏ nhất nên vẫn tiếp tục hạ max_cap
            max_cap = m - 1;
        }else{
            min_cap = m + 1;
        }
    }
    return min_cap;// Dừng lại khi min_cap > max_cap nên lúc đó min_cap là đáp án cần tìm
}
int main(){
    int n; cin >> n;
    int weights[n];
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    int days; cin >> days;
    cout << shipWithInDay(weights, n, days);
    return 0;
}