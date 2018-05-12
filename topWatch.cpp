#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <list>

using namespace std;

class comp{
public:
  bool operator()(pair<string,int> n1, pair<string,int> n2){
    return n1.second < n2.second;
  }
};

vector<string> topMovies(list< pair<string,int> > l, int num){
  vector<string> out;
  if(l.size() <= num){
    for(list< pair<string,int> >::iterator it = l.begin(); it != l.end(); it++){
      out.push_back(it->first);
    }
    return out;
  }

  priority_queue< pair<string,int>, vector< pair<string,int> >, comp> pq;
  for(list< pair<string,int> >::iterator it = l.begin(); it != l.end(); it++){
    pq.push(*it);
  }
  for(int i = 0; i < num; i++){
    out.push_back(pq.top().first);
    pq.pop();
  }
  return out;
}

int main(){
  list< pair<string,int> > myList;
  pair<string,int> p1 = {"The Phantom Menace",10};
  pair<string,int> p2 = {"Attack of the Clones",13};
  pair<string,int> p3 = {"Revenge of the Sith",17};
  pair<string,int> p4 = {"A New Hope",15};
  pair<string,int> p5 = {"The Empire Strikes Back",18};
  pair<string,int> p6 = {"Return of the Jedi",21};
  pair<string,int> p7 = {"The Fellowship of the Ring", 84};
  myList.push_back(p1);
  myList.push_back(p2);
  myList.push_back(p3);
  myList.push_back(p4);
  myList.push_back(p5);
  myList.push_back(p6);
  myList.push_back(p7);
  vector<string> mov = topMovies(myList, 15);
  for(int i = 0; i < mov.size(); i++){
    cout << mov[i] << endl;
  }
  return 0;
}
