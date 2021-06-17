#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;

typedef long long ll;
int T,tc;

struct Point{
    int x,y;
};
Point invalid_point;

double findDistance(const Point &a, const Point &b){
    return sqrt( (a.x-b.x)*(a.x-(b.x)) + (a.y-b.y)*(a.y-b.y));
}

class Pair{
public:
    Point first, second;
    double dist;

    Pair(){
        this-> first = invalid_point;
        this-> second = invalid_point;
        dist = 999999999;
    }

    Pair( Point first, Point second){
        this-> first = first;
        this-> second = second;
        dist = findDistance(first, second);
    }

    Pair( Point first, Point second, double dist){
        this-> first = first;
        this-> second = second;
        this-> dist = dist;
    }


};

bool comp(Pair &a, Pair &b){
    if(a.dist <= b.dist) return true;
    else return false;
}

int main()
{
    int n; cin>>n;

    Point arr[n],arrX[n],arrY[n];
    for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;

    vector <Pair> allpairs;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++) {
            allpairs.push_back(Pair(arr[i],arr[j]));
        }
    }

    sort(allpairs.begin(),allpairs.end(), comp);

    for(Pair p: allpairs) cout<<p.first.x<<" , "<<p.first.y<<"    and    "<<p.second.x<<" , "<<p.second.y<<"    dist = "<<p.dist<<endl;
    return 0;
}
