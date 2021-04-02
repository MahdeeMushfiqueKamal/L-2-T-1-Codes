#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};


class BST{
    Node *root = NULL;

    Node* recursiveInsertItem(Node *node, int x){
        if(node == NULL){
            node = new Node;
            node->data = x;
            node->left = NULL;
            node->right = NULL;
        }
        else if(x <= node->data){
            node->left = recursiveInsertItem(node->left,x);
        }
        else if(x > node->data){
            node->right = recursiveInsertItem(node->right,x);
        }
        return node;

    }
    bool recursiveSearchItem(Node *node, int x){
        if(node == NULL)return false;
        else if(node->data == x)return true;
        else if(x > node->data) recursiveSearchItem(node->right,x);
        else if(x < node->data) recursiveSearchItem(node->left,x);
    }

    Node* recursiveDeleteItem(Node *node, int x){
        if(node == NULL)return node;

        //searching for deleting
        else if(x > node->data){
            node->right = recursiveDeleteItem(node->right,x);
        }
        else if(x < node->data){
            node->left = recursiveDeleteItem(node->left,x);
        }

        else if(x == node->data){
            //found the node to be deleted.
            if(node->left == NULL && node->right == NULL){
                delete node;
                node = NULL;
            }
            else if(node->left == NULL){
                Node *temp = node->right;
                delete node;
                node = temp;
            }
            else if(node->right == NULL){
                Node *temp = node->left;
                delete node;
                node = temp;
            }

            else{
                //has 2 children
                Node *temp = node->right;
                //finding smallest in R-sub tree.
                while(temp->left != NULL)temp = temp->left;
                node->data = temp->data;
                node->right = recursiveDeleteItem(node->right, temp->data);
            }

            return node;
        }
    }

    int recursiveHeight(Node *node){
        if(node == NULL) return 0;
        return 1+ max(recursiveHeight(node->left), recursiveHeight(node->right));
    }

    int recursiveDepth(Node *node,int x){
        if(node->data == x) return 0;
        else if(x > node->data){
            return 1+ recursiveDepth(node->right, x);
        }
        else if(x < node->data){
            return 1+ recursiveDepth(node->left, x);
        }
    }

    int recursiveSize(Node *node){
        if(node == NULL) return 0;
        return 1+ recursiveSize(node->left) + recursiveSize(node->right);
    }

    void recursiveInOrder(Node *node){
        if(node == NULL) return;
        recursiveInOrder(node->left);
        cout<<node->data<<" ";
        recursiveInOrder(node->right);
    }

    void recursivePreOrder(Node *node){
        if(node == NULL) return;
        cout<<node->data<<" ";
        recursivePreOrder(node->left);
        recursivePreOrder(node->right);
    }

    void recursivePostOrder(Node *node){
        if(node == NULL) return;
        recursivePostOrder(node->left);
        recursivePostOrder(node->right);
        cout<<node->data<<" ";
    }


    //Own Function
    void recursiveShowBST(Node *node){
        cout<<"Node-  "<<node->data<<"    ";
        if(node->left != NULL)cout<<"Left - "<<node->left->data<<"    ";
        if(node->right != NULL)cout<<"Right - "<<node->right->data<<"    ";
        cout<<endl;
        if(node->left != NULL)  recursiveShowBST(node->left);
        if(node->right != NULL)    recursiveShowBST(node->right);
    }



public:
    void insertItem(int x){
        root = recursiveInsertItem(root,x);
    }

    void searchItem(int x){
        if(recursiveSearchItem(root,x))cout<<x<<" has been found"<<endl;
        else cout<<x<<" has not been found"<<endl;
    }

    void deleteItem(int x){
        recursiveDeleteItem(root,x);
    }

    int getMaxItem(){
        Node *temp= root;
        while(temp->right != NULL) temp = temp->right;
        return temp->data;
    }

    int getMinItem(){
        Node *temp= root;
        while(temp->left != NULL) temp = temp->left;
        return temp->data;
    }

    int getHeight(){
        return recursiveHeight(root);
    }

    int getItemDepth(int x){
        if(!recursiveSearchItem(root,x)) return -1;
        return recursiveDepth(root,x);
    }

    int getSize(){
        return recursiveSize(root);
    }

    void printInOrder(){
        recursiveInOrder(root);
    }

    void printPreOrder(){
        recursivePreOrder(root);
    }

    void PrintPostOrder(){
        recursivePostOrder(root);
    }
    //own method
    void showBST(){
        cout<<"Showing BST: "<<endl;
        recursiveShowBST(root);
    }


};
int main()
{
    int command;
    BST bstobj;
    bstobj.insertItem(5);
    bstobj.insertItem(8);
    bstobj.insertItem(3);
    bstobj.insertItem(2);
    bstobj.insertItem(4);
    bstobj.insertItem(7);
    bstobj.insertItem(9);

    cout<<bstobj.getSize()<<endl;
    bstobj.showBST();

    bstobj.searchItem(2);
    bstobj.searchItem(1);

    cout<<"Max Item - "<<bstobj.getMaxItem()<<endl;
    cout<<"Min Item - "<<bstobj.getMinItem()<<endl;
    cout<<"Depth of 5 - "<<bstobj.getItemDepth(5)<<endl;
    cout<<"Depth of 8 - "<<bstobj.getItemDepth(8)<<endl;
    cout<<"Height - "<<bstobj.getHeight()<<endl;

    bstobj.deleteItem(8);
    bstobj.showBST();

    return 0;
}
/*
Implement a binary search tree of integers having the following functions:

• getInOrderSuccessor : This function returns the in-order successor of an item in the binary search tree. When there is no successor, return an invalid number to indicate it.
• getInOrderPredecessor : This function returns the in-order predecessor of an item in the binary search tree. When there is no predecessor, return an invalid number to indicate it.

*/



//    while(1){
//        cout<<"---------------------"<<endl;
//        cout<<"0. Return"<<endl;
//        cout<<"1. Insert Item"<<endl;
//        cout<<"---------------------\nPress necessary number for desired operation:   ";
//        cin>>command;
//        if(command == 0) break;
//        else if(command == 1){
//            int x;
//            cin>>x;
//            bstobj.insertItem(x);
//        }
//
//    }
