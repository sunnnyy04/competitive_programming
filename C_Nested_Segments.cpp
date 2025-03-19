#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pt;

const int N = 300 * 1000 + 13;
int n;
pair<pt, int> segments[N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> segments[i].first.first >> segments[i].first.second;
        segments[i].second = i + 1; 
    }

    sort(segments, segments + n, [](pair<pt, int> a, pair<pt, int> b) {
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    });

    set<pt> activeSegments;

    for (int i = 0; i < n; i++) {
        while (!activeSegments.empty() && activeSegments.begin()->first < segments[i].first.first) {
            activeSegments.erase(activeSegments.begin());
        }

        if (!activeSegments.empty() && (--activeSegments.end())->first >= segments[i].first.second) {
            cout << segments[i].second << " " << (--activeSegments.end())->second << endl;
            return 0;
        }

        activeSegments.insert({segments[i].first.second, segments[i].second});
    }

    cout << "-1 -1" << endl;
    return 0;
}
