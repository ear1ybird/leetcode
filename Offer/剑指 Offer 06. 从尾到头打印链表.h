/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-02
    Description:输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> arr;
        ListNode* p=head;
        while (p!=NULL)
        {
            arr.push_back(p->val);
            p=p->next;
        }
        vector<int> ans;
        int i=0,j=arr.size()-1;
        while(i<arr.size()/2){
            int c=arr[j];
            arr[j]=arr[i];
            arr[i]=c;
            i++;j--;
        }
        return arr;
    }
};