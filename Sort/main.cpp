#include "SelectionSortCase.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"

// #include <algorithm>
// 老版本中 swap 在上面的库中
// 新版本在 std 中

using namespace std;

int main(){
    // 选择排序测试用例
    // SelectionSortCase();

    int n = 50000;

    // 对于近乎有序数组来说 插入排序要远远的比选择排序效率高
     int swapTimes = 0;
     int *arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
//    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);

    cout << "Test for Nearly Ordered Array, size = " << n << ", random range [0, " << n << "]" << endl;
    // 时间复杂度 n^2
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    // 时间复杂度 nlogn
    // 对近乎有序的数组会退化到 n^2
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}