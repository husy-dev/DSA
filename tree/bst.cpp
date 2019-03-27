#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *lchild,*rchild;
    TreeNode(){}
    TreeNode(int val):val(val),lchild(NULL),rchild(NULL){}
};

class BST{
    public:
        TreeNode *root;
        BST(){
            root = new TreeNode(0);
        }
        TreeNode* search(int val);  //搜索，没找到就返回比val小的最大值
        void insert(int val); //插入
        void remove(int val);
        int height();
        ~BST(){
            delete root;
        }
};

TreeNode* BST::search(int val){
    TreeNode* cur = this->root;
    while(cur){
        cur = cur->val>val?cur->lchild:cur->rchild;
    }

}

