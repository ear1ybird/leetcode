/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-03
    Description:写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。
    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int a=0,b=1,sum=0;
        for(int i=0;i<n;i++){
            sum=(a+b) %1000000007;
            a=b;
            b=sum;
        }

        return a;
    }
};