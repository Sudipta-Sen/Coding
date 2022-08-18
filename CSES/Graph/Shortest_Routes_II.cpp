#include<iostream>
#include<bits/stdc++.h>
typedef long long ld;
using namespace std;

class Solution {
public:
    void findAllPairShorestPath(ld n, vector<vector<ld>>& dst, vector<vector<ld>>& q) {

        //Always put k outside, otherwise it will give wrong ans
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(k!=j && k!=i && dst[i][k]!=-1 && dst[k][j]!=-1 && (dst[i][j]==-1 || dst[i][j]>dst[i][k]+dst[k][j])) {
                        dst[i][j]=dst[i][k]+dst[k][j];
                    }
                }
            }
        }
        for(int i=0; i<q.size(); i++) {
            cout<<dst[q[i][0]][q[i][1]]<<endl;
        }
        return;
    }
};

int main() {
    ld n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector<vector<ld>> dst(n, vector<ld>(n,-1));
    vector<vector<ld>> query;
    for(int i=0; i<n; i++) dst[i][i]=0;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;

        //Always do this if not said that there can be atmost one edge between two nodes
        if(dst[a-1][b-1]!=-1) {
            dst[a-1][b-1] = min(c, dst[a-1][b-1]);
            dst[b-1][a-1] = min(c, dst[b-1][a-1]);
        } else {
            dst[a-1][b-1] = c;
            dst[b-1][a-1] = c;
        }
    }

    for(int i=0; i<q; i++) {
        cin >> a >> b;
        query.push_back({a-1,b-1});
    }
    Solution sl;
    sl.findAllPairShorestPath(n, dst, query);
    return 0;
}