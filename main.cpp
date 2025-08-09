#include <bits/stdc++.h>
using namespace std;

struct Result {
    int moves;
    int snakeHead;
    int snakeTail;
};

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

Result minMovesWithOptimization(vector<pair<int,int>> ladders, vector<pair<int,int>> snakes) {
    int base_moves = bfs_min_moves(ladders, snakes);
    Result best = {base_moves, -1, -1};

    for (int head = 2; head <= 99; head++) {
        for (int tail = 1; tail < head; tail++) {
            auto new_snakes = snakes;
            new_snakes.push_back({head, tail});
            int moves = bfs_min_moves(ladders, new_snakes);
            if (moves != -1 && moves < best.moves) {
                best = {moves, head, tail};
            }
        }
    }
    return best;
}

int main() {
    vector<pair<int,int>> ladders = {{3, 90}, {56, 76}};
    vector<pair<int,int>> snakes = {{99, 10}, {30, 5}};

    Result res = minMovesWithOptimization(ladders, snakes);
    cout << "Minimum moves: " << res.moves << "\n";
    if (res.snakeHead != -1)
        cout << "Optimal extra snake head: " << res.snakeHead << ", tail: " << res.snakeTail << "\n";
}
