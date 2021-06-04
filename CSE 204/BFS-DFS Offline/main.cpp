#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;

class Graph{
    int N;
    vector<int> *adj;
    int *pieces;

public:
    Graph(int N){
        this->N = N;
        adj = new vector<int> [N];
        pieces = new int[N];
        for(int i=0;i<N; i++){
            pieces[i] = 0;
        }

    }
    ~Graph();

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void addPieces(int cx, int px){pieces[cx] = px;}

    int BFS(int origin){
        int collected = 0;
        bool *visited = new bool[N];
        for(int i = 0; i < N; i++){
            visited[i] = false;
        }

        queue<int> q;
        q.push(origin);
        visited[origin] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            collected += pieces[u];
            pieces[u] = 0;

            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }

        }
        return collected;
    }

    int DFS_visit(int u, bool *visited){
        int collected = 0;
        //visiting a node
        collected += pieces[u];
        pieces[u] = 0;

        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                collected+= DFS_visit(v, visited);

            }
        }
        return collected;
    }

    int DFS(int origin){

        bool *visited = new bool[N];
        for(int i = 0; i < N; i++){
            visited[i] = false;
        }
        visited[origin] = true;
        return DFS_visit(origin, visited);
    }

};

int main()
{
    ofstream out;
    out.open("out.txt");
    int C,R,L,F,u,v,cx,px,cy,fy;

    cin>>C>>R>>L>>F;
    Graph mamaland(C);

    for(int i=0;i<R;i++){
        cin>>u>>v;
        mamaland.addEdge(u,v);
    }

    int total_pieces=0;

    for(int i=0;i<L;i++){
        cin>>cx>>px;
        mamaland.addPieces(cx,px);
        total_pieces += px;
    }

    int total_collected = 0;
    int collected[F];
    for(int i=0;i<F;i++){
        cin>>cy>>fy;
        collected[fy] = mamaland.DFS(cy);
        total_collected += collected[fy];
    }

    if(total_collected == total_pieces) out<<"Mission Accomplished"<<endl;
    else out<<"Mission Impossible"<<endl;
    out<<total_collected<<" out of "<<total_pieces<<" pieces are collected"<<endl;
    for(int i=0;i<F;i++){
        out<<i<<" collected "<<collected[i]<<" pieces"<<endl;
    }
    return 0;
}


Graph::~Graph(){
    delete []adj;
    delete []pieces;
}

