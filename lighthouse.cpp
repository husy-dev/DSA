#include<iostream>
#include<vector>
using namespace std;

struct pointer{
    int x;
    int y;
    pointer(int x=0,int y=0):x(x),y(y){}
    
};



int main(){
    //输入
    int num;
    vector<pointer> l;
    cin >>num;
    int a,b;
    while(num--){
        cin>>a>>b;
        l.push_back(pointer(a,b));
    }

    //开始比较：先按照x大小排序，然后获得后一个y-前一个y的差值数组，然后两个差值或者累计差值>0的就符合要求。
    

    return 0;
}

