#ifndef CPS_CP13_EX28_H_
#define CPS_CP13_EX28_H_

#include <string>

class TreeNode {
public:
  TreeNode()
      : value_(std::string()), count_(0), left_(nullptr), right_(nullptr) {}

  ~TreeNode();
  TreeNode(const TreeNode &o);
  TreeNode &operator=(const TreeNode &rhs);

private:
  std::string value_;
  int count_; // I don't konw what dose count_ mean
  TreeNode *left_;
  TreeNode *right_;
};

class BinStrTree {
public:
  BinStrTree() : root_(new TreeNode()) {}

  ~BinStrTree() { delete root_; }
  BinStrTree(const BinStrTree &);
  BinStrTree &operator=(const BinStrTree &);

private:
  TreeNode *root_;
};

#endif
