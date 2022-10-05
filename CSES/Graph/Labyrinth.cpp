#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class node{
public:
    int x, y;
    char ch;
    node(int i=0, int j=0, char c='a') {
        x=i;
        y=j;
        ch = c;
    }

};

//This is a problem of bfs traversal

class Solution {
    vector<vector<int>> paths;
public:
    string findPath(vector<vector<char>>& grid, vector<int>& start, vector<int>& end) {
        int n=grid.size(), m=grid[0].size();
        paths = vector<vector<int>>{{0, -1, 'L'-'A'}, {0, 1, 'R'-'A'}, {-1,0,'U'-'A'}, {1, 0, 'D'-'A'}};
        vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
        vector<vector<node>> parent(n, vector<node>(m)); //store parent node and direction for direction

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        bool dstFound=false;
        while(!q.empty() && !dstFound) {
            int k = q.size();
            while(k-- && !dstFound) {
                pair<int, int> t = q.front();
                if(grid[t.first][t.second]=='B') {
                    dstFound = true;
                    break;
                }
                q.pop();
                for(auto p:paths) {
                    int mx = t.first + p[0];
                    int my = t.second + p[1];
                    char dir = p[2]+'A';
                    if(mx<0 || my<0 || mx>=grid.size() || my>=grid[0].size() || grid[mx][my]=='#' || visited[mx][my]) continue;
                    parent[mx][my] = {t.first, t.second, dir};
                    visited[mx][my] = true;
                    q.push({mx, my});
                }
            }
        }

        //If destination not found then return empty string
        if(!dstFound) return "";

        //Destination found, then backtrack
        string ans="";
        int i=end[0], j=end[1], mi, mj;
        while(grid[i][j]!='A') {
            mi = parent[i][j].x;
            mj = parent[i][j].y;
            ans += parent[i][j].ch;
            i = mi;
            j = mj;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<int> start(2), end(2);

    //Grid Input
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='A') start={i,j};
            if(grid[i][j]=='B') end={i,j};
        }
    }
    Solution sl;
    string res = sl.findPath(grid, start, end);
    if(res=="") cout<<"NO"<<endl;
    else cout<<"YES"<<endl<<res.length()<<endl<<res<<endl;
    return 0;
}