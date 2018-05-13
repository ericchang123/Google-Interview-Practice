#include <iostream>
#include <list>
#include <unordered_set>
#include <time.h>

using namespace std;

void remDup(list<int> &l){
  unordered_set<int> mySet;
  list<int>::iterator it;
  for(it = l.begin(); it != l.end(); it++){
    if(mySet.find(*it) != mySet.end()){
      l.erase(it);
    }
    else{
      mySet.insert(*it);
    }
  }
}

int main(){
  list<int> l;
  int ran;
  list<int>::iterator it;

  srand(time(NULL));

  for(int i = 0; i < 150; i++){
    ran = rand() % 10 + 1;
    l.push_back(ran);
  }
  for(it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  remDup(l);
  cout << endl;
  for(it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  return 0;
}
