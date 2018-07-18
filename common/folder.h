#ifndef CPS_FOLDER_H_
#define CPS_FOLDER_H_

#include <set>

namespace cps {

class Message;

class Folder {
  friend class Message;
  friend void swap(Folder &, Folder &);

public:
  Folder() = default;

  ~Folder();
  Folder(const Folder &f);
  Folder &operator=(const Folder &rhs);

  void Add(Message &m);
  void Remove(Message &m);

private:
  std::set<Message *> messages_;

  void addMsg(Message *m);
  void rmMsg(Message *m);

  void addToMessages(const Folder &f);
  void removeFromMessages();
};

void swap(Folder &, Folder &);

} // namespace cps

#endif
