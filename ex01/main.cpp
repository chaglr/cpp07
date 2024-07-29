/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:51:13 by muhnal            #+#    #+#             */
/*   Updated: 2024/07/29 19:02:03 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Awesome {
public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

private:
  int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

template <typename T> void print(const T &x) {
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = {0, 1, 2, 3, 4};
  Awesome tab2[5];

  iter(tab, 5, print<const int>);
  iter(tab2, 5, print<Awesome>);

  return 0;
}
