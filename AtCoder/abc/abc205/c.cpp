#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  if(c%2){
    if(a > b){
      cout << ">" <<  endl;
    } else if(a < b ){
      cout << "<" << endl;
    } else if(a == b){
      cout << "=" << endl;
    }
  }else{
    int a2 = abs(a);
    int b2 = abs(b);
    if(a2 > b2){
      cout << ">" <<  endl;
    } else if(a2 < b2 ){
      cout << "<" << endl;
    } else if(a2 == b2){
      cout << "=" << endl;
    }
  }

  return 0;
}