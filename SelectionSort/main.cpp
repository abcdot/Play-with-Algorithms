#include <iostream>
#include <string>
#include "Student.h"
// #include <algorithm>
// 老版本中 swap 在上面的库中
// 新版本在 std 中

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){
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

    // 整型排序
    int a[10] = {10, 9,8,7,6,5,4,3,2,1};
    selectionSort(a, 10);

    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 浮点型排序
    float b[10] = {10.1, 9.2,8.3,7.5,6.2,5.7,4.1,3.3,2.2,1.1};
    selectionSort(b, 10);

    for (int i = 0; i < 10; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    // 字符串排序
    string c[4] = {"D", "C", "B", "A"};
    selectionSort(c, 4);
    for (int i = 0; i < 4; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    // 自定义数据类型排序
    Student d[4] = {{"Leo", 90}, {"Daniel", 99}, {"Echo", 100}, {"Tracy", 99}};
    selectionSort(d, 4);
    for (int i = 0; i < 4; ++i) {
        cout << d[i];
    }
    cout << endl;
    return 0;
}