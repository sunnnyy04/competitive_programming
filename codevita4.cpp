#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;
char cube[6][MAXN][MAXN];
char backup[6][MAXN][MAXN];
int N, K;

vector<string> instructions;

void copy_cube() {
    for (int f = 0; f < 6; ++f)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cube[f][i][j] = backup[f][i][j];
}

void rotate_face(int f, bool clockwise) {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[f][i][j];
    if (clockwise) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cube[f][i][j] = temp[N-1-j][i];
    } else {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cube[f][i][j] = temp[j][N-1-i];
    }
}

void turn_left() {
    // front -> left, left -> back, back -> right, right -> front
    char temp[MAXN][MAXN];
    // Save front
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[3][i][j]; // front
    // front = right
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[3][i][j] = cube[5][i][j];
    // right = back
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[5][i][j] = cube[1][i][j];
    // back = left
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[1][i][j] = cube[4][i][j];
    // left = temp (old front)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[4][i][j] = temp[i][j];
    // top rotate right
    rotate_face(2, true);
    // base rotate left
    rotate_face(0, false);
}

void turn_right() {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[3][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[3][i][j] = cube[4][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[4][i][j] = cube[1][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[1][i][j] = cube[5][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[5][i][j] = temp[i][j];
    rotate_face(2, false);
    rotate_face(0, true);
}

void rotate_front() {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[3][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[3][i][j] = cube[0][N-1-j][i]; // base -> front
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[0][i][j] = cube[1][N-1-j][i]; // back -> base
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[1][i][j] = cube[2][N-1-j][i]; // top -> back
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[2][i][j] = temp[N-1-j][i];   // front -> top
    rotate_face(4, true);  // left rotate right
    rotate_face(5, false); // right rotate left
}

void rotate_back() {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[3][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[3][i][j] = cube[2][j][N-1-i]; // top -> front
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[2][i][j] = cube[1][j][N-1-i]; // back -> top
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[1][i][j] = cube[0][j][N-1-i]; // base -> back
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[0][i][j] = temp[j][N-1-i];   // front -> base
    rotate_face(4, false);
    rotate_face(5, true);
}

void rotate_left() {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[2][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[2][i][j] = cube[4][j][N-1-i]; // left -> top
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[4][i][j] = cube[0][j][N-1-i]; // base -> left
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[0][i][j] = cube[5][j][N-1-i]; // right -> base
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[5][i][j] = temp[j][N-1-i];   // top -> right
    rotate_face(3, false); // front rotate left
    rotate_face(1, true);  // back rotate right
}

void rotate_right() {
    char temp[MAXN][MAXN];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = cube[2][i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[2][i][j] = cube[5][N-1-j][i]; // right -> top
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[5][i][j] = cube[0][N-1-j][i]; // base -> right
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[0][i][j] = cube[4][N-1-j][i]; // left -> base
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cube[4][i][j] = temp[N-1-j][i];   // top -> left
    rotate_face(3, true);
    rotate_face(1, false);
}

void rotate_row_col(const string& side, int idx, const string& dir) {
    int f = -1;
    if (side == "base") f = 0;
    else if (side == "back") f = 1;
    else if (side == "top") f = 2;
    else if (side == "front") f = 3;
    else if (side == "left") f = 4;
    else if (side == "right") f = 5;

    bool is_row = (dir == "left" || dir == "right");
    bool clockwise = (dir == "right" || dir == "down");

    if (is_row) {
        // rotate row idx-1 of face f
        char temp[MAXN];
        for (int j = 0; j < N; ++j) temp[j] = cube[f][idx-1][j];
        if (clockwise) {
            for (int j = 0; j < N; ++j)
                cube[f][idx-1][j] = temp[(j + N - 1) % N];
        } else {
            for (int j = 0; j < N; ++j)
                cube[f][idx-1][j] = temp[(j + 1) % N];
        }
    } else {
        // rotate column idx-1
        char temp[MAXN];
        for (int i = 0; i < N; ++i) temp[i] = cube[f][i][idx-1];
        if (clockwise) {
            for (int i = 0; i < N; ++i)
                cube[f][i][idx-1] = temp[(i + N - 1) % N];
        } else {
            for (int i = 0; i < N; ++i)
                cube[f][i][idx-1] = temp[(i + 1) % N];
        }
    }
}

void execute(const string& inst) {
    stringstream ss(inst);
    string token;
    vector<string> parts;
    while (ss >> token) parts.push_back(token);

    if (parts[0] == "turn") {
        if (parts[1] == "left") turn_left();
        else turn_right();
    } else if (parts[0] == "rotate") {
        if (parts[1] == "front") rotate_front();
        else if (parts[1] == "back") rotate_back();
        else if (parts[1] == "left") rotate_left();
        else rotate_right();
    } else {
        string side = parts[0];
        int idx = stoi(parts[1]);
        string dir = parts[2];
        rotate_row_col(side, idx, dir);
    }
}

bool is_uniform(int f) {
    char c = cube[f][0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (cube[f][i][j] != c) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    instructions.resize(K);
    
    // Read 6 faces
    for (int f = 0; f < 6; ++f) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> backup[f][i][j];
            }
        }
    }
    
    // Read instructions
    string line;
    getline(cin >> ws, line); // consume newline
    for (int i = 0; i < K; ++i) {
        getline(cin, instructions[i]);
    }
    
    vector<pair<int, int>> solutions;
    
    for (int skip = 0; skip < K; ++skip) {
        copy_cube();
        for (int i = 0; i < K; ++i) {
            if (i == skip) continue;
            execute(instructions[i]);
        }
        for (int f = 0; f < 6; ++f) {
            if (is_uniform(f)) {
                solutions.emplace_back(skip, f);
            }
        }
    }
    
    if (solutions.size() == 1) {
        cout << instructions[solutions[0].first] << '\n';
    } else if (solutions.empty()) {
        cout << "Not Possible\n";
    } else {
        cout << "Faulty\n";
    }
    
    return 0;
}