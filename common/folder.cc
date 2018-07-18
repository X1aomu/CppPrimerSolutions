#include "common/folder.h"

#include <set>

#include "common/message.h"

namespace cps {

Folder::~Folder() { removeFromMessages(); }
Folder::Folder(const Folder &f) : messages_(f.messages_) { addToMessages(f); }
Folder &Folder::operator=(const Folder &rhs) {
  removeFromMessages();
  messages_ = rhs.messages_;
  addToMessages(rhs);
  return *this;
}

void Folder::Add(Message &m) {
  addMsg(&m);
  m.addFolder(this);
}
void Folder::Remove(Message &m) {
  rmMsg(&m);
  m.rmFolder(this);
}

void Folder::addMsg(Message *m) { messages_.insert(m); }
void Folder::rmMsg(Message *m) { messages_.erase(m); }

void Folder::addToMessages(const Folder &f) {
  for (auto msg : f.messages_) {
    msg->addFolder(this);
  }
}
void Folder::removeFromMessages() {
  for (auto msg : messages_) {
    msg->rmFolder(this);
  }
}

void swap(Folder &left, Folder &right) {
  using std::swap;
  left.removeFromMessages();
  right.removeFromMessages();
  swap(left.messages_, right.messages_);
  left.addToMessages(left);
  right.addToMessages(right);
}

} // namespace cps
