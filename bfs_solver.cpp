#include <bits/stdc++.h>
using namespace std;

int bfs_min_moves(vector<pair<int,int>> ladders, vector<pair<int,int>> snakes) {
    vector<int> board(101, -1);
    for (auto &l : ladders) board[l.first] = l.second;
    for (auto &s : snakes) board[s.first] = s.second;

    vector<bool> visited(101, false);
    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [pos, dist] = q.front();
        q.pop();
        if (pos == 100) return dist;
        for (int dice = 1; dice <= 6; dice++) {
            int next = pos + dice;
            if (next > 100) continue;
            if (board[next] != -1) next = board[next];
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, dist + 1});
            }
        }
    }
    return -1;
}
