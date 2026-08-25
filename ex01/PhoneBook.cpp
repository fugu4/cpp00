#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
 : contact_count(0),
  next_index(0)
{
}

std::string trim(std::string str)
{
  int start = 0;
  int end = str.length();

  while(start < end && (str[start] == ' ' || str[start] == '\t'))
    start++;
  while(end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
    end--;
  return str.substr(start, end - start);
}

std::string PhoneBook::read_empty(std::string sentence)
{
  std::string command;
  command = ("");
 
  while(command.empty())
  {
    std::cout << sentence;
    std::getline(std::cin, command);
    command = trim(command);
  }
  return(command);
}

std::string numtrim(std::string str)
{
  int start = 0;
  int end = str.length();

  while(start < end && (str[start] == ' ' || str[start] == '\t'))
    start++;
  while(end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
    end--;
  if(start == end)
    return "";
  int i = start;
  while((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\t')
  {
    if(i == end - 1)
      return str.substr(start, end - start);
    i++;
  }
  return "";
}

std::string PhoneBook::readnum_empty(std::string sentence)
{
  std::string command;
  command = ("");
 
  while(command.empty())
  {
    std::cout << sentence;
    std::getline(std::cin, command);
    command = numtrim(command);
  }
  return(command);
}

void PhoneBook::input_info(Contact& contact)
{
  contact.set_first_name(read_empty("first name = "));
  contact.set_last_name(read_empty("last name = "));
  contact.set_nickname(read_empty("nickname = "));
  contact.set_phone_number(readnum_empty("phone number = "));
  contact.set_darkest_secret(read_empty("darkest secret = "));
}

void PhoneBook::add()
{
  Contact contact;

  input_info(contact);
	if (contact_count < 8)
		contact_count++;
	Contacts[next_index++] = contact;
	if (next_index == 8)
		next_index = 0;
}

std::string format(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void  show_info(const Contact& contact)
{  
  std::cout << "first name: ";
	std::cout << contact.get_first_name() << std::endl;
  std::cout << "last name: ";
	std::cout << contact.get_last_name() << std::endl;
  std::cout << "nickname: ";
	std::cout << contact.get_nickname() << std::endl;
  std::cout << "phone number: ";
	std::cout << contact.get_phone_number() << std::endl;
  std::cout << "darkest secret: ";
	std::cout << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::show()
{
	int i;
	std::string str_index;
	int index;

  if(contact_count == 0)
  {
    std::cout << "No contacts" << std::endl;
    return ;
  }
	i = 0;
	while (i < contact_count)
	{
		std::cout << std::setw(10) << i + 1 << "|"
              << std::setw(10) << format(Contacts[i].get_first_name()) << "|"
              << std::setw(10) << format(Contacts[i].get_last_name()) << "|" 
              << std::setw(10) << format(Contacts[i].get_nickname()) << std::endl;
		i++;
	}
	std::cout << "Choose Number: ";
	std::getline(std::cin, str_index);
	if (str_index.length() != 1 || str_index[0] < '1' || str_index[0] > '0'
		+ contact_count)
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	index = str_index[0] - '1';
	show_info(Contacts[index]);
}