#include "vector.hpp"
#include<iostream>

vector::vector(){
    this->_capacity = 10;
    this->_size = 0;
    this->_elems =new int[this->_capacity];
}

vector::~vector(){
    delete []this->_elems;
}

void vector::insert(size_t loc, int val){
    this->_size++;
    this->check();
    int *tmp=this->_elems;
    for(size_t t=0;t<loc;++t) this->_elems[t]=tmp[t];
    this->_elems[loc]=val;
    for(size_t t = loc+1;t<this->_size;++t){
        this->_elems[t]=tmp[t-1];
    }
}

void vector::resize(){
    int *tmp = this->_elems;
    this->_elems= new int[this->_capacity*2];
    for(size_t i=0;i<this->_size;++i){
        this->_elems[i]=tmp[i];
    }
    delete []tmp;
    this->_capacity *=2;
}

std::ostream& vector::operator<<(std::ostream& os){
    for(size_t i=0;i<this->_size;++i){
        os<<this->_elems[i]<<",";
    }
    os<<"\n";
    return os;
}

void vector::check(){
    if (this->_size>=this->_capacity) this->resize();
}

// int main(){
//     vector i;
//     for(int i =0;i<12;++i){
//         i.insert(i);
//     }
//     cout<<i;
// }