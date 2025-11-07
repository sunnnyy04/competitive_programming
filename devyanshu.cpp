#include <bits/stdc++.h>
using namespace std;

// Generate all valid cuboid nets (all 11 cube nets generalize here)
const vector<vector<pair<int,int>>> cuboidNets = {
    {{0,0},{1,0},{2,0},{1,1},{1,2},{1,3}}, // T shape
    {{0,0},{1,0},{2,0},{0,1},{1,1},{2,1}}, // 2x3 rectangle (flat)
    {{0,0},{1,0},{2,0},{3,0},{2,1},{2,2}}, // long T
    {{0,0},{1,0},{2,0},{1,1},{0,1},{0,2}}, // L-shape variant
    {{0,0},{1,0},{1,1},{1,2},{2,2},{3,2}}, // zigzag
    {{0,0},{1,0},{2,0},{1,1},{1,-1},{1,-2}}, // tall cross
    {{0,0},{0,1},{1,1},{2,1},{2,2},{3,2}}, // slanted S
    {{0,0},{1,0},{2,0},{0,1},{0,2},{0,3}}, // vertical bar
    {{0,0},{1,0},{1,1},{2,1},{2,2},{3,2}}, // snake
    {{0,0},{1,0},{1,1},{1,2},{2,2},{3,2}}, // inverted snake
    {{0,0},{1,0},{2,0},{3,0},{3,1},{3,2}}  // long L
};

vector<pair<int,int>> normalize(vector<pair<int,int>> cells) {
    int minx=1e9, miny=1e9;
    for(auto &c:cells) minx=min(minx,c.first), miny=min(miny,c.second);
    for(auto &c:cells) c.first-=minx, c.second-=miny;
    sort(cells.begin(),cells.end());
    return cells;
}

bool matchesNet(vector<pair<int,int>> layout) {
    layout = normalize(layout);
    for(auto net : cuboidNets) {
        net = normalize(net);
        for(int r=0;r<4;r++){
            vector<pair<int,int>> rot = layout;
            for(auto &p:rot){
                int x=p.first, y=p.second;
                p.first=y; p.second=-x; // rotate 90°
            }
            rot = normalize(rot);
            if(rot==net) return true;
            layout=rot;
        }
    }
    return false;
}

int main(){
    int N; cin>>N;
    set<pair<pair<int,int>,pair<int,int>>> edges;
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        if(x1>x2 || y1>y2) swap(x1,x2), swap(y1,y2);
        edges.insert({{x1,y1},{x2,y2}});
    }

    vector<pair<int,int>> squares;
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            if(edges.count({{i,j},{i+1,j}}) &&
               edges.count({{i,j+1},{i+1,j+1}}) &&
               edges.count({{i,j},{i,j+1}}) &&
               edges.count({{i+1,j},{i+1,j+1}}))
                squares.push_back({i,j});
        }
    }

    if(squares.size()!=6){ cout<<0; return 0; }

    if(matchesNet(squares)) {
        // compute cuboid dimensions
        int minx=INT_MAX,maxx=INT_MIN,miny=INT_MAX,maxy=INT_MIN;
        for(auto &c:squares){
            minx=min(minx,c.first); maxx=max(maxx,c.first);
            miny=min(miny,c.second); maxy=max(maxy,c.second);
        }
        int a = maxx-minx+1;
        int b = maxy-miny+1;
        int c = 1; // thickness (each face is 1 unit)
        cout << a*b*c;
    } else cout<<0;
    return 0;
}
