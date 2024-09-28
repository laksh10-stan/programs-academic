#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N , K , arr[100005] , dp[100005], sum[100005], res = 0;
    scanf("%lld %lld",&N,&K);
    dp[0] = 0 , sum[0] = 0;
    for(int i =1 ; i <= N; ++i)
    {
        scanf("%lld", arr + i);
        sum[i] = sum[i-1] + arr[i];
        if( i <= K ) dp[i] = dp[i - 1] + arr[i];
        else dp[i] = 0;
        res = max( res , dp[i] );
    }
    int prev = 0;
    for(int i = K + 1; i <= N; ++i)
    {
        int index = -1;
        if( prev == 0 )
        {
            for(int j = 0; j < K; ++j)
            {
                if( dp[i] <= ((i -j -2 > 0)?dp[i -j -2]:0 )+ sum[i] - sum[i - j - 1] )
                {
                    dp[i] = max( dp[i] , ((i -j -2 > 0)?dp[i -j -2]:0 )+ sum[i] - sum[i - j - 1]);
                    index = j;
                }
            }
            if( index == K - 1 ) prev = 0;
            else prev = 1;
        }
        else
        {
            int j = K - 1;
            dp[i] = dp[i-1] + arr[i];
            if( i - 2 >= 0 )
            dp[i] = max( dp[i] , dp[i - 2] + arr[i] );
            if( dp[i] <= ((i -j -2 > 0)?dp[i -j-2]:0 )+ sum[i] - sum[i - j - 1])
            {
                dp[i] = max( dp[i] , ((i -j -2 > 0)?dp[i -j -2]:0 )+ sum[i] - sum[i - j - 1]);
                index = j;
            }
            if( index == K - 1) prev = 0;
            else prev = 1;
        }
        //cout << dp[i] << " " << i << "\n";
        res = max( res , dp[i] );
    }
    cout << res << "\n";
    return 0;
}

