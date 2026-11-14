#include <iostream>
#include <iomanip>

void practice() {
  int a = 1<<30;
  int b = 1;
  int c = a+b;
  // 2^31はintの範囲外
  int d = a+a;

  std::cout << a << " + " << b << " = " << c << std::endl;
  std::cout << a << " + " << a << " = " << d << std::endl;

  long long e = 1LL<<62;
  long long f = 1LL;
  long long g = e + f;
  // 2^63はlong longの範囲外
  long long h = e + e;
  int i = 1<<30;
  // 2^62
  // int同士で計算するとint内で計算
  long long j = i*i*4LL;
  long long k = i*((long long)i)*4;
  long long l = (long long)i*i*4;

  std::cout << e << " + " << f << " = " << g << std::endl;
  std::cout << e << " + " << e << " = " << h << std::endl;
  std::cout << i << " * " << i << " * " << 4 << " = " << j << std::endl;
  std::cout << i << " * " << i << " * " << 4 << " = " << k << std::endl;
  std::cout << i << " * " << i << " * " << 4 << " = " << l << std::endl;


  double x = 10;
  double y = 3;
  double z = x/y;

  std::cout << z << std::endl;
  // 整数部分を含めた有効桁数
  std::cout << std::setprecision(3) << z << std::endl;
  std::cout << std::setprecision(15) << z << std::endl;
  // 15が適用されたままとなる
  std::cout << z << std::endl;
  // 小数点以下の桁数指定
  std::cout << std::fixed << std::setprecision(15) << z << std::endl;



  long long xxx = 1LL<<62;
  long long yyy = xxx * 4;
  yyy /= 4;
  // long long zzz = (long long) xxx;
  std::cout << xxx << " * " << 4 << " / " << 4 << " = " << yyy << std::endl;

  // GCC拡張
  // 途中でlong longの範囲を超えても計算できている
  __int128 xx = (__int128)1LL<<62;
  __int128 yy = xx * 4;
  yy /= 4;
  long long zz = (long long) yy;
  std::cout << (long long)xx << " * " << 4 << " / " << 4 << " = " << zz << std::endl;
}

int main() {
  practice();
  return 0;
}