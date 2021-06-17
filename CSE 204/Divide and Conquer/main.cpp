#include <bits/stdc++.h>
#define INF 999999

using namespace std;

struct Point{
    int x,y;
};

Point invalid_point;


double findDistance(const Point &a, const Point &b){
    return sqrt( (a.x-b.x)*(a.x-(b.x)) + (a.y-b.y)*(a.y-b.y));
}
bool compX(const Point &a, const Point &b){
    if(a.x < b.x) return true;
    else if (a.x == b.x){
        if(a.y <= b.y) return true;
    }
    else return false;
}

bool compY(const Point &a, const Point &b){
    if(a.y <= b.y) return true;
    else return false;
}

class Pair{
public:
    Point first, second;
    double dist;

    Pair(){
        this-> first = invalid_point;
        this-> second = invalid_point;
        dist = INF;
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

Pair *firstAndSecondShortest( Point arr[], int l, int r);
void compareAndAdjust(Pair *ans, Pair tp);



int main()
{
    int n; cin>>n;

    Point arr[n];
    for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
    sort(arr, arr+n, compX);

    Pair *tp = firstAndSecondShortest(arr, 0, n-1);


    //cout<<"Debug for 3 inputs"<<endl;
    cout<<"Closest Points: (" << tp[0].first.x << " , " << tp[0].first.y<<") and ("<<tp[0].second.x<<" , "<<tp[0].second.y<<") dist= "<<tp[0].dist<<endl;
    cout<<"2nd Closest Points: ("<<tp[1].first.x<<" , " << tp[1].first.y<<") and ("<<tp[1].second.x<<" , "<<tp[1].second.y<<") dist= "<<tp[1].dist<<endl;

    return 0;
}

Pair *firstAndSecondShortest( Point arr[], int l, int r){           //l and r are both inclusive
    Pair *ans = new Pair[2];
    //base case: 1 or less points or invalid input
    //random point from twoPoint constructor

    //base case only 2 points
    if(r-l+1 == 2){
        ans[0] = Pair(arr[l], arr[r]);
        ans[1] = Pair(invalid_point, invalid_point, INF);
    }
    //base case 3 points
    else if(r-l+1 == 3){
        compareAndAdjust(ans, Pair(arr[l], arr[l+1]) );
        compareAndAdjust(ans, Pair(arr[l], arr[r]) );
        compareAndAdjust(ans, Pair(arr[l+1], arr[r]) );
    }

    else if(r-l+1 > 3){
        int mid = l + (r-l)/2;
        Pair *from_left = firstAndSecondShortest(arr , l , mid);
        Pair *from_right = firstAndSecondShortest(arr, mid+1, r);

        compareAndAdjust(ans, from_left[0]);
        compareAndAdjust(ans, from_left[1]);
        compareAndAdjust(ans, from_right[0]);
        compareAndAdjust(ans, from_right[1]);

//        // Points in Strip
//        double dlt = ans[1].dist;
//        //points in (arr[mid].x - dlt) to  (arr[mid].x + dlt)
//        vector<Point> pointsInStrip;
//        for(int i=l; i<=r; i++){
//            if(arr[i].x >= arr[mid].x - dlt && arr[i].x <= arr[mid].x +dlt )  pointsInStrip.push_back(arr[i]);
//        }
//        sort(pointsInStrip.begin(), pointsInStrip.end(), compY);
//        int len = pointsInStrip.size();
//
//        if(len > 1){
//            for(int i=0;i< len;i++){  // O(7n)
//                for(int j=1; j < 8; j++){
//                    if(i+j < len){
//                        //cout<<"Passing "<< pointsInStrip[i].x<<" , "<<pointsInStrip[i].y<<"   and "<< pointsInStrip[i+j].x<<" , "<<pointsInStrip[i+j].y<<" to compare"<<endl;
//                        compareAndAdjust(ans, Pair(pointsInStrip[i], pointsInStrip[i+j]));
//                    }
//                }
//            }
//        }
    }

    return ans;
}


void compareAndAdjust(Pair *ans, Pair tp){
    //cout<<"Adjusting"<<tp.first.x<<" , "<<tp.first.y<<"  and  "<<tp.second.x<<" , "<<tp.second.y<<"  dist = "<<tp.dist<<endl;
    if(tp.dist < ans[0].dist){
        ans[0].first = tp.first;
        ans[0].second = tp.second;
        ans[0].dist = tp.dist;
    }
    else if(tp.dist < ans[1].dist){
        ans[1].first = tp.first;
        ans[1].second = tp.second;
        ans[1].dist = tp.dist;
    }
}
