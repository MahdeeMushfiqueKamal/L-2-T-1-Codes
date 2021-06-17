#include <bits/stdc++.h>
#define INF 999999
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

int n;

struct Point{
    int x,y;
};

Point invalid_point;


double findDistance(const Point &a, const Point &b){
    return sqrt( (double) (a.x-b.x)*(a.x-(b.x)) + (a.y-b.y)*(a.y-b.y));
}
bool compX(const Point &a, const Point &b);
bool compY(const Point &a, const Point &b);

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

Pair *firstAndSecondShortest( Point arrX[],Point arrY[] ,int l, int r);
void compareAndAdjust(Pair *ans, Pair tp);



int main()
{
    cin>>n;

    Point arr[n],arrX[n],arrY[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        arrX[i].x = arrY[i].x = arr[i].x;
        arrX[i].y = arrY[i].y = arr[i].y;
    }
    sort(arrX, arrX+n, compX);
    sort(arrY, arrY+n, compY);

    Pair *tp = firstAndSecondShortest(arrX, arrY, 0, n-1);

    int p1,p2;
    for(int i=0; i<n;i++){
        if(arr[i].x == tp[1].first.x && arr[i].y == tp[1].first.y) p1 = i;
        else if (arr[i].x == tp[1].second.x && arr[i].y == tp[1].second.y) p2 = i;
    }

    cout<<p1<<" "<<p2<<endl;
    printf("%0.4f",tp[1].dist);

    return 0;
}

Pair *firstAndSecondShortest( Point arrX[], Point arrY[], int l, int r){           //l and r are both inclusive
    Pair *ans = new Pair[2];
    //cout<<"function "<<l<<" , "<<r<<" called\n";
    //base case: 1 or less points or invalid input
    //random point from twoPoint constructor

    //base case only 2 points
    if(r-l+1 == 2){
        ans[0] = Pair(arrX[l], arrX[r]);
        ans[1] = Pair(invalid_point, invalid_point, INF);
    }
    //base case 3 points
    else if(r-l+1 == 3){
        compareAndAdjust(ans, Pair(arrX[l], arrX[l+1]) );
        compareAndAdjust(ans, Pair(arrX[l], arrX[r]) );
        compareAndAdjust(ans, Pair(arrX[l+1], arrX[r]) );
    }

    else if(r-l+1 > 3){
        int mid = l + (r-l)/2;
        Pair *from_left = firstAndSecondShortest(arrX , arrY,  l , mid);
        Pair *from_right = firstAndSecondShortest(arrX, arrY,  mid+1, r);

        compareAndAdjust(ans, from_left[0]);
        compareAndAdjust(ans, from_left[1]);
        compareAndAdjust(ans, from_right[0]);
        compareAndAdjust(ans, from_right[1]);

        double dlt = ans[1].dist;
//        cout<<"Combine step for "<<l<<" , "<<r<<endl;
//        watch(dlt)
//        watch(arrX[mid].x)

        //points in (arr[mid].x - dlt) to  (arr[mid].x + dlt)
        vector<Point> pointsInStrip;
        for(int i=0; i<=n; i++){
            if(arrY[i].x >= arrX[mid].x - dlt && arrY[i].x <= arrX[mid].x +dlt )  pointsInStrip.push_back(arrY[i]);
        }
//        cout<<"Points in strip: ";
//        for(Point p : pointsInStrip)cout<<"("<<p.x<<" , "<<p.y<<")   ";
//        cout<<endl;
        int len = pointsInStrip.size();

        if(len > 1){
            for(int i=0;i< len;i++){  // O(7n)
                for(int j=1; j < 8; j++){
                    if(i+j < len){
                        //cout<<"Passing "<< pointsInStrip[i].x<<" , "<<pointsInStrip[i].y<<"   and "<< pointsInStrip[i+j].x<<" , "<<pointsInStrip[i+j].y<<" to compare"<<endl;
                        compareAndAdjust(ans, Pair(pointsInStrip[i], pointsInStrip[i+j]));
                    }
                }
            }
        }
    }
//    cout<<"Return of function "<<l<<" and "<<r<<endl;
//    cout<<"Closest Points: (" << ans[0].first.x << " , " << ans[0].first.y<<") and ("<<ans[0].second.x<<" , "<<ans[0].second.y<<") dist= "<<ans[0].dist<<endl;
//    cout<<"2nd Closest Points: ("<<ans[1].first.x<<" , " << ans[1].first.y<<") and ("<<ans[1].second.x<<" , "<<ans[1].second.y<<") dist= "<<ans[1].dist<<endl;
    return ans;
}


void compareAndAdjust(Pair *ans, Pair tp){
    //cout<<"Adjusting "<<tp.first.x<<" , "<<tp.first.y<<"  and  "<<tp.second.x<<" , "<<tp.second.y<<"  dist = "<<tp.dist<<endl;
    if(tp.dist < ans[0].dist){

        //copying the content of close points to 2nd closest points
        ans[1].first = ans[0].first;
        ans[1].second = ans[0].second;
        ans[1].dist = ans[0].dist;

        //updating closest point
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
