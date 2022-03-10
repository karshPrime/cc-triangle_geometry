#include <iostream>
#include <cmath>

float get_length(float cord_a[], float cord_b[]);
float get_angle(float side_a, float side_b, float side_c);

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