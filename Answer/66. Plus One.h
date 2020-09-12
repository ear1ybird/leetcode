/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        plusOneHelper(digits,n);

        return digits;
    }

    void plusOneHelper(vector<int> &digits, int n)
    {
        if(n<0){
            digits.insert(digits.begin(),1);
            return;
        }
        if (digits[n] + 1 > 9){
            digits[n]=0;
            plusOneHelper(digits,n-1);
        }else{
            digits[n]++;
            return;
        }
    }
};