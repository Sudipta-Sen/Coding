#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
    ll inf = 1e17;
    ll ninf = -inf;
public:
    ll getDiscountedMinCost(int node, vector<vector<pair<ll, ll>>>& adj) {
        vector<ll> discounted(node, inf), full(node, inf);
        vector<vector<int>> visited(node, vector<int>(2,false));
        //weight, node, discount given or not(0 or 1)
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q; 
        q.push({0, 0, 0});
        full[0] = 0;

        while(!q.empty()) {
            vector<ll> t = q.top();
            q.pop();
            int cur_node = t[1];
            if(visited[cur_node][t[2]]) continue;
            visited[cur_node][t[2]] = true;
            for(auto nd:adj[cur_node]) {
                //cupon not used till now
                if(t[2]==0) {
                    if(full[cur_node]!=inf && discounted[nd.first]>full[cur_node]+(nd.second/2)) {
                        discounted[nd.first]=full[cur_node]+(nd.second/2);
                        q.push({discounted[nd.first], nd.first, 1});
                    }
                }
                
                //we will save cupon for latter use
                if(full[cur_node]!=inf && full[nd.first]>full[cur_node]+nd.second) {
                    full[nd.first]=full[cur_node]+nd.second;
                    q.push({full[nd.first], nd.first, 0});
                }

                //cupon already used
                if(discounted[cur_node]!=inf && discounted[nd.first]>discounted[cur_node]+nd.second) {
                    discounted[nd.first]=discounted[cur_node]+nd.second;
                    q.push({discounted[nd.first], nd.first, 1});
                }
            }
        }

        return min(discounted[node-1], full[node-1]);
    }
};

int main() {
    ll n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    Solution sl;
    cout<<sl.getDiscountedMinCost(n, adj)<<endl;
}