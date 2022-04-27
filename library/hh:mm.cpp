// hh:mmを分換算する関数
int changeToMinutes(string s)
{
  // 時間
  string h1 = {s[0]};
  string h2 = {s[1]};
  string hour_s = h1 + h2;
  int hour = stoi(hour_s);

  // 分
  string m1 = {s[3]};
  string m2 = {s[4]};
  string minutes_s = m1 + m2;
  int minutes = stoi(minutes_s);

  return hour * 60 + minutes;
}

// 分から文字列(hh:mm)に戻す関数
string hhmm(int sumMinutes)
{
  int hour = sumMinutes / 60 % 24;
  int minutes = sumMinutes % 60;
  string s1 = to_string(hour);
  string s2 = to_string(minutes);
  if (s1.size() == 1)
    s1 = '0' + s1;
  if (s2.size() == 1)
    s2 = '0' + s2;
  string res = s1 + ':' + s2;
  return res;
}