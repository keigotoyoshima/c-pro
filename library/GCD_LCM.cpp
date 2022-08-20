// greatest common divisor
// ユークリッドの互除法
int GCD(int a, int b)
{
  return b ? GCD(b, a % b) : a;
}

// least common multiple
int lcm(int a, int b)
{
  return a * b / gcd(a, b);
}
