#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeMyTrip(int nodes, vector<vector<int>>& adj) {
        vector<int> parent(nodes, -1), temp;
        vector<bool> visited(nodes, false);
        int tripStart=-1, tripEnd=-1;
        for(int i=0; i<nodes && tripStart==-1; i++) {
            if(!visited[i]) {
                parent[i] = i;
                dfs(i, tripStart, tripEnd, parent, visited, adj);
            }
        }
        if(tripStart==-1) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }

        //Retrive cycle and print
        //
        cout<<tripEnd<<" "<<tripStart<<endl;
        int i=tripStart;
        while(i!=tripEnd) {
            temp.push_back(i+1);
            i = parent[i];
        }
        temp.push_back(tripEnd+1);
        temp.push_back(tripStart+1);
        cout<<temp.size()<<endl;
        for(int i=0; i<temp.size()-1; i++) {
            cout<<temp[i]<<" ";
        }
        cout<<temp[temp.size()-1]<<endl;
        return;
    }

    void dfs(int node, int& tripStart, int& tripEnd, vector<int>& parent, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for(auto nd:adj[node]) {
            if(!visited[nd]) {
                parent[nd] = node;
                dfs(nd, tripStart, tripEnd, parent, visited, adj);
            } else if(nd!=parent[node]){
                tripStart = node;
                tripEnd = nd;
            }
            if(tripStart!=-1) return;
        }
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        //Remove Self loop
        if(a==b) continue;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    Solution sl;
    sl.makeMyTrip(n, adj);
    return 0;
}