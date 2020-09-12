#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int main(void){
    float sphere_x;
    float sphere_y;
    float sphere_z;
    float sphere_r;
    cin>>sphere_x>>sphere_y>>sphere_z>>sphere_r;

    float box_p_x;
    float box_p_y;
    float box_p_z;
    float box_len_x;
    float box_len_y;
    float box_len_z;
    cin>>box_p_x>>box_p_y>>box_p_z;
    cin>>box_len_x>>box_len_y>>box_len_z;

    float x_dis=abs(box_p_x-sphere_x);
    float y_dis=abs(box_p_y-sphere_y);
    float z_dis=abs(box_p_z-sphere_z);

    

    if(x_dis>sphere_r+box_len_x/2 && y_dis>sphere_r+box_len_y/2 && z_dis>sphere_r+box_len_z/2){
            cout<<"false"<<endl;
        }else{
            cout<<"true"<<endl;
        }

    return 0;
}   