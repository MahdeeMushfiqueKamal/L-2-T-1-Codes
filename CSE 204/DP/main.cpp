#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;
typedef long long ll;
ll n,s;
int f[105];
int dp[105][10005];
ll mod = 1e9 + 7;


int calculateWays(int dice , int sum){
    //cout<< "calculateWays(" <<dice<<" , "<<sum<<") is being executed\n";

    if(sum < dice){
        return dp[dice][sum] = 0;
    }
    if(dice <= 0) return 0;
    if(dice == 1 && sum <= f[dice]) return dp[dice][sum] = 1;
    if(dp[dice][sum] != -1) return dp[dice][sum];

    ll ways = 0;
    //watch(f[dice])
    for(int i=1; i<= f[dice] ; i++){

        if(sum - i > 0 && dice-1 >0){
                //cout<< "calculateWays(" <<dice-1<<" , "<<sum-i<<") is being called\n";
            if(dp[dice-1][sum-i] != -1) ways += dp[dice-1][sum-i];
            else ways += calculateWays(dice -1 , sum - i);
            ways %= mod;
        }

    }

    return dp[dice][sum] = ways;
}

int main()
{
    //initializing
    for(int i=0;i< 105; i++){
        for(int j=0; j< 10005 ; j++) dp[i][j] = -1;
    }
    cin>>n>>s;
    for(int i=1; i<=n;i++)cin>>f[i];


    cout<<calculateWays(n,s)<<endl;
    return 0;
}
