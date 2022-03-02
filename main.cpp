#include <iostream>

using std::cout;
using std::endl;
using std::cin;

//double sin(int, int);
//double cos(int, int);

int main() {
  cout << "Enter cordinates of your triangle: " << endl << "<separate with space>" << endl;

  float cords[3][2];
  for (short int i = 0; i < 3; i++) {
    cout << "Point " << i + 1 << " Cords: ";
    cin >> cords[i][0];
    cin >> cords[i][1];
  }

  return 0;
}
