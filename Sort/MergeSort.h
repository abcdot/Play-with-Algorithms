//
// Created by Daniel on 2021/3/6.
//

#ifndef PLAY_WITH_ALGORITHMS_MERGESORT_H
#define PLAY_WITH_ALGORITHMS_MERGESORT_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;

// 将 arr[l...mid] 和 arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r){
    T temp[r-l+1];
    for(int i=l; i<=r; i++){
        temp[i-l] = arr[i];
    }

    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++){

        // 先判断索引的合法性，再进行其他判断
        if(i > mid){
            arr[k] = temp[j-l];
            j++;
        } else if (j > r){
            arr[k] = temp[i-l];
            i++;
        } else if(temp[i-l] < temp[j-l]){
            arr[k] = temp[i-l];
            i++;
        } else {
            arr[k] = temp[j-l];
            j++;
        }
    }
}

// 使用递归实现归并排序， 对 arr[l....r] 的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r){

//        if(l >= r)
//            return;

    // 优化二：
    if(r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    // 坑：l&r 是非常大的数时有可能溢出
    int mid = (l+r)/2;

    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);

    // 优化一：
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}
// 时间复杂度 nlogn
template<typename T>
void mergeSort(T arr[], int n){
    __mergeSort( arr, 0, n-1);
}


// 自底向上归并
template<typename T>
void mergeSortBU(T arr[], int n){
    for (int i = 1; i <=n ; i+=i) {
        for (int j = 0; j + i < n; j += i + i) {

            // 对 arr[j...j + i - 1] 和 arr[j + i... j + 2 * i - 1] 进行归并
            __merge(arr, j , j + i - 1, min(j + i + i - 1, n -1 ));
        }
    }
}

#endif //PLAY_WITH_ALGORITHMS_MERGESORT_H
