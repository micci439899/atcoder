#include <bits/stdc++.h>
using namespace std;

// f(n, m, a, b) := \sum_{i=0}^{n-1} \lfloor{\frac{ai+b}{m}} \rfloor
// 元ネタは下記
// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// C++だと負の数のときの場合分けが必要（本当はAC Libraryを使うのが良い）
// a = q_1 m + r_1, b = q_2 m + r_2とおく
// q_1 = floor(a/m)
// r_1 = a - qm
// q_2 = floor(b/m)
// r_2 = b - qm
// より
// f(n, m, a, b)
// = \sum_0^{n-1} \lfloor ( \frac{(q_1 m + r_1)i + q_2 m + r_2)}{m} \rfloor 
// = \sum_0^{n-1} (q_1 i + q_2) + \lfloor \frac{r_1 i + r_2}{m} /rfloor
// = q_1 \frac{(n-1)n}{2} + q_2 n + f(n, m, r_1, r_2)
long long floor_sum(long long n, long long m, long long a, long long b){
  long long ans = 0;

  if(a < 0){
    long long q = (a - m + 1) / m;
    long long r = a - q * m;

    ans += q * n * (n - 1) / 2;
    a = r;
  }

  if(a >= m){
    long long q = a / m;
    ans += q * n * (n - 1) / 2;
    a %= m;
  }

  if(b < 0){
    // b = qm + rとおく（aと同じ）
    long long q = (b - m + 1) / m;
    long long r = b - q * m;

    ans += q * n;
    b = r;
  }

  if(b >= m){
    long long q = b / m;
    ans += q * n;
    b %= m;
  }

  if(a == 0){
    return ans;
  }

  long long k = (a * (n-1) + b) / m;
  return ans + n * k - floor_sum(k, a, m, m + a - b - 1);
}

void test_floor_sum() {
  // (1*0+2)/3 + (1*1+2)/3 + (1*2+2)/3 + (1*3+2)/3 + (1*4+2)/3
  // = 0 + 1 + 1 + 1 + 2
  long long x1 = floor_sum(5, 3, 1, 2);
  cout << x1 << endl;

  // (3*0+7)/5 + (3*1+7)/5 + (3*2+7)/5 + (3*3+7)/5 + (3*4+7)/5
  // = 1 + 2 + 2 + 3 + 3
  long long x2 = floor_sum(5, 5, 3, 7);
  cout << x2 << endl;

  // (0*(-2)-3)/5 + (1*(-2)-3)/5 + (2*(-2)-3)/5 + (3*(-2)-3)/5 + (4*(-2)-3)/5
  // = -1 - 1 - 2 - 2 - 3
  long long x3 = floor_sum(5, 5, -2, -3);
  cout << x3 << endl;

}

int main() {
  test_floor_sum();
  return 0;
}