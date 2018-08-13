#include <iostream>
#include <vector>
#include <limits>

#define MAXSIZE 10008
int crossriver(u_int L,u_int s,u_int t, std::vector<int>& store)
{
    std::vector<int> dp(MAXSIZE,std::numeric_limits<int>::max());
    for(int i=0;i<=L;++i)
    {
        for(int j=s;j<=t;++j)
        {
            dp[i]=std::min(dp[i],dp[i+j]);
        }

        dp[i]+=store[i];

    }

    return dp[L];

}

int main(){




}