#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
using namespace std;

int main()
{
    //ofstream out;
    //out.open("out.txt");
    long long int n,k, cost = 0;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr, arr+n);
    reverse(arr, arr+n);
    //for(int i=0;i<n;i++)cout<<arr[i]<<" ";

    for(int i=0;i<n;i++){
        int prev_buy = i/k;
        cost += (1+ prev_buy)* arr[i];
    }

    cout<<cost<<endl;
    return 0;
}
