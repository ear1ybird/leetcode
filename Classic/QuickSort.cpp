#include <iostream>
#include <vector>
#include <string>

using namespace std;

int AdjustArray(int[], int, int);
void quick_sort(int[], int, int);

template<typename T>
int getArrayLen(T &array)
{
    return (sizeof(array) / sizeof(array[0]));
}

int main(void)
{
    int s[] = {9, 8, 4, 5, 1, 2, 3};
    quick_sort(s, 0, 6);
    cout<<getArrayLen(s);
    return 0;
}

int AdjustArray(int s[], int l, int r)
{
    int i = l, j = r;
    int x = s[l];

    while (i < j)
    {
        while (i < j && s[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            s[i] = s[j];
            i++;
        }

        while (i < j && s[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            s[j] = s[i];
            j--;
        }
    }
    s[i] = x;
    return i;
}

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = AdjustArray(s, l, r);
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}