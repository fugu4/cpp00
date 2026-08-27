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

  str = str.substr(start, end - start);

  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '\t')
      str[i] = ' ';
    i++;
  }
    return str.substr(start, end - start);
}

bool PhoneBook::read_empty(const std::string& sentence, std::string& result)
{
  result = "";

  while(result.empty())
  {
    std::cout << sentence;
    if (!std::getline(std::cin, result))
      return false;
    result = trim(result);
  }
  return true;
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
    {
      str = str.substr(start, end - start);

      int i = 0;
      while (str[i] != '\0')
      {
        if (str[i] == '\t')
        str[i] = ' ';
        i++;
      }
      return str.substr(start, end - start);
    }
    i++;
  }
  return "";
}

bool PhoneBook::readnum_empty(const std::string& sentence, std::string& result)
{
  result = "";

  while(result.empty())
  {
    std::cout << sentence;
    if (!std::getline(std::cin, result))
      return false;
    result = numtrim(result);
  }
  return true;
}

bool PhoneBook::input_info(Contact& contact)
{
  std::string input;

  if (!read_empty("first name = ", input))
    return false;
  contact.set_first_name(input);
  if (!read_empty("last name = ", input))
    return false;
  contact.set_last_name(input);
  if (!read_empty("nickname = ", input))
    return false;
  contact.set_nickname(input);
  if (!readnum_empty("phone number = ", input))
    return false;
  contact.set_phone_number(input);
  if (!read_empty("darkest secret = ", input))
    return false;
  contact.set_darkest_secret(input);
  return true;
}

bool PhoneBook::add()
{
  Contact contact;

  if (!input_info(contact))
    return false;
	if (contact_count < 8)
		contact_count++;
	Contacts[next_index++] = contact;
	if (next_index == 8)
		next_index = 0;
  return true;
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

bool PhoneBook::show()
{
	int i;
	std::string str_index;
	int index;

  if(contact_count == 0)
  {
    std::cout << "No contacts" << std::endl;
    return true;
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
	if (!std::getline(std::cin, str_index))
    return false;
	if (str_index.length() != 1 || str_index[0] < '1' || str_index[0] > '0'
		+ contact_count)
	{
		std::cout << "invalid index" << std::endl;
		return true;
	}
	index = str_index[0] - '1';
	show_info(Contacts[index]);
  return true;
}
