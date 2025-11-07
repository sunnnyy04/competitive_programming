#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<vector<char>>> cube;
map<string, int> f_map = {{"base", 0}, {"back", 1}, {"top", 2}, {"front", 3}, {"left", 4}, {"right", 5}};

void rotate_clock(vector<vector<char>>& f) {
    int n = N;
    vector<vector<char>> nf(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nf[j][n - 1 - i] = f[i][j];
        }
    }
    f = nf;
}

void rotate_ccw(vector<vector<char>>& f) {
    int n = N;
    vector<vector<char>> nf(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nf[n - 1 - j][i] = f[i][j];
        }
    }
    f = nf;
}

void turn_left() {
    auto temp = cube[3];
    cube[3] = cube[5];
    cube[5] = cube[1];
    cube[1] = cube[4];
    cube[4] = temp;
    rotate_clock(cube[2]);
    rotate_ccw(cube[0]);
}

void turn_right() {
    auto temp = cube[3];
    cube[3] = cube[4];
    cube[4] = cube[1];
    cube[1] = cube[5];
    cube[5] = temp;
    rotate_ccw(cube[2]);
    rotate_clock(cube[0]);
}

void rotate_front() {
    auto temp = cube[3];
    cube[3] = cube[2];
    cube[2] = cube[1];
    cube[1] = cube[0];
    cube[0] = temp;
    rotate_clock(cube[4]);
    rotate_ccw(cube[5]);
}

void rotate_back() {
    auto temp = cube[3];
    cube[3] = cube[0];
    cube[0] = cube[1];
    cube[1] = cube[2];
    cube[2] = temp;
    rotate_ccw(cube[4]);
    rotate_clock(cube[5]);
}

void rotate_left() {
    auto temp = cube[4];
    cube[4] = cube[2];
    cube[2] = cube[5];
    cube[5] = cube[0];
    cube[0] = temp;
    rotate_ccw(cube[3]);
    rotate_clock(cube[1]);
}

void rotate_right() {
    auto temp = cube[4];
    cube[4] = cube[0];
    cube[0] = cube[5];
    cube[5] = cube[2];
    cube[2] = temp;
    rotate_clock(cube[3]);
    rotate_ccw(cube[1]);
}

void apply(const string& line) {
    stringstream ss(line);
    string first;
    ss >> first;
    if (first == "turn") {
        string d;
        ss >> d;
        if (d == "left") turn_left();
        else turn_right();
    } else if (first == "rotate") {
        string d;
        ss >> d;
        if (d == "front") rotate_front();
        else if (d == "back") rotate_back();
        else if (d == "left") rotate_left();
        else rotate_right();
    } else {
        // slice
        int num;
        string dir;
        string side = first;
        ss >> num >> dir;
        int f = f_map[side];
        int idx = num - 1;
        if (dir == "left" || dir == "right") {
            // row idx
            vector<char> row(N);
            for (int j = 0; j < N; j++) row[j] = cube[f][idx][j];
            if (dir == "left") {
                char fc = row[0];
                for (int j = 0; j < N - 1; j++) row[j] = row[j + 1];
                row[N - 1] = fc;
            } else {
                char lc = row[N - 1];
                for (int j = N - 1; j > 0; j--) row[j] = row[j - 1];
                row[0] = lc;
            }
            for (int j = 0; j < N; j++) cube[f][idx][j] = row[j];
        } else {
            // column idx
            vector<char> col(N);
            for (int i = 0; i < N; i++) col[i] = cube[f][i][idx];
            if (dir == "up") {
                char fc = col[0];
                for (int i = 0; i < N - 1; i++) col[i] = col[i + 1];
                col[N - 1] = fc;
            } else {
                char lc = col[N - 1];
                for (int i = N - 1; i > 0; i--) col[i] = col[i - 1];
                col[0] = lc;
            }
            for (int i = 0; i < N; i++) cube[f][i][idx] = col[i];
        }
    }
}

bool has_uniform(const vector<vector<vector<char>>>& c) {
    for (int f = 0; f < 6; f++) {
        char ch = c[f][0][0];
        bool uni = true;
        for (int i = 0; i < N && uni; i++) {
            for (int j = 0; j < N && uni; j++) {
                if (c[f][i][j] != ch) {
                    uni = false;
                }
            }
        }
        if (uni) return true;
    }
    return false;
}

bool has_almost_uniform(const vector<vector<vector<char>>>& c) {
    for (int f = 0; f < 6; f++) {
        map<char, int> cnt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt[c[f][i][j]]++;
            }
        }
        int mx = 0;
        for (auto& p : cnt) mx = max(mx, p.second);
        if (mx == N * N - 1) return true;
    }
    return false;
}

int main() {
    cin >> N >> K;
    cube.assign(6, vector<vector<char>>(N, vector<char>(N)));
    for (int f = 0; f < 6; f++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cube[f][i][j];
            }
        }
    }
    vector<string> instr(K);
    for (int i = 0; i < K; i++) {
        string s1;
        cin >> s1;
        if (s1 == "turn" || s1 == "rotate") {
            string s2;
            cin >> s2;
            instr[i] = s1 + " " + s2;
        } else {
            int num;
            string d;
            cin >> num >> d;
            instr[i] = s1 + " " + to_string(num) + " " + d;
        }
    }
    vector<vector<vector<char>>> initial_cube = cube;
    string extra;
    bool no_faulty = false;
    for (int skip = 0; skip < K; skip++) {
        cube = initial_cube;
        for (int j = 0; j < K; j++) {
            if (j == skip) continue;
            apply(instr[j]);
        }
        if (has_uniform(cube)) {
            extra = instr[skip];
            no_faulty = true;
            break;
        }
    }
    if (no_faulty) {
        cout << extra ;
    } else {
        bool faulty = false;
        for (int skip = 0; skip < K; skip++) {
            cube = initial_cube;
            for (int j = 0; j < K; j++) {
                if (j == skip) continue;
                apply(instr[j]);
            }
            if (has_almost_uniform(cube)) {
                extra = instr[skip];
                faulty = true;
                break;
            }
        }
        if (faulty) {
            cout << "Faulty" ;
            cout << extra ;
        } else {
            cout << "Not Possible" ;
        }
    }
    return 0;
}