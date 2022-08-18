#include<bits/stdc++.h>
#include<iostream>
typedef long long ll;
using namespace std;


//Solution: https://www.youtube.com/watch?v=kZfm68XKC58
class Solution{
public:
    void findNegCycle(int n, vector<vector<int>>& adj) {
        vector<int> parent(n+1);
        vector<ll> dst(n+1, 1e15);
        dst[0] = dst[1] = 0;
        int x=-1;
        for(int i=1; i<=n; i++) {
            x = -1;
            for(auto ed:adj) {
                //cout<<"Edge: "<<ed[0]<<" "<<ed[1]<<endl;
                if(dst[ed[1]]>dst[ed[0]]+ed[2]) {
                    //cout<<"Change"<<endl;
                    dst[ed[1]] = dst[ed[0]]+ed[2];
                    parent[ed[1]] = ed[0]; //Store the parent node
                    x = ed[1];
                }
            }
        }
        if(x==-1) {
            cout<<"NO"<<endl;
            return;
        }

        //Find a node which belongs to the cycle
        for(int i=1; i<n; i++) x = parent[x];

        //Track back the cycle
        vector<int> temp;
        int st = x;
        do {
            temp.push_back(st);
            st = parent[st];
        } while(st!=x);
        temp.push_back(x);
        cout<<"YES"<<endl;
        for(int i=temp.size()-1; i>0; i--) {
            cout << temp[i]<<" ";
        }
        cout<<temp[0]<<endl;
        return;
    }
};

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> adj(m);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[i] = {a, b, c};
    } 
    Solution sl;
    sl.findNegCycle(n, adj);
    return 0;
}