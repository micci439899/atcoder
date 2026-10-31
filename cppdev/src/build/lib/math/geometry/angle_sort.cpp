
// todo:
// geometryのより一般的な処理を書いたファイルを用意したい
// 内積、直行か、平行か、一般化（n次元）など...

#include <bits/stdc++.h>
using namespace std;

// クロス積（外積）
// 2次元座標平面におけるベクトル同士のクロス積におけるz座標相当
long long cross_product(const pair<long long, long long> &a, const pair<long long, long long> &b){
  return a.first * b.second - b.first * a.second;
}

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b){
  // 下半平面にいるか
  // より具体的には、y座標が0未満もしくはx軸上でx座標が負
  // （x軸上からの反時計回りでの角度を考えたとき、半開区間）
  bool is_low_a = a.second < 0 || (a.second == 0 && a.first < 0);
  bool is_low_b = b.second < 0 || (b.second == 0 && b.first < 0);

  // どちらかが上でどちらかが下
  // aが上ならaの方が角度が小さい
  if(is_low_a != is_low_b) return !is_low_a;

  // 同じ半平面ならクロス積（のz座標）が大きいときaの方が角度が小さい
  return cross_product(a, b) > 0;
}

// 偏角ソートの確認
// 何故偏角ソートと呼ぶのか不明（複素解析の用語の認識。歴史的経緯があったりして競プロの文脈では慣例的にそう呼ぶようになったのだろう（憶測））
void test_angle_sort() {
  vector<pair<long long, long long>> xy = {
    {1, 1}
    , {2, 0}
    , {-1, -6}
    , {3, 0}
    , {-10, 4}
    , {2, -4}
    , {100, 99}
  };
  sort(xy.begin(), xy.end(), cmp);

  for(int i = 0; i < xy.size(); i++) {
    if(i) cout << " ";
    cout << "(" << xy.at(i).first << ", " << xy.at(i).second << ")";
  }
  cout << endl;
}


int main() {
  test_angle_sort();
  return 0;
}
