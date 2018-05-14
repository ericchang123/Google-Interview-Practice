#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minLevel(TreeNode* root){
  if(root == NULL) return 0;
  TreeNode* curr;
  int sum = 0;
  int min = INT_MAX;
  int level = 1;
  unordered_map<int, int> mp;         // First int is the sum, second int is the level
  queue<TreeNode*> current;
  queue<TreeNode*> next;
  current.push(root);
  while(!current.empty()){
    curr = current.front();
    current.pop();
    if(curr->left) next.push(curr->left);
    if(curr->right) next.push(curr->right);
    sum += curr->val;
    if(current.empty()){
      mp[sum] = level;
      level++;
      if(sum < min) min = sum;
      current = next;
      queue<TreeNode*> empty;
      next = empty;
      sum = 0;
    }
  }
  return mp[min];
}

int main(){
  TreeNode* n1 = new TreeNode(50);
  TreeNode* n2 = new TreeNode(6);
  TreeNode* n3 = new TreeNode(45);
  TreeNode* n4 = new TreeNode(3);
  TreeNode* n5 = new TreeNode(8);
  TreeNode* n6 = new TreeNode(7);
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  cout << "Level with minimum sum is: " << minLevel(n1) << endl;
  return 0;
}
