#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ld;
class Solution {
public:
    void findShortestPath(ld n, vector<vector<pair<ld, ld>>>& adj) {
        vector<ld> dst(n, LLONG_MAX);
        vector<bool> visited(n, false);
        dst[0] = 0;
        priority_queue<vector<ld>, vector<vector<ld>>, greater<vector<ld>>> q;
        q.push({0,0});
        while(!q.empty()) {
            vector<ld> t = q.top();
            q.pop();
            ld cur_node = t[1];

            /*This visited array is the addition to previously done dfs
            as for 2 test cases TLE is coming is not added visited array*/
            if(visited[cur_node]) continue;
            visited[cur_node] = true;
            
            for(auto& ed:adj[cur_node]) {
                if(dst[ed.first]>ed.second+dst[cur_node]) {
                    dst[ed.first]=ed.second+dst[cur_node];
                    q.push({dst[ed.first], ed.first});
                }
            }
        }
        for(int i=0; i<n-1; i++) {
            cout<<dst[i]<<" ";
        }
        cout<<dst[n-1]<<endl;
        return;
    }
};

int main() {
    ld n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<ld, ld>>> adj(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    Solution sl;
    sl.findShortestPath(n, adj);
    return 0;
}