//
// Created by Daniel on 2021/3/1.
//

#ifndef PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
#define PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

using namespace  std;

namespace SortTestHelper{

    // 生成有 N 个元素的随机数组，每个元素的随机范围为 [rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangR){

        assert(rangeL <= rangR);

        int *arr = new int[n];

        // 随机数种子
        srand(time(NULL));

        // 相对比较标准的随机数生成方法
        for (int i = 0; i < n; ++i) {
          arr[i] = rand() % (rangR - rangeL + 1) + rangeL;
        }

        return  arr;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }

    // 添加测试算法性能（时间）函数
    template<typename T>
    void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t start_time = clock();
        sort(arr, n);
        clock_t end_time = clock();
//        printArray(arr, n);
        assert(isSorted(arr, n));

        cout << sortName << " : " << double (end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;

    }

    int* copyIntArray(int a[], int n){
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}
#endif //PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
