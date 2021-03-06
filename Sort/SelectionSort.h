//
// Created by Daniel on 2021/3/6.
//

#ifndef PLAY_WITH_ALGORITHMS_SELECTIONSORT_H
#define PLAY_WITH_ALGORITHMS_SELECTIONSORT_H


#include <algorithm>

using namespace  std;

// 时间复杂度为 n^2
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
#endif //PLAY_WITH_ALGORITHMS_SELECTIONSORT_H
