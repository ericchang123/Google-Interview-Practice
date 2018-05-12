#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permutation(string s, int left, int right){
  int i;
  if(left == right){
    cout << s << endl;
  }
  else{
    for(i = left; i <= right; i++){
      swap(s[left],s[i]);
      permutation(s, left + 1, right);
      swap(s[left],s[i]);
    }
  }
}

int main(){
  cout << "Enter a string\n";
  string s;
  cin >> s;
  permutation(s,0,s.length() - 1);
  return 0;
}
