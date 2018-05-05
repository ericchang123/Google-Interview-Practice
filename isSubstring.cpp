#include <iostream>
#include <string>

using namespace std;

int isSubstring(string& A, string& B){
  int i = 1;
  string temp = A;
  while(temp.length() < B.length()){
    temp += A;
    i++;
  }
  if(temp.find(B) != string::npos){
    return i;
  }
  temp.append(A);
  if(temp.find(B) != string::npos){
    return i + 1;
  }
  return -1;
}

int main(){
  string A = "abcd";
  string B = "cdabcdabcdabcdabcdabcdabz";
  cout << isSubstring(A, B) << endl;
  return 0;
}
