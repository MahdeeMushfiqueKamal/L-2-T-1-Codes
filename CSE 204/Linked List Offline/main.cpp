#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;

struct Node{
    int id;
    int reflx;
    Node *prev;
    Node *next;
};

class PillowGame{
    int id_gen=0;
    int direction = 1;
    int len = 0;

    Node *head,*tail,*pillow;

public:
    PillowGame();
    int pillowHolderId();
    void revDir();
    void pass();
    void addPlayer(int r);

    void enterPlayer(int r){

    }

};

int main()
{
    int n;
    cin>>n;
    int R[n];
    for(int i=0;i<n;i++)cin>>R[i];
    PillowGame PG;
    for(int i=0;i<n;i++)PG.addPlayer(R[i]);
    cout<<PG.pillowHolderId()<<" is holding the pillow"<<endl;
    PG.pass();
    cout<<PG.pillowHolderId()<<" is holding the pillow"<<endl;
    PG.pass();
    PG.pass();
    PG.pass();
    PG.revDir();
    PG.pass();
    cout<<PG.pillowHolderId()<<" is holding the pillow"<<endl;
    return 0;
}


PillowGame::PillowGame(){
    head = new Node;
    tail = new Node;
    pillow = new Node;
    head->prev = NULL;
    head->next = NULL;
    tail->prev = NULL;
    tail->next = NULL;
    pillow = head;

}

void PillowGame::revDir(){
    direction = (direction == 1) ? -1 : 1;
}

int PillowGame::pillowHolderId(){
    return pillow->id;
}

void PillowGame::pass(){
    if(direction == 1){
        pillow = pillow->next;
    }
    else pillow = pillow->prev;
}

void PillowGame::addPlayer(int r){
    if(len == 0){
        head->id = ++id_gen;
        head->reflx = r;
        len++;
    }
    else if(len == 1){
        tail->id = ++id_gen;
        tail->reflx = r;
        len++;

        head->next = tail;
        tail->next = head;
        head->prev = tail;
        tail->prev = head;
    }
    else if(len > 1){
        Node *new_node = new Node;
        new_node->id = ++id_gen;
        new_node-> reflx = r;
        len++;

        tail->next = new_node;
        new_node-> prev = tail;

        new_node->next = head;
        head->prev = new_node;

        tail = new_node;
    }
}
