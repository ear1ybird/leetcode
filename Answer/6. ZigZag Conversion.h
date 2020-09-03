/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-08-13
    Description:将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形
    排列。
    Agorithm:双指针
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        
        vector<string> line(numRows);
        int i=0,j=0;
        bool i_flag=true;
        int m=0;
        int len=s.length();
        while (m<len)
        {
            line[i].push_back(s[m]);
            m++;
            
            if(i==numRows-1){
                i_flag=false;
            }else if(i==0){
                i_flag=true;
            }

            if(i_flag==true){
                i++;
            }else if(i_flag==false){
                i--;
                j++;
            }
        }
        string res;
        for(int i=0;i<line.size();++i){
            res+=line[i];
        }
        return res;
    }
};