#include <utility>
#include <vector>

// todo:
// geometryのより一般的な処理
// 内積、直行か、平行か、一般化（n次元）など...
struct Geometry {

  // 傾き（slope, gradient）
  static std::pair<long long, long long> slope(std::pair<long long, long long> p1, std::pair<long long, long long> p2) {
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;

    if(dx == 0) {
      dx = 0;
      dy = 1;
    } else if(dy == 0) {
      dx = 1;
      dy = 0;
    } else {
      if(dx < 0) {
        dx *= -1;
        dy *= -1;
      }
      // std::なしの場合、int換算されてしまう可能性あり
      // （std::なしでも動くことに注意する）
      long long g = std::gcd(std::abs(dx), std::abs(dy));
      dx /= g;
      dy /= g;
    }
    return {dx, dy};
  }


  // クロス積（外積）
  // 2次元座標平面におけるベクトル同士のクロス積におけるz座標相当
  static long long cross_product(const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
    return a.first * b.second - b.first * a.second;
  }
  // 外積
  // oを始点としたとき版
  static long long cross_product(const std::pair<long long, long long> &o, const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
    return (o.first - a.first) * (o.second - b.second) - (o.second - a.second) * (o.first - b.first);
  }

  static bool angle_cmp(const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
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

  // 凸包アルゴリズム
  // monotone chain
  // 下記参考
  // https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
  static std::vector<std::pair<long long, long long>> convex_hull(std::vector<std::pair<long long, long long>> p) {
    int n = p.size();

    std::vector<std::pair<long long, long long>> res(2*n);

    sort(p.begin(), p.end());

    // lower hull
    int k = 0;
    for(int i = 0; i < n; i++){
      while(
        k >= 2
        && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
      ){
        res.pop_back();
        k--;
      }
      res.at(k) = p.at(i);
      k++;
    }

    // upper hull
    int t = k + 1;
    for(int i = n-2; i >= 0; i--) {
      while(
        k >= t
        && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
      ){
        res.pop_back();
        k--;
      }
      res.at(k) = p.at(i);
      k++;
    }

    res.pop_back();
    k--;
    res.resize(k);
    return res;
  }
};
