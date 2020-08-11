#include "1.Two Sum.h"
#include <iostream>

int main()
{
    Solution solution;
    vector<int> nums={4, 7, 2, 15};
    vector<int> result = solution.twoSum(nums, 9);
    
    for(int i:result){
        cout<<i<<endl;
    }

    return 0;
    //
}