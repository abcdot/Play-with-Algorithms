//
// Created by Daniel on 2021/3/6.
//

#ifndef PLAY_WITH_ALGORITHMS_SELECTIONSORTCASE_H
#define PLAY_WITH_ALGORITHMS_SELECTIONSORTCASE_H

#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"

void SelectionSortCase(){
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
    SortTestHelper::printArray(c, 4);

    // 自定义数据类型排序
    Student d[4] = {{"Leo", 90}, {"Daniel", 99}, {"Echo", 100}, {"Tracy", 99}};
    selectionSort(d, 4);
    for (int i = 0; i < 4; ++i) {
        cout << d[i];
    }
    cout << endl;

    // 使用 SortTestHelper 随机生成的数组
    int n = 1000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    selectionSort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 在 generateRandomArray 使用了 new 方法，需要 delete 释放
    // 使用
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    delete[] arr;
}

#endif //PLAY_WITH_ALGORITHMS_SELECTIONSORTCASE_H
