ub#include<iostream>
#include<cstdlib>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;
void null_message();

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
    int pillowHolderReflx();
    void revDir();
    void pass();
    void addPlayer(int r);
    void enterPlayer(int r);
    void sequence();
    void eleminate();
    int getLen(){return len;}
    ~PillowGame();
};

int main()
{
    int n;
    cin>>n;
    int R[n];
    for(int i=0;i<n;i++)cin>>R[i];
    PillowGame PG;
    for(int i=0;i<n;i++)PG.addPlayer(R[i]);
    int time = 0,t;
    char command;
    while(1){
        cin>>t;
        cin>>command;

        while(time + PG.pillowHolderReflx() < t){
            time+= PG.pillowHolderReflx();
            PG.pass();
        }
        if(command == 'F'){
            if(PG.getLen()!=1){
                cout<<"Game Over : Player "<< PG.pillowHolderId() <<" is holding the pillow at t="<<t<<", ";
                PG.sequence();
            }
            break;
        }
        else if(command == 'P'){
            if(PG.getLen()!=1)cout<<"Player "<< PG.pillowHolderId() <<" is holding the pillow at t="<<t<<endl;
        }
        else if (command == 'R')PG.revDir();
        else if (command == 'I'){
            int x;
            cin>>x;
            PG.enterPlayer(x);
        }
        else if(command == 'M'){
            if(PG.getLen()!=1)cout<<"Player "<<PG.pillowHolderId()<<" has been eliminated at t="<<t<<endl;
            PG.eleminate();
            time = t;
        }
    }
    return 0;
}


PillowGame::PillowGame(){
    head = new Node;
    tail = new Node;
    //pillow = new Node;
    if(head==NULL || tail==NULL)null_message();
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

int PillowGame::pillowHolderReflx(){
    return pillow->reflx;
}

void PillowGame::pass(){
    if(direction == 1){
        pillow = pillow->next;
    }
    else pillow = pillow->prev;
}

void PillowGame::addPlayer(int r){
    if(len > 1){
        Node *new_node = new Node;
        if(new_node==NULL)null_message();
        new_node->id = ++id_gen;
        new_node-> reflx = r;
        len++;

        tail->next = new_node;
        new_node-> prev = tail;

        new_node->next = head;
        head->prev = new_node;

        tail = new_node;
    }
    else if(len == 0){
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
}

void PillowGame::enterPlayer(int r){
    if(len==1)return;
    Node *new_node = new Node;
    if(new_node==NULL)null_message();
    new_node->id = ++id_gen;
    new_node->reflx = r;
    len++;

    if(direction == 1){
        Node *left;
        //Node *left = new Node;
        left = pillow->prev;

        left->next  = new_node;
        new_node->prev = left;

        new_node->next = pillow;
        pillow->prev = new_node;

    }
    else if(direction == -1){
        Node *right;
        //Node *right = new Node;
        right = pillow->next;

        pillow->next = new_node;
        new_node->prev = pillow;

        new_node->next = right;
        right->prev = new_node;
    }
}


void PillowGame::sequence(){
    cout<<"pillow passing sequence = Player "<<pillow->id;
    Node *temp;
    if(direction == 1){
        temp = pillow->next;
        while(temp!=pillow){
            cout<<" , "<<temp->id;
            temp = temp-> next;
        }
    }
    else{
        temp = pillow->prev;
        while(temp!=pillow){
            cout<<" , "<<temp->id;
            temp = temp-> prev;
        }
    }
}


void PillowGame::eleminate(){
    if(len==1)return;
    Node *left,*right;
    left= pillow->prev;
    right = pillow->next;

    left->next = right;
    right->prev = left;

    if(direction==1)pillow = right;
    else pillow = left;

    len--;
    if(len==1)cout<<"Game over : Player "<< pillow->id <<" wins!!"<<endl;
}



void null_message(){
    cout<<"Allocated memory is NULL, Exiting Program..."<<endl;
    exit(0);
}

PillowGame::~PillowGame(){
    Node *temp;
    while(head!=tail){
        temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
}
