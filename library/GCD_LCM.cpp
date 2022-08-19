// greatest common divisor
// ユークリッドの互除法
int gcd(int a, int b)
{
  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, a % b);
  }
}

// least common multiple
int lcm(int a, int b)
{
  return a * b / gcd(a, b);
}
