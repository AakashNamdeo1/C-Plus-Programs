#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    int larger = (num1 > num2) ? num1 : num2;
    std::cout << "The larger value is: " << larger << std::endl;

    return 0;
}
