/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-13
    Description:给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行
    反转。
    Agorithm:判断溢出
**************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if(x==0){
            return 0;
        }
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            //判断溢出
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};