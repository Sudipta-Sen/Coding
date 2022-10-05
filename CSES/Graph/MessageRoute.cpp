#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSmallestRoute(int nodes, vector<vector<int>>& adj) {
        vector<bool> visited(nodes, false);
        vector<int> parent(nodes, -1);
        queue<int> q;
        bool dstFound = false;

        q.push(0);
        visited[0] = true;
        while(!q.empty() && !dstFound) {
            int cur = q.front();
            if(cur==nodes-1) {
                dstFound = true;
                break;
            }
            q.pop();
            for(auto nd:adj[cur]) {
                if(!visited[nd]) {
                    visited[nd] = true;
                    parent[nd] = cur;
                    q.push(nd);
                }
            }
        }
        if(!dstFound) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        //Backtrack using parent node to find the path
        vector<int> temp;
        int i = nodes-1;
        while(i!=-1) {
            temp.push_back(i+1);
            i = parent[i];
        }

        //Print the path
        cout<<temp.size()<<endl;
        for(i=temp.size()-1; i>=0; i--) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
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
    sl.printSmallestRoute(n, adj);
    return 0;
}