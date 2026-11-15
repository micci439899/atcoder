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
  angle_sort_test();
  convex_hull_test();
}

int main() {
  geometry_test();
  return 0;
}