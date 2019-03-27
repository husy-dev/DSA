#include<iostream>
#include<algorithm>
using namespace std;

//自己实现ivector的缩容扩容
template <typename T> class ivector{
    private:
        size_t _size, _capacity;
        T* _elems;
        void enlarge(){  //默认两倍扩充
            this->_capacity *=2;
            T* tmp = this->_elems;
            this->_elems=new T[this->_capacity];
            for (int i=0;i<this->_size;++i){
                this->_elems[i]=tmp[i];
            }
            delete [] tmp;
        }
        bool checkOver(){
            return this->_size>=this->_capacity;
        }     
    public:
        ivector(){
            this->_capacity=10;
            this->_size=0;
            this->_elems=new T[this->_capacity];
        }
        ivector(const size_t _size, T val){
            this->_capacity= _size;
            this->_size=this->_capacity;
            this->_elems=new T[this->_size]();
            for(int i=0;i<this->_size;++i){
                this->_elems[i]=val;
            }

        }
        void push_back(T val){
            if (checkOver()){
                this->enlarge();
            }
            this->_elems[this->_size++]=val;
        }
        size_t size(){
            return this->_size;
        }
        T at(size_t loc){
            return this->_elems[loc];
        }

        void clear(){
            delete [] this->_elems;
            this->_size=0;
            this->_capacity = 10;
            this->_elems = new T[this->_capacity]();
        }

        T& operator[](size_t loc){
            return this->_elems[loc];
        }

};

int main(){
    string a;
    ivector<ivector<int> > ans(32,ivector<int>());
    int i =0;
    int num,loc;
    char ch;
    int maxLen=0;
    cin>>a>>num;
    ivector<string> result;
    for(int i=0;i<a.size();++i){
        ans[a[i]-'A'].push_back(i);
        maxLen++;
    }
    while(num--){
        cin>>loc>>ch;
        for (int i=0;i<32;++i){
            for (int j=0;j<ans[i].size();++j){
                if (ans[i][j]>=loc){
                    ans[i][j]++;
                }
            }
        }
        ans[ch-'A'].push_back(loc); //不保证顺序了
        maxLen++;
        //开始check是否连续能消除
        int maxLoc=INT_MAX,minLoc=INT_MIN;
        for (int i=0;i<32;++i){
            if (ans[i].size()>2){
                maxLoc = max(max(ans[i][2],ans[i][1]),ans[i][0]);
                minLoc = min(min(ans[i][1],ans[i][2]),ans[i][0]);
                if (maxLoc-minLoc==2){
                    ans[i].clear();
                    maxLen-=3;
                    //恢复消除后的现象
                    for (int t=0;t<32;++t){
                        for (int j=0;j<ans[t].size();++j){
                            if (ans[t][j]>maxLoc){
                                ans[t][j]-=3;
                            }
                        }
                    }
                    i = -1; //重新检查,由于这里不是第一次进入for循环，因此会++，所以要设为-1
                }
            }
        }
        
        //打印
        ivector<char> l(maxLen,'*');
        for (int i=0;i<32;++i){
            for(int j=0;j<ans[i].size();++j){
                l[ans[i][j]]=i+'A';
            }
        }
        if (l.size()){
            string tmp;
            for (int i=0;i<l.size();++i){
                tmp+=l[i];
            }
            result.push_back(tmp);
        }else{
            result.push_back("-");
        }
    }

    //输出
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<"\n";
    }
    return 0;
}