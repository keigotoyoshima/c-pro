#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <array>
using namespace std;

// int to string
string intToString(int i){
  return to_string(i);
}

// string to int
int stringToInt(string s){
  return stoi(s);
}

// char to string
string charToString(char c){
  string s = {c}; 
  return s;
}

// string to char
char stringToChar(string s){
  char c = s[0];
  return c;
}

// char to int
int charToInt(char c){
  return c - '0';
}

// int to char
int intToChar(int i){
  return i + '0';
}