//
// Created by Daniel on 2021/3/6.
//

#ifndef PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
#define PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; ++i) {
        // 寻找元素 arr[i] 合适的插入位置
        // 第一种写法
//        for (int j = i; j > 0; j--) {
//            if (arr[j] < arr[j-1]){
//                swap(arr[j], arr[j-1]);
//            } else {
//                break;
//            }
//        }

        // 第二种写法
        // 插入排序可以提前终止内层循环
//        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
//            swap(arr[j], arr[j-1]);
//        }

        // 对使用 swap 优化
        T temp= arr[i];
        int j;
        for(j = i; j > 0 && temp < arr[j-1]; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}


// 对 arr[l...r] 范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r){
    for (int i = l+1; i <=r ; i++) {
        T e = arr[i];
        int k;
        // 问题出现在下一行 使用了 int k
        for (k = i; k > l && arr[k-1] > e ; k--) {
            arr[k] = arr[k-1];
        }
        arr[k] = e;
    }

    return;
}
#endif //PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
