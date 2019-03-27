#include "vector.hpp"

void vector::_swap(int a, int b){
    int temp=this->_elems[a];
    this->_elems[a]=this->_elems[b];
    this->_elems[b]= temp;
}

/*
划分一段向量，通过交换找到一个位置其左侧不大于它，右侧不小于它
*/
size_t vector::_partiton(size_t low, size_t high){
    int pivot = this->_elems[low];
    while(low<high){
        while(this->_elems[high]>=pivot) --high;
        this->_elems[low]=this->_elems[high];
        while(this->_elems[low]<=pivot) ++low;
        this->_elems[low]=this->_elems[high];
    }
}
/* 递归版,顺序为从小到大
* low包含，high则不包含
*/
void vector::_quickSort1(size_t low,size_t high, int* data){
    if (low==high||low==high+1) return;
    size_t mid= this->_partiton(low,high);
    _quickSort1(low, mid, data);
    _quickSort1(mid, high, data);
}

/*递归版，关键码递增
* [low,high)
*/
void vector::_mergeSort1(size_t low, size_t high ){
    if (high-low<2) return;
    size_t mid = (high+low)>>1; //由于high不包含，若序列为偶数个，mid指向中间两个的后面那一个
    _mergeSort1(low,mid);
    _mergeSort1(mid,high);
    _merge(low,mid,high);
}
/*要注意p的内存泄漏
*/
int* vector::_deepCopy(){
    int *p=new int[this->_size];
    for(size_t i=0;i<this->_size;++i){
        p[i]=this->_elems[i];
    }
    return p;
}
void vector::_merge(size_t low, size_t mid, size_t high){
    int* old = this->_deepCopy();
    size_t i=low,j = mid,t=low;
    for(;i<mid,j<high;){
        if(old[i]<old[j])  this->_elems[t++]=old[i++];
        else{
            this->_elems[t++]= old[j++];
        }
    }
    if (i<mid && j==high) { //把i剩下的复制到_elems里去 
        for(size_t k=i;k<mid;) this->_elems[t++] = old[k++];
    }
    if (j<high && i==mid) { //把j剩下的复制到_elems里去 
        for(size_t k=j;k<high;) this->_elems[t++] = old[k++];
    }
    delete []old;
}

int main(){
    
}






