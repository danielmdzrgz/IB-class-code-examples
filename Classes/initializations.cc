/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 15 Dec 2020
 * @brief Illustrate different initializations supported in C++
 *
 * @see https://www.learncpp.com/cpp-tutorial/911-the-copy-constructor/
 */

#include <iostream>

class Point {
 private:
  double x_, y_, z_;    // Point coordinates

 public:
  Point(double x = 0.0, double y = 0.0, double z = 0.0): x_{x}, y_{y}, z_{z} { 
		std::cout << "The constructor has been called..." << std::endl;
	}
  friend std::ostream& operator<<(std::ostream &out, const Point &point);
  double getX() const { return x_; }
  double getY() const { return y_; }
  double getZ() const { return z_; }
};

// Overloaded operator << (insertion)
std::ostream& operator<<(std::ostream &out, const Point &point) {
  out << "Point(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ')'; // actual output done here
  return out; // return std::ostream so we can chain calls to operator<<
}

int main() {
  int my_var1(1); // Direct initialize an integer
  Point my_point1(1.0, 1.0, 1.0); // Direct initialize a Point, calls Point(double, double, double) constructor
  std::cout << "my_point1 is: " << my_point1 << std::endl;

	int my_var2 { 2 }; // Uniform initialization of an integer
  Point my_point2 {2.0, 2.0, 2.0}; // Uniform initialization of a Point, calls Point(double, double, double) constructor
  std::cout << "my_point2 is: " << my_point2 << std::endl;

	int my_var3 = 3; // Copy initialize an integer
  Point my_point3 = Point(3.0); // Copy initialize a Point, will call Point(3.0, 0.0, 0.0)
  Point my_point4 = 4; // Copy initialize a Point.  
	                     // The compiler will try to find a way to convert 4 to a Point, 
											 // which will invoke the Point(4, 0.0, 0.0) constructor.
  std::cout << "my_point3 is: " << my_point3 << std::endl;
  std::cout << "my_point4 is: " << my_point4 << std::endl;

  Point my_point5{}; // use default constructor to set to (0.0, 0.0, 0.0)
  std::cout << "my_point5 is: " << my_point5 << std::endl;
  Point p_copy(my_point5);
  std::cout << "p_copy is: " << p_copy << std::endl;

  return 0;
}
