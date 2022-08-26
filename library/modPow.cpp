// 繰り返し二乗法(aのn乗)
int modPow(long long a, long long n)
{
  if (n == 0)
    return 1; // 0乗にも対応する場合
  if (n == 1)
    return a % MOD;
  if (n % 2 == 1)
    return (a * modPow(a, n - 1)) % MOD;
  long long t = modPow(a, n / 2);
  return (t * t) % MOD;
}