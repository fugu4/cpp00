
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
    std::getline(std::cin, command);
    if(std::cin.eof())
      std::exit(1);
    else if(command == "EXIT")
      break;
    else if(command == "ADD")
      phonebook.add();
    else if(command == "SEARCH")
      phonebook.show();
  }
}
