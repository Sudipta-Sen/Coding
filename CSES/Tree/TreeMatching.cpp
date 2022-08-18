#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxEdges(int nodes, vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> present(nodes+1, vector<int>(2,-1));
        return max(help(1, 0, edges, present), help(1, 1, edges, present));
    }

    int help(int pos, bool isIncluded, vector<vector<int>>& edges, vector<vector<int>>& present) {
        
    }
};

int main() {
    int n, a, b;
    cin >> n;
    vector<vector<int>> edges(n+1, vector<int>()); 
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
    }
    Solution sl;
    cout<<sl.findMaxEdges(n, edges)<<endl;
    return 0;
}