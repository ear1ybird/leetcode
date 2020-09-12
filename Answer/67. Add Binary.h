/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-12
    Description:给你两个二进制字符串，返回它们的和（用二进制表示）。
    输入为 非空 字符串且只包含数字 1 和 0。。
    Agorithm:简单
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int a_len = a.size();
        int b_len = b.size();

        if (a_len > b_len)
        {
            int m = a_len - b_len;
            while (m > 0)
            {
                b.insert(b.begin(), '0');
                m--;
            }
        }
        else
        {
            int m = b_len - a_len;
            while (m > 0)
            {
                a.insert(a.begin(), '0');
                m--;
            }
        }
        vector<char> ret;
        addBinaryHelper(a, b, a.size()-1, false, ret);

        string res;
        for (int i = 0; i < ret.size(); i++)
        {
            res += ret[i];
        }
        return res;
    }

    void addBinaryHelper(string &a, string &b, int i, bool carry, vector<char> &ret)
    {
        if (i < 0)
        {
            if(carry){
                ret.insert(ret.begin(),'1');
                return;
            }else{
                return;
            }
        }

        int x = (int)a[i]-48;
        int y = (int)b[i]-48;
        int z = 0;
        if (carry)
        {
            z = 1;
        }
        else
        {
            z = 0;
        }
        int sum = x + y + z;
        switch (sum)
        {
        case 0:
            ret.insert(ret.begin(), '0');
            addBinaryHelper(a, b, i - 1, false, ret);
            break;
        case 1:
            ret.insert(ret.begin(), '1');
            addBinaryHelper(a, b, i - 1, false, ret);
            break;
        case 2:
            ret.insert(ret.begin(), '0');
            addBinaryHelper(a, b, i - 1, true, ret);
            break;
        case 3:
            ret.insert(ret.begin(), '1');
            addBinaryHelper(a, b, i - 1, true, ret);
            break;
        default:
            break;
        }
    }
};