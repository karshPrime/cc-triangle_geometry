#include <iostream>
#include <cmath>

float get_length(float cord_a[], float cord_b[]);
float get_angle(float side_a, float side_b, float side_c);
std::string triangle_type(float angles[], float lengths[]);
void print_details(float angles[], float lengths[], const std::string& type);
bool is_triangle(float angles[]);

int main() {
  std::cout << "Enter coordinates of your triangle: " << std::endl << "<separate with space>" << std::endl;

  float cords[3][2];
  for (short i = 0; i < 3; i++) {
    std::cout << "Point " << 'A' + i << ": ";
    std::cin >> cords[i][0];
    std::cin >> cords[i][1];
  }

  //            C
  //           /\
  //          /  \
  //  side_a /    \ side_b
  //        /      \
  //       /________\
  //     B   side_c   A

  float line_length[3];
  line_length[0] = get_length(cords[1], cords[2]);
  line_length[1] = get_length(cords[2], cords[0]);
  line_length[2] = get_length(cords[0], cords[1]);

  float angles[3];
  angles[0] = get_angle(line_length[1], line_length[2], line_length[0]);
  angles[1] = get_angle(line_length[0], line_length[2], line_length[1]);
  angles[2] = get_angle(line_length[0], line_length[1], line_length[2]);

  if (is_triangle(angles)) {
    std::string type = triangle_type(angles, line_length);
    print_details(angles, line_length, type);
  } else {
    std::cout << "Entered coordinates do not form a triangle." << std::endl;
  }

  return 0;
}

// calculates length of different sides
float get_length(float cord_a[], float cord_b[]) {
  float length = sqrt(std::pow((cord_a[0] - cord_b[0]), 2) + std::pow((cord_a[1] - cord_b[1]), 2));
  return length;
}

// calculates angles from calculated side lengths
float get_angle(float side_a, float side_b, float side_c) {
  // cos(A) = (b2 + c2 - a2) / (2bc)
  float angle = std::acos((std::pow(side_a, 2) + std::pow(side_b, 2) - std::pow(side_c, 2)) / (2 * side_a * side_b));
  return ((angle * 180) / 3.1429);
}

// confirms if entered coordinates do form a triangle
bool is_triangle(float angles[]) {
  for (short i = 0; i < 3; i++) {
    if (not std::isnormal(angles[i])){
      return false;
    }
  }
  return true;
}

// checks if either of the element in the list is over 90
bool over_90(const float angles[]) {
  for (short i = 0; i < 4; i++){
    if (angles[i] > 90) {
      return true;
    }
  }
  return false;
}

// checks if either of the element in the list is equal to 90
bool any_90(const float angles[]) {
  for (short i = 0; i < 3; i++) {
    if (angles[i] == 90) {
      return true;
    }
  }
  return false;
}

// compares all values in a list to see if either of them hold same value
bool any_same(const float properties[]) {
  if (properties[0] == properties[1] || properties[1] == properties[2] ||properties[2] == properties[0]) {
    return true;
  }
  return false;
}

// Checks triangle type
std::string triangle_type(float angles[], float lengths[]) {
  if (over_90(angles)) {
    return "Oblique";
  } else if (any_90(angles)) {
    return "Right-Angle";
  } else if (angles[0] == angles[1] == angles[2]) {
    return "Equilateral";
  } else if (any_same(angles)) {
    return "Isosceles";
  } else if (any_same(lengths)) {
    return "Scalene";
  }
  return "Acute"; // since the triangle isn't right-angled or obliqued
}

// Print all calculated details
void print_details(float angles[], float lengths[], const std::string& type) {
  std::cout << std::endl << "Details generated:" << std::endl;
  std::cout << "Length AB: " << lengths[2] << "unit" << std::endl;
  std::cout << "Length BC: " << lengths[0] << "unit" << std::endl;
  std::cout << "Length CA: " << lengths[1] << "unit" << std::endl;

  std::cout << "Angle <ABC: " << angles[1] << "\370" << std::endl;
  std::cout << "Angle <BCA: " << angles[2] << "\370" << std::endl;
  std::cout << "Angle <BAC: " << angles[0] << "\370" << std::endl;


  std::cout << "∆ABC is a(n) " << type << " triangle." << std::endl;
}
