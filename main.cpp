#include <iostream>
#include <cmath>

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
  float angles[3];

  return 0;
}
