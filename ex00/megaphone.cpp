/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 23:00:52 by hnogi             #+#    #+#             */
/*   Updated: 2026/07/10 23:56:57 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
  if(ac < 2)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  int i = 1;
  while(ac > i)
  {
    int j = 0;
    while(av[i][j] != '\0')
    {
      std::cout << static_cast<char>(std::toupper(av[i][j]));
      j++;
    }
    i++;
  }
  std::cout << std::endl;
  return 0;
}
