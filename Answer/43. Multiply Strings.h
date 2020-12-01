/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-01
    Description:给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的
        柱子，下雨之后能接多少雨水。
    Agorithm:遍历，分别找左边和右边的最大值，其中较小的是水的高度
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        return itoa(atoi(num1)*atoi(num2));
    }

    int atoi(string s){
        int ans=0;
        int m=1;
        for(int i=s.size()-1;i>=0;i--){
            ans+=(s[i]-'0')*m;
            m*=10;
        }
        return ans;
    }
    string itoa(int n){
        if(n==0){
            return "0";
        }

        string s;
        while(n!=0){
            int m=n%10;
            string tmp;
            tmp.push_back(m+'0');
            s=tmp+s;
            n/=10;
        }
        return s;
    }
};