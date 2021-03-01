//
// Created by Daniel on 2021/3/1.
//

#ifndef PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
#define PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
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
}
#endif //PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
