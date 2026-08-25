#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
  public:
  PhoneBook();
  void add();
  void show();

  private:
  Contact Contacts[8];
  int contact_count;
  int next_index;
  void input_info(Contact& contact);
  std::string read_empty(std::string sentence);
  std::string readnum_empty(std::string sentence);
};

#endif 