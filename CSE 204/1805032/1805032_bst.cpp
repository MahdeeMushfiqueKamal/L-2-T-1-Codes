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

    int getInOrderSuccessor(int x){
        if(!recursiveSearchItem(root,x))return -1;
        if(x == getMaxItem()) return -1;
        Node *node = root;
        while(node->data != x){
            if(node->data > x) node = node->left;
            else node= node->right;
        }
        //R-subtree er smallest
        if(node->right != NULL){
            Node *temp = node->right;
            while(temp->left != NULL) temp = temp->left;
            return temp->data;
        }
        //No right node
        else{
            Node *successor=NULL, *ancestor = root;
            while(ancestor != node){
                if(ancestor->data > node->data){
                    successor = ancestor;
                    if(ancestor->left != NULL)ancestor = ancestor->left;
                }
                else ancestor = ancestor->right;
            }
            return successor->data;
        }
        //
    }

    int getInOrderPredecessor(int x){
        if(!recursiveSearchItem(root,x))return -1;
        if(x == getMinItem()) return -1;
        Node *node = root;
        while(node->data != x){
            if(node->data > x) node = node->left;
            else node= node->right;
        }
        //found the node, need to find Predecessor,
        // L - sub tree er largest item
        if(node->left != NULL){
            Node *temp = node->left;
            while(temp->right != NULL) temp = temp->right;
            return temp->data;
        }
        else{
            //Need to write code
            Node *predecessor=NULL, *ancestor = root;
            while(ancestor != node){
                if(ancestor->data < node->data){
                    //emon ekta ancestor paisi jar jonno node ta RST e pore.
                    predecessor = ancestor;
                    if(ancestor->right != NULL)ancestor = ancestor->right;
                }
                else ancestor = ancestor->left;
            }
            return predecessor->data;
        }
        //
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
        cout<<endl;
    }


};
int main()
{
    int command,x;
    BST bstobj;
    cout<<"Press necessary number for desired operation:   "<<endl;
    cout<<"---------------------"<<endl;
    cout<<"0.Return            1.Insert Item        2.SearchItem        3.getInOrderSuccessor         4.getInOrderPredecessor"<<endl;
    cout<<"5.DeleteItem        6.getItemDepth       7.getMaxItem        8.getMinItem                  9.getHeight"<<endl;
    cout<<"10.printInOrder     11.printPreOrder     12.PrintPostOrder   13.getSize"<<endl;
    cout<<"---------------------"<<endl;
    while(1){

        cin>>command;
        if(command == 0) break;
        else if(command == 1){
            cout<<"Item- ";cin>>x;
            bstobj.insertItem(x);
        }
        else if(command == 2){
            cout<<"Item- ";cin>>x;
            bstobj.searchItem(x);
        }
        else if(command == 3){
            cout<<"Item- ";cin>>x;
            cout<<bstobj.getInOrderSuccessor(x)<<endl;
        }
        else if(command == 4){
            cout<<"Item- ";cin>>x;
            cout<<bstobj.getInOrderPredecessor(x)<<endl;
        }
        else if(command == 5){
            cout<<"Item- ";cin>>x;
            bstobj.deleteItem(x);
        }
        else if(command == 6){
            cout<<"Item- ";cin>>x;
            cout<<"Item Depth :"<<bstobj.getItemDepth(x)<<endl;
        }
        else if(command == 7) cout<<"Max Item: "<<bstobj.getMaxItem()<<endl;
        else if(command == 8) cout<<"Min Item: "<<bstobj.getMinItem()<<endl;
        else if(command == 9) cout<<"Height: "<<bstobj.getHeight()<<endl;
        else if(command == 10){
            cout<<"InOrder :";
            bstobj.printInOrder();
            cout<<endl;
        }
        else if(command == 11){
            cout<<"PreOrder :";
            bstobj.printPreOrder();
            cout<<endl;
        }
        else if(command == 12){
            cout<<"PostOrder :";
            bstobj.PrintPostOrder();
            cout<<endl;
        }
        else if(command == 13) cout<<"Size: "<<bstobj.getSize()<<endl;
        else if (command == 14) bstobj.showBST();

    }
    return 0;
}

