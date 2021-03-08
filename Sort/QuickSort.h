//
// Created by Daniel on 2021/3/8.
//

#ifndef PLAY_WITH_ALGORITHMS_QUICKSORT_H
#define PLAY_WITH_ALGORITHMS_QUICKSORT_H

#include <algorithm>
#include "InsertionSort.h"

// 对 arr[l...r] 部分进行 partition 操作
// 返回 p，使得 arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){

    // 重点优化二：
    swap(arr[rand() % (r-l+1)+l], arr[l]);
    T v = arr[l];

    // arr[l+1...j] < v; arr[j+1...i] > v
    int j = l;
    for (int i = l + 1; i <= r ; i++) {
        if(arr[i] < v) {
            swap(arr[j+1], arr[i]);
            j++;
        }
    }

    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr, int l, int r){
//    if(l >= r)
//        return;

    // 优化一：
    if(r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, p+1, r);
    __quickSort(arr, l, p - 1);
}

template<typename T>
void quickSort(T arr[], int n){
    // 重点优化二：
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}


// 优化三：二路快速排序
template<typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[rand() % (r-l+1)+l], arr[l]);
    T v = arr[l];

    // arr[l+1...i) <= v; arr(j...r] >= v
    int i=l+1, j=r;
    while (true){
        while (i <=r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if(i > j) break;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    swap(arr[l], arr[j]);

    return j;
}

template<typename T>
void __quickSort2(T arr, int l, int r){
//    if(l >= r)
//        return;

    // 优化一：
    if(r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, p+1, r);
    __quickSort2(arr, l, p - 1);
}

template<typename T>
void quickSort2(T arr[], int n){
    // 重点优化二：
    srand(time(NULL));
    __quickSort2(arr, 0, n - 1);
}


// 优化四： 三路快排
template<typename T>
void __quickSort3(T arr[], int l, int r){
//    if(l >= r)
//        return;

    // 优化一：
    if(r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    // partition
    swap(arr[rand() % (r-l+1)+l], arr[l]);
    T v = arr[l];

    int lt = l;  // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1;  // arr[lt+1...i] == v

    while (i < gt){
        if(arr[i] < v){
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            gt--;
        } else { // arr[i] == v
            i++;
        }
    }

    swap(arr[l], arr[lt]);

    __quickSort3(arr, l, lt-1);
    __quickSort3(arr, gt, r);

}

template<typename T>
void quickSort3(T arr[], int n){
    // 重点优化二：
    srand(time(NULL));
    __quickSort3(arr, 0, n - 1);
}
#endif //PLAY_WITH_ALGORITHMS_QUICKSORT_H
