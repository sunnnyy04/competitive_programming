#include <bits/stdc++.h>
using namespace std;

struct EdgeInfo {
    bool horiz;
    double coord;
};

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> poly(n);
    for (auto &pt : poly) cin >> pt.first >> pt.second;

    // Determine polygon orientation
    double signedArea = 0;
    for (int i = 0; i < n; ++i) {
        int nxt = (i + 1) % n;
        signedArea += poly[i].first * poly[nxt].second - poly[nxt].first * poly[i].second;
    }
    if (signedArea < 0) reverse(poly.begin(), poly.end());

    // Compute side lengths
    vector<double> sides(n);
    for (int i = 0; i < n; ++i) {
        double dx = poly[(i + 1) % n].first - poly[i].first;
        double dy = poly[(i + 1) % n].second - poly[i].second;
        sides[i] = hypot(dx, dy);
    }

    double bestVol = 0.0;
    for (int t = 0; t <= 250; ++t) {
        double h = 0.1 * t;
        bool ok = true;
        for (auto len : sides) {
            if (len - 2 * h < 0.1 - 1e-9) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        vector<EdgeInfo> edges(n);
        for (int i = 0; i < n; ++i) {
            double x1 = poly[i].first, y1 = poly[i].second;
            double x2 = poly[(i + 1) % n].first, y2 = poly[(i + 1) % n].second;
            double dx = x2 - x1, dy = y2 - y1;
            bool isHoriz = fabs(dy) < 1e-9;
            double shiftX = 0, shiftY = 0;

            if (isHoriz) {
                shiftY = (dx > 0 ? h : -h);
                edges[i] = {true, y1 + shiftY};
            } else {
                shiftX = (dy > 0 ? -h : h);
                edges[i] = {false, x1 + shiftX};
            }
        }

        vector<pair<double, double>> shifted(n);
        for (int i = 0; i < n; ++i) {
            int prev = (i + n - 1) % n;
            auto L1 = edges[prev], L2 = edges[i];
            double x, y;
            if (L1.horiz) {
                y = L1.coord;
                x = L2.coord;
            } else {
                x = L1.coord;
                y = L2.coord;
            }
            shifted[i] = {x, y};
        }

        // Compute area
        double area = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += shifted[i].first * shifted[j].second - shifted[j].first * shifted[i].second;
        }
        area = fabs(area) / 2.0;

        if (area > 1e-6) {
            double vol = area * h;
            bestVol = max(bestVol, vol);
        }
    }

    printf("%.2f", bestVol);
    return 0;
}
