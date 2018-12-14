#include <bits/stdc++.h>
#include <unistd.h>
#include <omp.h>

int main()
{
  // 時間計測開始
  std::chrono::steady_clock::time_point start,end;
  start = std::chrono::steady_clock::now();

  // random
  std::random_device seed_gen;
  // std::mt19937 engine(seed_gen());
  std::mt19937 engine(100);
  std::uniform_real_distribution<> dist1(0, 10);

  long long n = 10000;

  int *a; int *b; int *result;
  a = new int[n*n]; b = new int[n]; result = new int[n];

  // int a[n*n], b[n], result[n];
  
  int i;

  for (i = 0; i < n*n; i++)
  {
    a[i] = dist1(engine);
    // std::cout << a[i] << std::endl;
  }

  for (i = 0; i < n; i++)
  {
    b[i] = dist1(engine);
    // std::cout << b[i] << std::endl;
    result[i] = 0;
  }

#ifdef _OPENMP
  // スレッド数の設定
  omp_set_num_threads(8);
#pragma omp parallel for private(i)
#endif
  for (i = 0; i < n*n; i++)
  {
    result[i / n] += a[i] * b[i % n];
     // sleep(1);
  }
  
  // 時間計測終了
  end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  // for (int i = 0; i < n; i++)
  //   std::cout << result[i] << ' ';
  // std::cout << std::endl;

  std::cout << elapsed <<"ms"<< std::endl;
}
