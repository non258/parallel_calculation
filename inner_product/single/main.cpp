#include <bits/stdc++.h>
#include <unistd.h>
#include <omp.h>

int main()
{
  // random
  std::random_device seed_gen;
  // std::mt19937 engine(seed_gen());
  std::mt19937 engine(100);
  std::uniform_real_distribution<> dist1(0, 10);

  // 時間計測開始
  std::chrono::system_clock::time_point start,end;
  start = std::chrono::system_clock::now();

  long long n = 1000;

  double a[n*n],b[n],result[n];
  // double result_tmp = 0;

  for (int i = 0; i < n*n; i++)
  {
    a[i] = dist1(engine);
    // std::cout << a[i] << std::endl;
  }


  for (int i = 0; i < n; i++)
  {
    b[i] = dist1(engine);
    // std::cout << b[i] << std::endl;
    result[i] = 0;
  }

int i;

#ifdef _OPENMP
  // スレッド数の設定
  omp_set_num_threads(4);
#pragma omp parallel for private(i)
#endif
  for (i = 0; i < n*n; i++)
  {
    // std::cout << i << i / n << i % n << std::endl;
    // cout << 0 << 1 / n << endl;
    result[i / n] += a[i] * b[i % n];
    // std::cout << (int)a[i] << b[i % n] << std::endl;
    // sleep(1);
  }


  // 時間計測終了
  end = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast< std::chrono::nanoseconds>(end - start).count();

  // for (int i = 0; i < n; i++)
  //   std::cout << result[i] << ' ';
  // std::cout << std::endl;

  std::cout << elapsed <<"ns"<< std::endl;
}
