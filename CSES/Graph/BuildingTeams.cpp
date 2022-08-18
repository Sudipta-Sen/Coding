#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void buildTeam(int nodes, vector<vector<int>>& adj) {
        vector<int> colors(nodes, -1);
        bool isPossible=true;
        for(int i=0; i<nodes; i++) {
            if(colors[i]==-1) {
                if(!colorGraph(i, nodes, colors, adj)) {
                    isPossible = false;
                    break;
                }
            }
        }
        if(!isPossible) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        for(int i=0; i<nodes-1; i++) {
            cout<<colors[i]+1<<" ";
        }
        cout<<colors[nodes-1]+1<<endl;
        return;
    }

    bool colorGraph(int node, int n, vector<int>& colors, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        colors[node] = 1;

        while(!q.empty()) {
            int cur = q.front();
            int cl = colors[cur];
            q.pop();
            for(auto nd:adj[cur]) {
                if(colors[nd]!=-1) {
                    if(colors[nd]==cl) return false;
                } else {
                    colors[nd] = 1-cl;
                    q.push(nd);
                }
            }
        }
        return true;
    }
};
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    Solution sl;
    sl.buildTeam(n, adj);
}