/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-02
    Description:在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
    每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数
    组和一个整数，判断数组中是否含有该整数。
    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};