#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
    ll countRooms(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        ll count=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j]=='.') {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }

    void dfs (int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]!='.' || visited[i][j]) return;

        visited[i][j] = true;
        dfs(i+1, j, visited, grid);
        dfs(i-1, j, visited, grid);
        dfs(i, j+1, visited, grid);
        dfs(i, j-1, visited, grid);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sl;
    cout<<sl.countRooms(grid)<<endl;
    return 0;
}