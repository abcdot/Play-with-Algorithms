#include "SelectionSortCase.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

// #include <algorithm>
// 老版本中 swap 在上面的库中
// 新版本在 std 中

using namespace std;

int main(){
    // 选择排序测试用例
    // SelectionSortCase();

    int n = 1000000;

    // 对于近乎有序数组来说 插入排序要远远的比选择排序效率高
     int swapTimes = 10;
    // 测试1 一般性测试
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // 测试2 测试近乎有序的数组
//     int *arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    // 测试3 测试存在包含大量相同元素的数组
//    int *arr = SortTestHelper::generateRandomArray(n, 0, 10);


    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);

    cout << "Test for Nearly Ordered Array, size = " << n << ", random range [0, " << n << "]" << endl;
    // 时间复杂度 n^2
//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
//    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    // 时间复杂度 nlogn
    // 对近乎有序的数组会退化到 n^2
    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
//    SortTestHelper::testSort("Merge Sort BU", mergeSortBU, arr4, n);


    // 快排
//    SortTestHelper::testSort("Quick Sort", quickSort, arr4, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);
    // 应用： merge sort 取逆序对 nlogn
    // quick sort 取第 n 大的数 n

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;


    return 0;
}