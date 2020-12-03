/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-03
    Description:请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表
    示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 
    9，则该函数输出 2。
    Algorithm:n&(n-1)把最右边的1变成0，然后计数。
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n!=0){
            sum++;
            n=n&(n-1);
        }
        return sum;
    }
};