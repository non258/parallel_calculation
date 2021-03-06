#include <bits/stdc++.h>
#include <unistd.h>
#include <omp.h>

#define ll long long

int main()
{
  // random
  std::random_device seed_gen;
  // std::mt19937 engine(seed_gen());
  std::mt19937 engine(100);
  std::uniform_real_distribution<> dist1(0, 10);

  ll n = 1000;
  int count = 0;

  int a[n*n], b[n], result[n];

  std::vector<int> v(100, 0);
  
  ll i;

  for (i = 0; i < n*n; i++)
  {
    a[i] = dist1(engine);
  }

  for (i = 0; i < n; i++)
  {
    b[i] = dist1(engine);
    result[i] = 0;
  }
  
  while (count > 100)
  {
    // 時間計測開始
    std::chrono::steady_clock::time_point start,end;
    start = std::chrono::steady_clock::now();

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

    v.push_back(elapsed);
    count++;
  }

  int min = *std::max_element(v.begin(), v.end());
  std::cout << min <<"ms"<< std::endl;
}
