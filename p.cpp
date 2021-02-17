
#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

const int MAX = 1e6+5;

bool prime[MAX];
int spf[MAX];

void sieve()
{
    fill(prime, prime + MAX, true);
    for (int i = 1; i < MAX; i++)spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                if (prime[j]) spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

//Multiple Query
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


int main()
{



	sieve();






	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
        int dp[n];
        dp[0]=dp[1]=0;
        int ans=0;
        for(int i=2; i<(n); i++){


            if(prime[i] and prime[i-2]) ans++;
                dp[i]=ans;



	}

		cout<<dp[n]<<'\n';

	}

	return 0;

}

