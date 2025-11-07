#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    bool operator<(const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};

bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool pointOnLine(Point p, Point a, Point b) {
    Point d1 = b - a, d2 = p - a;
    return d1.x * d2.y == d1.y * d2.x && onSegment(a, p, b);
}

Point rotate90CCW(Point c, Point p) {
    return Point(c.x - (p.y - c.y), c.y + (p.x - c.x));
}

int cheb(Point a, Point b) { return max(abs(a.x - b.x), abs(a.y - b.y)); }

void raster(set<Point>& s, Point a, Point b) {
    int x0 = a.x, y0 = a.y, x1 = b.x, y1 = b.y;
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = dx - dy;
    while (true) {
        s.insert(Point(x0, y0));
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= -dy) { err -= dy; x0 += sx; }
        if (e2 <= dx)  { err += dx; y0 += sy; }
    }
}

// Find intersection of two segments
bool segIntersect(Point a, Point b, Point c, Point d, Point& inter) {
    long long d1x = b.x - a.x, d1y = b.y - a.y;
    long long d2x = d.x - c.x, d2y = d.y - c.y;
    long long den = d1x * d2y - d1y * d2x;
    if (den == 0) return false;
    long long tnum = (c.x - a.x) * d2y - (c.y - a.y) * d2x;
    long long unum = (c.x - a.x) * d1y - (c.y - a.y) * d1x;
    if (den < 0) { tnum = -tnum; unum = -unum; den = -den; }
    if (tnum < 0 || tnum > den || unum < 0 || unum > den) return false;
    inter.x = a.x + (d1x * tnum) / den;
    inter.y = a.y + (d1y * tnum) / den;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<Point,Point>> seg(n);
    for (int i = 0; i < n; ++i) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        seg[i] = {Point(x1,y1), Point(x2,y2)};
    }
    Point src, dst; cin>>src.x>>src.y>>dst.x>>dst.y;

    // Collect all possible star centers: endpoints + intersections
    set<Point> candidates;
    for (auto& s : seg) {
        candidates.insert(s.first);
        candidates.insert(s.second);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            Point inter;
            if (segIntersect(seg[i].first, seg[i].second, seg[j].first, seg[j].second, inter)) {
                candidates.insert(inter);
            }
        }
    }

    vector<Point> centre;
    vector<vector<pair<Point,Point>>> starSeg;
    map<Point,int> centreId;
    int id = 0;

    for (auto& p : candidates) {
        vector<pair<Point,Point>> inc;
        for (auto& s : seg) {
            if (pointOnLine(p, s.first, s.second)) {
                inc.push_back(s);
            }
        }
        if (inc.size() >= 2) {
            centre.push_back(p);
            starSeg.push_back(move(inc));
            centreId[p] = id++;
        }
    }

    int N = centre.size();
    if (N == 0) { cout << cheb(src,dst); return 0; }

    vector<set<Point>> reachable(N);
    for (int i = 0; i < N; ++i) {
        set<Point>& S = reachable[i];
        for (int rot = 0; rot < 4; ++rot) {
            set<Point> cur;
            for (auto [a,b] : starSeg[i]) {
                Point p1 = a, p2 = b;
                for (int k = 0; k < rot; ++k) {
                    p1 = rotate90CCW(centre[i], p1);
                    p2 = rotate90CCW(centre[i], p2);
                }
                raster(cur, p1, p2);
            }
            for (auto& p : cur) S.insert(p);
        }
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            bool conn = false;
            for (auto& p : reachable[i]) {
                if (reachable[j].count(p)) { conn = true; break; }
            }
            if (conn) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<int> start;
    for (int i = 0; i < N; ++i)
        if (reachable[i].count(src)) start.push_back(i);
    if (start.empty()) { cout << cheb(src,dst) ; return 0; }

    vector<int> dist(N, -1);
    queue<int> q;
    for (int s : start) {
        dist[s] = 1;
        q.push(s);
    }
    int ans = INT_MAX;
    bool found = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (reachable[u].count(dst)) {
            ans = min(ans, dist[u]);
            found = true;
        }
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (found) {
        cout << ans;
    } else {
        set<Point> all;
        vector<bool> vis(N, false);
        queue<int> qq;
        for (int s : start) { qq.push(s); vis[s] = true; }
        while (!qq.empty()) {
            int u = qq.front(); qq.pop();
            for (auto& p : reachable[u]) all.insert(p);
            for (int v : g[u])
                if (!vis[v]) { vis[v] = true; qq.push(v); }
        }
        int best = INT_MAX;
        for (auto& p : all) best = min(best, cheb(p, dst));
        cout << best;
    }
    return 0;
}