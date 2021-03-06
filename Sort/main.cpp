#include "SelectionSortCase.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

// #include <algorithm>
// 老版本中 swap 在上面的库中
// 新版本在 std 中

using namespace std;

int main(){
    // 选择排序测试用例
    // SelectionSortCase();

    int n = 10000;

    // 对于近乎有序数组来说 插入排序要远远的比选择排序效率高
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr;
    delete[] arr2;
    return 0;
}