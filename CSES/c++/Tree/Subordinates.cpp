#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void findSubordinates(vector<int>& booses) {
        int n=booses.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n);
        for(int i=1; i<n; i++) {
            adj[booses[i]].push_back(i);
        }
        dfs(1, adj, ans);
        for(int i=1; i<n-1; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<ans[n-1]<<endl;
        return;
    }

    int dfs(int node, vector<vector<int>>& adj, vector<int>& ans) {
        int count = 0;
        for(auto nd:adj[node]) {
            count += dfs(nd, adj, ans);
        }
        ans[node] = count;
        return count+1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> vect(n+1);
    for(int i=2; i<=n; i++) {
        cin >> vect[i];
    }
    Solution sl;
    sl.findSubordinates(vect);
}