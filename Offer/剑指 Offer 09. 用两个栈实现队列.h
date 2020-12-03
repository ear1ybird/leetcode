/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-03
    Description:用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 
    appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的
    功能。(若队列中没有元素，deleteHead 操作返回 -1 )

    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> s1,s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        while(s2.empty()==false){
            s1.push(s2.top());
            s2.pop();
        }

        s1.push(value);
        while(s1.empty()==false){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int deleteHead() {
        if(s2.empty()){
            return -1;
        }
        int m=s2.top();
        s2.pop();
        return m;
    }
};