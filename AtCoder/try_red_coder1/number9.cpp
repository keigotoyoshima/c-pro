s.insert(0, "a"); 

int main(){
  int m; cin >> m;
  vector<int>a(m);
  vector<int>b(m);
  for (int i = 0; i < m; i++)
  {
    cin >> a[i] >> b[i];
  }

  int n; cin >> n;
  vector<int>c(n);
  vector<int>d(n);
  for (int i = 0; i < n; i++)
  {
    cin >> c[i] >> d[i];
  }

  // m個の点のうち1点のみ特別扱い
  for (int i = 0; i < n; i++)
  {
    // それぞれのnに対して平行移動の仕方を確定
    int kx = a[0] - c[i];
    int ky = b[0] - d[i];
    int cnt = 0;
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
      flag = false;
      int px = a[j] - kx;
      int py = b[j] - ky;
      // px, py がnの中に含まれているか判定。
     
      for (int r = 0; r < n; r++)
      {
        if(c[r] == px && d[r] == py) {
          flag = true;
        }
      }
      if(!flag) break;
    }
    // m個の点が全て平行移動できる場合
    if(flag){
      cout << -kx << " "<< -ky << endl;
      return 0;
    }
    
  }
  cout << "NO" << endl;
  return 0;
}

// m個の星をそれぞれ同値で平行移動した場合に、n個の星に含まれるかを判定する。このとき、mのうち一つの点だけを特別扱いし、nそれぞれに対して、平行移動の仕方を確定する。確定した値でmそれぞれを平行移動し、nに全て含まれるかを調べる。

// 考え方
// 平行移動の仕方を確定後、全ての点を平行移動して判定する。