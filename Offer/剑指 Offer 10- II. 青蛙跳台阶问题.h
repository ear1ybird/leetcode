/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-03
    Description:一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个
     n 级的台阶总共有多少种跳法
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
    int numWays(int n) {
        vector<int> array={1,1,2};

        for(int i=3;i<=n;i++){
            array.push_back((array[i-1]+array[i-2])%1000000007);
        }
        return array[n];
    }
};