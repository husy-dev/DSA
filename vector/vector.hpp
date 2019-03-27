#ifndef I_VECTOR_H
#define I_VECTOR_H
typedef unsigned size_t;
class vector{
    private:
        int* _elems;
        size_t _capacity=10;
        size_t _size;
        void _quickSort1(size_t low,size_t high, int* data);
        void _quickSort2();
        void _mergeSort1(size_t low, size_t high);
        void _mergeSort2();
        void _swap(int a, int b);
        void _merge(size_t low, size_t mid, size_t high);
        int* _deepCopy();
        void check();
        size_t _partiton(size_t low, size_t high);
        
    public:
        vector();
        ~vector();
        //void sort(){}
        void resize();
        void insert(size_t loc, int val);
        //void remove(){}
        std:ostream& operator<<(std::ostream& os);
};

#endif