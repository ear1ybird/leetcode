/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-12-02
    Description:输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入
        的前序遍历和中序遍历的结果中都不含重复的数字。
    Algorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

 struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return help(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int left,int right,int left1,int right1){
        if(left>=preorder.size() || left1>=inorder.size() || left>right || left1>right1){
            return NULL;
        }
        int value= preorder[left];
        TreeNode* node=new TreeNode(value);

        //计算中序遍历中左子树长度
        int count=left1;
        while(inorder[count]!=value){
            count++;
        }
        count-=left1;
        node->left=help(preorder,inorder,left+1,left+count,left1,left1+count-1);
        node->right=help(preorder,inorder,left+count+1,right,left1+count+1,right1);

        return node;
    } 
};