//
// Created by Daniel on 2021/3/6.
//

#ifndef PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
#define PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
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
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(arr[j], arr[j-1]);
        }
    }
}
#endif //PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
