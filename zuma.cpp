#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string a;
    vector<vector<int> > ans(32,vector<int>());
    int i =0;
    int num,loc;
    char ch;
    int maxLen=0;
    cin>>a>>num;
    vector<string> result;
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
        vector<char> l(maxLen,'*');
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