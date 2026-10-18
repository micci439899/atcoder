# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int X, Y;
  cin >> X >> Y;

  int cnt = 0;
  
  for(int i = 1; i <= 6; i++)for(int j = 1; j <= 6; j++){
    if (i+j >= X || abs(i-j) >= Y){
      cnt++;
    }
  }


  double ans = (double)cnt / (double)36;

  printf("%.11f\n", ans);

  return 0;
}











