/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-03
    Description:把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋
    转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 
    [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
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
    int minArray(vector<int>& numbers) {
        int min=numbers[0];
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]<min){
                return numbers[i];
            }
        }
        return min;
    }
};