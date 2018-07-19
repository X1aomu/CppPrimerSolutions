#ifndef CPS_MESSAGE_H_
#define CPS_MESSAGE_H_

#include <set>
#include <string>

namespace cps {

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);

public:
  explicit Message(const std::string &str = "") : contents_(str) {}

  ~Message();
  Message(const Message &);
  Message &operator=(const Message &);
  Message(Message &&);
  Message &operator=(Message &&);

  void SaveTo(Folder &f);
  void RemoveFrom(Folder &f);

private:
  std::string contents_;
  std::set<Folder *> folders_;

  void moveFolders(Message *m); // move m's folders to this'

  void addFolder(Folder *f);
  void rmFolder(Folder *f);

  void addToFolders(const Message &m);
  void removeFromFolders();
};

void swap(Message &, Message &);

} // namespace cps

#endif
