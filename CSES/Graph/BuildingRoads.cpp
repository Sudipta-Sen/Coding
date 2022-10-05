#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Standard template for union find
class unionFind {
private:
    int size;
    int *rank, *parent;
public:
    unionFind(int n) {
        size = n;
        rank = new int[n+1];
        parent = new int[n+1];
        for(int i=0; i<=n; i++) {
            rank[i] = 1;
            parent[i] = i; 
        }
    }

    int findParent(int n) {
        if(parent[n]==n) return n;
        return parent[n] = findParent(parent[n]);
    }

    bool isSame(int a, int b) {
        return findParent(a)==findParent(b);
    }

    void unionNode(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa==pb) return;
        size--;
        if(rank[pa]>rank[pb]) {
            parent[pb] = pa;
        } else if (rank[pa]<rank[pb]){
            parent[pa] = pb;
        } else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int getCurSizeOfIndividualParent() {
        return size;
    }
};

class Solution {
public:
    void findPath(int nodes, vector<vector<int>>& edges) {
        unionFind *uf = new unionFind(nodes);
        for(auto e:edges) {
            uf->unionNode(e[0], e[1]);
        }

        //No of roads required to connect all cites is one less than the no of connected components
        int reqEd = uf->getCurSizeOfIndividualParent()-1;
        set<int> st;

        //Get parent of all the connected components
        for(int i=1; i<=nodes; i++) {
            st.insert(uf->findParent(i));
        }
        cout<<reqEd<<endl;
        auto i=st.begin();

        //Connect parents of two connected components
        while(reqEd--) {
            cout<<*i;
            i++;
            cout<<" "<<*i<<endl;
        }
        
        return;
    }
};
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        edges.push_back({a,b});
    }
    Solution sl;
    sl.findPath(n, edges);
    return 0;
}