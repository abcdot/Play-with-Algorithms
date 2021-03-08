//
// Created by Daniel on 2021/3/8.
//

#ifndef PLAY_WITH_ALGORITHMS_QUICKSORT_H
#define PLAY_WITH_ALGORITHMS_QUICKSORT_H

// 对 arr[l...r] 部分进行 partition 操作
// 返回 p，使得 arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){
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
    if(l >= r)
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, p+1, r);
    __quickSort(arr, l, p - 1);
}

template<typename T>
void quickSort(T arr[], int n){
    __quickSort(arr, 0, n - 1);
}
#endif //PLAY_WITH_ALGORITHMS_QUICKSORT_H
