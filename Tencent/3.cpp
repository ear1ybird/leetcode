#include <iostream>
using namespace std;

bool isBST(int* array,int length)
{
 
    if (array==NULL||length==0)
    {
        return false;
    }
    bool result=true;
    int root=array[length-1];
    int i=0;
    for (;i<length-1;i++)
    {
        if (array[i]>root)
        {
            break;
        }
    }
    int j=i;
    for (;j<length-1;j++)
    {
        if (array[j]<root)
        {
            return false;
        }
    }
    bool lReult=true,rResult=true;
    if (i>0)
    {
         lReult=isBST(array,i);
    }
 
    if (i<length-1)
    {
         rResult=isBST(array+i,length-i-1);
    }
    return (lReult&&rResult);
}

int main()
{
 
    int array[100]={0};
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    if (isBST(array,n))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
