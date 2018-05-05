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
  temp += A;
  if(temp.find(B) != string::npos){
    return i + 1;
  }
  return -1;
}

int main(){
  string A;
  string B;
  cout << "Enter a string A and a string B\n" << endl;
  // This will see if A can be repeated n times such that B becomes a substring
  cin >> A >> B;
  // -1 means B cannot be a substring of any amount of A's
  // Otherwise, the number printed is how many times A must be repeated such that B is a isSubstring
  if(isSubstring(A,B) > 0){
    cout << "Number of A's: " << isSubstring(A,B) << endl;
  }
  else{
    cout << "B cannot be a substring" << endl;
  }
  return 0;
}
