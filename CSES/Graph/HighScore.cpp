#include<bits/stdc++.h>
#include<iostream>
typedef int long long ll;
using namespace std;

class Solution {
    ll inf = 1e17;
    ll ninf = inf*-1;
public:
    ll findMaxPath(int n, vector<vector<ll>>& adj) {
        vector<ll> dst(n, inf);
        dst[0] = 0;
        ll x = -1;
        for(int i=1; i<n; i++) { // ed {st, dst, weight}
            x = -1;
            for(auto ed:adj) {
                if(dst[ed[0]]!=inf && dst[ed[1]]>dst[ed[0]]+ed[2]) {
                    x = ed[1];
                    dst[ed[1]] = dst[ed[0]] + ed[2];
                }
            }
        }

        if(x!=-1) {
            ll prev = dst[n-1]*-1;
            for(int i=0; i<=n+1; i++) { // ed {st, dst, weight}
                for(auto ed:adj) {
                    if(dst[ed[0]]!=inf && dst[ed[1]]>dst[ed[0]]+ed[2]) {
                        dst[ed[1]] = ninf;
                    }     
                }
            }
            if(dst[n-1]==ninf) return -1;
            return dst[n-1]*-1;
        }
        return -1*dst[n-1];
    }
};

int main() {
    ll n, m, a, b, c;
    cin >> n >> m;
    vector<vector<ll>> adj(m);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        /*Making all the edge negative to fill into bellman for algo
          Here "arbitary large score" means getting a positive edge cycle
          but since we make all the edegs negative so we have to search for
          a negative edge cycle*/
        adj[i] = {a-1, b-1, -1*c};
    }
    Solution sl;
    cout<<sl.findMaxPath(n, adj)<<endl;
    return 0;
}

