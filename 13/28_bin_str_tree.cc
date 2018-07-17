#include "13/28_bin_str_tree.h"

#include <string>

TreeNode::~TreeNode() {
  delete left_;
  delete right_;
}

TreeNode::TreeNode(const TreeNode &o)
    : value_(std::string(o.value_)), count_(o.count_),
      left_(o.left_ ? new TreeNode(*o.left_) : nullptr),
      right_(o.right_ ? new TreeNode(*o.right_) : nullptr) {}

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  value_ = rhs.value_;
  count_ = rhs.count_;
  auto new_left = rhs.left_ ? new TreeNode(*rhs.left_) : nullptr;
  auto new_right = rhs.right_ ? new TreeNode(*rhs.right_) : nullptr;
  delete left_;
  delete right_;
  left_ = new_left;
  right_ = new_right;
  return *this;
}

BinStrTree::BinStrTree(const BinStrTree &o) : root_(new TreeNode(*o.root_)) {}

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
  if (this != &rhs) { // prevent copying the same tree that maybe large
    delete root_;
    root_ = new TreeNode(*rhs.root_);
  }
  return *this;
}
