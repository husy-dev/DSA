#include<iostream>
using namespace std;

void swap(int& a, int &b){
    int temp =a;
    a =b;
    b=temp;
}

int partition(int *vi, int low, int up){
	int pivot = vi[low];
	int mid = low;
    int temp=0;
	for (int i = low+1; i < up;)
	{
		if(vi[i] < pivot)
		{
            swap(vi[i++],vi[++mid]);
		}else{
            ++i;
        }
	}
    swap(vi[low],vi[mid]);
	return mid;
}

void quickSort(int* vi, int low, int up)
{
	if(low < up)
	{
		int mid = partition(vi, low, up);
		quickSort(vi, low, mid);
		quickSort(vi, mid+1, up);
	}
}

//输入有序序列，和target，返回小于target的最大下标,二分法
int lastSmaller(int target,int* nums, int len){
    int lo=0,hi=len-1,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(nums[mid]>=target){ //这里决定了所有大于target的值都在mid的右边，因此最后mid返回的就是小于target的
            hi =mid-1;
        }else{
            lo=mid+1;
        }
    }
    return hi;
}

//在nums数组里找到第一个大于target的下标,len是数组的长度
int firstLarger(int target,int* nums, int len){
   int lo=0,hi=len-1,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(nums[mid]>target){ //这里决定了所有大于target的值都在mid的右边，因此最后mid返回的就是小于target的
            hi =mid-1;
        }else{
            lo=mid+1;
        }
    }
    return lo;

}


int main(){
    //数据准备
    int dotNum; // 点的个数
    int rangeNum; //区间的个数
    cin>>dotNum>>rangeNum;

    int ** rangeList=new int*[rangeNum];
    for(int i=0;i<rangeNum;++i){
        rangeList[i] =new int[2];
    }
    int *dotList =new int[dotNum];
    int *resultList =new int[rangeNum];

    for(int i=0;i<dotNum;++i) {
        cin>>dotList[i];
    }
    int pre,next;
    for(int i=0;i<rangeNum;++i){
        cin>>rangeList[i][0]>>rangeList[i][1];
    } 

    //给dotList使用快排排序
    quickSort(dotList,0,dotNum);
    //对每一个区间记录下最后一个小于下限的下标
    for(int i =0;i<rangeNum;++i){
        resultList[i] =firstLarger(rangeList[i][1],dotList,dotNum)-lastSmaller(rangeList[i][0],dotList,dotNum)-1;
    }

    //输出
    for(int i=0;i<rangeNum;++i){
        cout<<resultList[i]<<"\n";
    }
    return 0;
}