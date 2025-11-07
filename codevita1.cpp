#include <bits/stdc++.h>
using namespace std;

bool validMove(int anchor, int offset, bool horizontal, const vector<string>& grid, int R, int C, int len) {
    if (horizontal) {
        if (offset < 0 || offset + len > C) return false;
        for (int k = 0; k < len; ++k)
            if (grid[anchor][offset + k] == 'B') return false;
        return true;
    } else {
        if (offset < 0 || offset + len > R) return false;
        for (int k = 0; k < len; ++k)
            if (grid[offset + k][anchor] == 'B') return false;
        return true;
    }
}

struct Node {
    bool horizontal;
    int a, b;
};

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (auto& row : grid) cin >> row;

    vector<pair<int, int>> src;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (grid[i][j] == 'l')
                src.emplace_back(i, j);

    int len = src.size();
    set<int> sr, sc;
    for (auto& [r, c] : src) {
        sr.insert(r);
        sc.insert(c);
    }

    bool startH;
    int baseA, baseB;
    if (sr.size() == 1) {
        startH = true;
        baseA = *sr.begin();
        baseB = *sc.begin();
    } else {
        startH = false;
        baseA = *sc.begin();
        baseB = *sr.begin();
    }

    vector<pair<int, int>> dst;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (grid[i][j] == 'L')
                dst.emplace_back(i, j);

    set<int> dr, dc;
    for (auto& [r, c] : dst) {
        dr.insert(r);
        dc.insert(c);
    }

    bool goalH;
    int goalA, goalB;
    if (dr.size() == 1) {
        goalH = true;
        goalA = *dr.begin();
        goalB = *dc.begin();
    } else {
        goalH = false;
        goalA = *dc.begin();
        goalB = *dr.begin();
    }

    vector<vector<vector<int>>> dist(2, vector<vector<int>>(16, vector<int>(16, -1)));
    queue<Node> q;

    int startIdx = startH ? 0 : 1;
    dist[startIdx][baseA][baseB] = 0;
    q.push({startH, baseA, baseB});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int d = dist[cur.horizontal ? 0 : 1][cur.a][cur.b];
        if (cur.horizontal) {
            for (auto [da, db] : vector<pair<int,int>>{{0,-1},{0,1},{-1,0},{1,0}}) {
                int na = cur.a + da, nb = cur.b + db;
                if (na >= 0 && na < R && validMove(na, nb, true, grid, R, C, len) && nb + len - 1 < C && dist[0][na][nb] == -1) {
                    dist[0][na][nb] = d + 1;
                    q.push({true, na, nb});
                }
            }
        } else {
            for (auto [da, db] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
                int na = cur.a + da, nb = cur.b + db;
                if (na >= 0 && na < C && validMove(na, nb, false, grid, R, C, len) && nb + len - 1 < R && dist[1][na][nb] == -1) {
                    dist[1][na][nb] = d + 1;
                    q.push({false, na, nb});
                }
            }
        }

        // rotation handling
        auto rotateCheck = [&](int r0, int c0, int r1, int c1) {
            for (int r = r0; r <= r1; ++r)
                for (int c = c0; c <= c1; ++c)
                    if (grid[r][c] == 'B') return false;
            return true;
        };

        if (cur.horizontal) {
            // rotate up
            if (cur.a - (len - 1) >= 0 && rotateCheck(cur.a - (len - 1), cur.b, cur.a, cur.b + len - 1)) {
                int top = cur.a - (len - 1);
                for (int k = 0; k < len; ++k) {
                    int x = cur.b + k;
                    if (dist[1][x][top] == -1 && validMove(x, top, false, grid, R, C, len)) {
                        dist[1][x][top] = d + 1;
                        q.push({false, x, top});
                    }
                }
            }
            // rotate down
            if (cur.a + (len - 1) < R && rotateCheck(cur.a, cur.b, cur.a + len - 1, cur.b + len - 1)) {
                for (int k = 0; k < len; ++k) {
                    int x = cur.b + k;
                    if (dist[1][x][cur.a] == -1 && validMove(x, cur.a, false, grid, R, C, len)) {
                        dist[1][x][cur.a] = d + 1;
                        q.push({false, x, cur.a});
                    }
                }
            }
        } else {
            // rotate left
            if (cur.a - (len - 1) >= 0 && rotateCheck(cur.b, cur.a - (len - 1), cur.b + len - 1, cur.a)) {
                int left = cur.a - (len - 1);
                for (int k = 0; k < len; ++k) {
                    int y = cur.b + k;
                    if (dist[0][y][left] == -1 && validMove(y, left, true, grid, R, C, len)) {
                        dist[0][y][left] = d + 1;
                        q.push({true, y, left});
                    }
                }
            }
            // rotate right
            if (cur.a + (len - 1) < C && rotateCheck(cur.b, cur.a, cur.b + len - 1, cur.a + len - 1)) {
                for (int k = 0; k < len; ++k) {
                    int y = cur.b + k;
                    if (dist[0][y][cur.a] == -1 && validMove(y, cur.a, true, grid, R, C, len)) {
                        dist[0][y][cur.a] = d + 1;
                        q.push({true, y, cur.a});
                    }
                }
            }
        }
    }

    int goalIdx = goalH ? 0 : 1;
    int res = dist[goalIdx][goalA][goalB];
    cout << (res == -1 ? "Impossible" : to_string(res));
    return 0;
}
