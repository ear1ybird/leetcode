/*************************************************************************
    Copyright:ear1ybird
    Author:ear1ybird
    Date:2020-09-16
    Description:给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
    Agorithm:
**************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void outputmatrix(vector<vector<int>> matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        outputmatrix(matrix);
        return;
    }
};