#include <iostream>

// #include <algorithm>
// 老版本中 swap 在上面的库中
// 新版本在 std 中

using namespace std;
void selectionSort(int arr[], int n){
    for (int i = 0; i < n; ++i) {

        // 寻找 [i, n)区间内的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // 数据交换
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int a[10] = {10, 9,8,7,6,5,4,3,2,1};
    selectionSort(a, 10);

    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}