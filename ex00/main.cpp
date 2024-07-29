/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:50:36 by muhnal            #+#    #+#             */
/*   Updated: 2024/07/29 19:15:15 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "whatever.hpp"
#include <iostream>

// class Test {
// public:
// 	int value;
// 	Test(int val) : value(val) {}
// 	bool operator<(const Test& other) const { return value < other.value; }
// 	bool operator>(const Test& other) const { return value > other.value; }
// };

// std::ostream& operator<<(std::ostream& os, const Test& t) {
// 	os << t.value;
// 	return os;
// }


// int main(void) {
// 	int a = 2;
// 	int b = 3;

// 	::swap(a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";

// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
// 	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

// 		// Edge cases
// 	std::string e = "";
// 	std::string f = "";

// 	::swap(e, f);
// 	std::cout << "e = \"" << e << "\", f = \"" << f << "\"" << std::endl;
// 	std::cout << "min(e, f) = \"" << ::min(e, f) << "\"" << std::endl;
// 	std::cout << "max(e, f) = \"" << ::max(e, f) << "\"" << std::endl;

// 	int g = 5;
// 	int h = 5;

// 	::swap(g, h);
// 	std::cout << "g = " << g << ", h = " << h << std::endl;
// 	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
// 	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

// 	Test t1(10);
// 	Test t2(20);

// 	::swap(t1, t2);
// 	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl;
// 	std::cout << "min(t1, t2) = " << ::min(t1, t2) << std::endl;
// 	std::cout << "max(t1, t2) = " << ::max(t1, t2) << std::endl;


// 	return 0;
// }

class Awesome {
public:
  Awesome(void) : _n(0) {}
  Awesome(int n) : _n(n) {}
  Awesome &operator=(Awesome &a) {
    _n = a._n;
    return *this;
  }
  bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
  bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
  bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
  bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
  bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
  bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
  int get_n() const { return _n; }

private:
  int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) {
  o << a.get_n();
  return o;
}

int main(void) {
  Awesome a(2), b(4);

  swap(a, b);
  std::cout << a << " " << b << std::endl;
  std::cout << max(a, b) << std::endl;
  std::cout << min(a, b) << std::endl;
  return (0);
}
