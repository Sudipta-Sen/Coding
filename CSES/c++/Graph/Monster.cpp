#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int x, y, t;
    node(int a=0, int b=0, int t1=0) {
        x=a;
        y=b;
        t=t1;
    }
};

class Solution {
    vector<vector<int>> paths;
public:
    string findPath(vector<int> start, vector<vector<char>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>> monsterTime(m, vector<int>(n,INT_MAX));
        vector<vector<node>> parent(m, vector<node>(n));
        paths = vector<vector<int>>{{1, 0, 'D'-'A'}, {-1,0,'U'-'A'}, {0, -1, 'L'-'A'}, {0, 1, 'R'-'A'}};
        flowMonster(grid, monsterTime);
        vector<int> res = findEscape(start, grid, monsterTime, parent);
        if(res[0]==-1) return "";
        return findDirections(res[0], res[1], parent, grid);
    }

    string findDirections(int x, int y, vector<vector<node>>& parent, vector<vector<char>>& grid) {
        string ans="";
        while(grid[x][y]!='A') {
            int mx = parent[x][y].x;
            int my = parent[x][y].y;
            ans += (parent[x][y].t+'A');
            x = mx;
            y = my;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> findEscape(vector<int> start,vector<vector<char>>& grid, vector<vector<int>>& monsterTime, vector<vector<node>>& parent) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<node> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                node t = q.front();
                q.pop();
                if(t.x==0 || t.x==m-1 || t.y==0 || t.y==n-1) {
                    return {t.x, t.y};
                }
                for(auto p:paths) {
                    int mx = t.x+p[0];
                    int my = t.y+p[1];
                    if(isValid(mx, my, t.t+1, grid, monsterTime) && !visited[mx][my]) {
                        visited[mx][my] = true;
                        q.push({mx, my, t.t+1});
                        parent[mx][my] = {t.x, t.y, p[2]};
                    }
                }
            }
        }
        return {-1,-1};
    }

    bool isValid(int x, int y, int t, vector<vector<char>>& grid, vector<vector<int>>& monsterTime) {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]=='#') return false;
        if(monsterTime[x][y]<=t) return false;
        return true;
    }

    void flowMonster(vector<vector<char>>& grid, vector<vector<int>>& monsterTime) {
        //cout<<"Monster Flow In"<<endl;
        queue<node> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='M') {
                    monsterTime[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        //cout<<q.size()<<endl;
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                node t = q.front();
                q.pop();
                for(auto p:paths) {
                    int mx = p[0]+t.x;
                    int my = p[1]+t.y;
                    if(mx<0 || my<0 || mx>=m || my>=n || grid[mx][my]=='#' || monsterTime[mx][my]!=INT_MAX) continue;
                    monsterTime[mx][my] = t.t+1;
                    q.push({mx,my,monsterTime[mx][my]});
                }
            }
        }
    }
};
int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<int> start;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='A') {
                start.push_back(i);
                start.push_back(j);
            }
        }
    }

    //If already at on of the side
    if(start[0]==0 || start[0]==m-1 || start[1]==0 || start[1]==n-1) {
        cout<<"YES"<<endl<<0<<endl;
        return 0;
    }
    Solution sl;
    string ans = sl.findPath(start, grid);
    if(ans=="") cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl<<ans.length()<<endl<<ans<<endl;
    }
    return 0;
}