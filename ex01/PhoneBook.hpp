#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
  public:
  PhoneBook();
  bool add();
  bool show();

  private:
  Contact Contacts[8];
  int contact_count;
  int next_index;
  bool input_info(Contact& contact);
  bool read_empty(const std::string& sentence, std::string& result);
  bool readnum_empty(const std::string& sentence, std::string& result);
};

#endif 
