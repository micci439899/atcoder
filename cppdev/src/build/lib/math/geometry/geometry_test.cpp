#include <bits/stdc++.h>
#include "geometry.hpp"
using namespace std;

void out(vector<pair<long long, long long>> &xy) {
  for(int i = 0; i < (int)xy.size(); i++) {
    if(i) cout << " ";
    cout << "(" << xy.at(i).first << ", " << xy.at(i).second << ")";
  }
  cout << endl;
}

void out_pair(pair<long long, long long> p) {
  cout << "(" << p.first << ", " << p.second << ")" << endl;
}

void out_slope(Geometry &g, pair<long long, long long> &p0, pair<long long, long long> &p1) {
  pair<long long, long long> sl = g.slope(p0, p1);
  cout << "pairs are" << endl;
  out_pair(p0);
  out_pair(p1);
  cout << "slope is ";
  cout << sl.second << "/" << sl.first << endl;
}

// 傾きテスト
void slope_test() {
  cout << "slope test" << endl;
  Geometry g;

  pair<long long, long long> p0 = {0, 0};
  pair<long long, long long> p1 = {1, 0};
  pair<long long, long long> p2 = {0, 1};
  pair<long long, long long> p3 = {-1, 0};
  pair<long long, long long> p4 = {0, -1};
  pair<long long, long long> p5 = {1, 1};
  pair<long long, long long> p6 = {1e9, 1e9};
  pair<long long, long long> p7 = {1e9-1, 1e9+1};
  pair<long long, long long> p8 = {1e13, 1e14};
  pair<long long, long long> p9 = {1e12, 1e15};
  pair<long long, long long> p10 = {2, 7};
  pair<long long, long long> p11 = {5, 3};

  out_slope(g, p0, p1);
  out_slope(g, p0, p2);
  out_slope(g, p0, p3);
  out_slope(g, p0, p4);
  out_slope(g, p0, p5);
  out_slope(g, p5, p6);
  out_slope(g, p6, p5);
  out_slope(g, p5, p7);
  out_slope(g, p8, p9);
  out_slope(g, p10, p11);
}



// 偏角ソートの確認
// 何故偏角ソートと呼ぶのか不明（複素解析の用語の認識。歴史的経緯があったりして競プロの文脈では慣例的にそう呼ぶようになったのだろう（憶測））
void angle_sort_test() {
  cout << "angle sort test" << endl;
  Geometry g;

  // 原点があると意図しない挙動になる
  vector<pair<long long, long long>> xy = {
    {1, 1}
    , {2, 0}
    , {-1, -6}
    , {3, 0}
    , {-10, 4}
    , {2, -4}
    , {100, 99}
    , {999, 1000}
    // , {0, 0}
    , {0, 1}
    , {-10, 0}
    , {-20, 0}
    , {0, -100}
    , {0, -200}
    , {-1, 1}
    , {-1e9, 1e9-1}
    , {-1e9+1, 1e9}
    , {-1, -1}
    , {-1e9, -1e9+1}
    , {-1e9+1, -1e9}
    , {1, -1}
    , {1e9, -1e9+1}
    , {1e9-1, -1e9}
  };

  cout << "origin" << endl;
  out(xy);
  sort(xy.begin(), xy.end(), g.angle_cmp);

  cout << "sorted" << endl;
  out(xy);

  cout << endl;
}

// 凸包の確認
void convex_hull_test() {
  cout << "convex hull test" << endl;
  Geometry g;
  vector<pair<long long, long long>> xy = {
    {1, 1}
    , {2, 0}
    , {-1, -6}
    , {3, 0}
    , {-10, 4}
    , {2, -4}
    , {100, 99}
    , {999, 1000}
    // , {0, 0}
    , {0, 1}
    , {-10, 0}
    , {-20, 0}
    , {0, -100}
    , {0, -200}
    , {-1, 1}
    , {-1e9, 1e9-1}
    , {-1e9+1, 1e9}
    , {-1, -1}
    , {-1e9, -1e9+1}
    , {-1e9+1, -1e9}
    , {1, -1}
    , {1e9, -1e9+1}
    , {1e9-1, -1e9}
  };

  cout << "origin" << endl;
  out(xy);

  vector<pair<long long, long long>> hull = g.convex_hull(xy); 
  cout << "hull" << endl;
  out(hull);
  cout << endl;
}

void geometry_test() {
  slope_test();
  angle_sort_test();
  convex_hull_test();
}

int main() {
  geometry_test();
  return 0;
}