/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-05
    Description:给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
    Agorithm:
        Solution 两次遍历
        Solution1 一次遍历，双指针法
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        ListNode *tmp = head;
        while (tmp->next != NULL)
        {
            len++;
            tmp = tmp->next;
        }
        len++;
        if (len == 1 && n == 1)
        {
            delete (head);
            return NULL;
        }
        ListNode *cur = head;
        ListNode *pre = cur;
        int index = len - n;
        for (int i = 0; i < index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        if (index == 0)
        {
            head = pre->next;
        }
        else
        {
            pre->next = cur->next;
        }
        delete (cur);
        return head;
    }
};

class Solution1
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;

        for (int i = 0; i < n - 1; i++)
        {
            p1 = p1->next;
        }
        ListNode *p2_pre = p2;
        while (p1->next != NULL)
        {
            p2_pre = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2 == head)
        {
            head=p2->next;
        }else{
            p2_pre->next = p2->next;
        }
        delete (p2);
        return head;
    }
};