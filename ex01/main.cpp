
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
  PhoneBook phonebook;
  std::string command;

  try
  {
    while(true)
    {
      std::cout << "Phonebook > ";
      if (!std::getline(std::cin, command))
        break;
      if(command == "EXIT")
        break;
      else if(command == "ADD")
        phonebook.add();
      else if(command == "SEARCH")
        phonebook.show();
    }
  }
  catch (const std::runtime_error&)
  {
  }
  return 0;
}
