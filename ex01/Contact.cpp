#include "Contact.hpp"
#include <iostream>

Contact::Contact()
  : first_name(""),
    last_name(""),
    nickname(""),
    phone_number(""),
    darkest_secret("")
{
}
void Contact::set_first_name(const std::string& input)
{
  first_name = input;
}

void Contact::set_last_name(const std::string& input)
{
  last_name = input;
}

void Contact::set_nickname(const std::string& input)
{
  nickname = input;
}

void Contact::set_phone_number(const std::string& input)
{
  phone_number = input;
}
void Contact::set_darkest_secret(const std::string& input)
{
  darkest_secret = input;
}

const std::string& Contact::get_first_name() const
{
  return (first_name);
}

const std::string& Contact::get_last_name() const
{
   return (last_name);
}

const std::string& Contact::get_nickname() const
{
  return (nickname);
}

const std::string& Contact::get_phone_number() const
{
  return (phone_number);
}

const std::string& Contact::get_darkest_secret() const
{
  return (darkest_secret);
}

