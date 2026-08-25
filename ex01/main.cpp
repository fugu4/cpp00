
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
  PhoneBook phonebook;
  std::string command;

  while(true)
  {
    std::cout << "Phonebook > ";
    if(!std::getline(std::cin, command))
      break;
    if(command == "EXIT")
      break;
    else if(command == "ADD")
    {
      if(!phonebook.add())
        break;
    }
    else if(command == "SEARCH")
    {
      if(!phonebook.show())
        break;
    }
  }
}
