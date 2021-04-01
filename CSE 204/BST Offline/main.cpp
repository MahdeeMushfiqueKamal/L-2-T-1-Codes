#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;

typedef struct Node{
    int data;
    Node *left;
    Node *right;
};


class BST{
    Node root;

};
int main()
{
    int command;
    BST tree;

    while(1){
        cout<<"Press following number for desired operation:   "<<endl;
        cout<<"0-\tReturn."<<endl;

        cin>>command;
        if(command == 0) break;

    }

    return 0;
}
/*
Implement a binary search tree of integers having the following functions:
• insertItem : This function inserts a new item in the binary search tree.
• searchItem : This function searches for an item in the binary search tree. If the item, say 52, is found, the function should print “52 has been found”; otherwise the function should print “52 has not been found”.
• getInOrderSuccessor : This function returns the in-order successor of an item in the binary search tree. When there is no successor, return an invalid number to indicate it.
• getInOrderPredecessor : This function returns the in-order predecessor of an item in the binary search tree. When there is no predecessor, return an invalid number to indicate it.
• deleteItem : The function will delete an existing item from the binary search tree. You must re-structure the tree after deletion according to the idea given in class. In case of deletion of a node where both of its children exist, you must choose the next largest node in the tree for replacement. If the item is not in the tree, do nothing.
• getItemDepth : This function returns the depth of an item in the binary search tree. Assume that the root has a depth of 0, the nodes at the next level have a depth of 1 and so on. If the item is not in the tree, return an invalid number to indicate it.
• getMaxItem : This function finds and returns the maximum item of the binary search tree. You cannot write recursive function for this task.
• getMinItem : This function finds and returns the minimum item of the binary search tree. You cannot write recursive function for this task.
• getHeight : This function returns the height of the binary search tree.
• printInOrder : This function prints the in-order traversal of the binary search tree.
• printPreOrder : This function prints the pre-order traversal of the binary search tree.
• printPostOrder : This function prints the post-order traversal of the binary search tree.
• getSize : This function returns the current size of the binary search tree. The size of a tree is the number of nodes in the tree. You should write a recursive function for this task.
Except the last 5 functions, all the other functions should run in O(h) time, where h is the height of the binary search tree. Here “item” means an integer.

*/
