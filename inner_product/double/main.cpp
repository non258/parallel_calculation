#include <bits/stdc++.h>
#include <unistd.h>
#include <omp.h>

int main()
{
  // random
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::uniform_real_distribution<> dist1(0, 10);

  // 時間計測開始
  std::chrono::system_clock::time_point start,end;
  start = std::chrono::system_clock::now();

  int n = 1000;

  int a[n][n],b[n],result[n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = dist1(engine);

  for (int i = 0; i < n; i++)
    b[i] = dist1(engine);


#ifdef _OPENMP
  // スレッド数の設定
  omp_set_num_threads(4);
#pragma omp parallel for 
#endif
  for (int i = 0; i < n; i++)
  {
    double result_tmp = 0;
    for (int j = 0; j < n; j++)
      result_tmp += a[i][j] * b[j];
    result[i] = result_tmp;
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
