//
// Created by Admine on 2022/9/3.
//题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//
//程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。

#include <stdio.h>

int main() {
    int i, j, k;
    // 3-layer circulation
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            for (k = 1; k < 5; k++) {
                // Make the i,j,k identicial with each other
                if ((i != j) && (i != k) && (j != k))
                    printf("%d,%d,%d\n", i, j, k);
            }

        }
    }
    return 0;
}
