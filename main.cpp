#include <iostream>
#include <functional>

#include "solution.h"

using namespace std;

int main()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,6);
  auto dice = std::bind ( distribution, generator );
  std::cout << dice() << " " << dice() << " " << dice() << " "
            << dice() << " " << dice() << " " << dice() << " " << std::endl;

  List list{1, 2, 3, 4, 5, 6, 7};
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;
  std::cout << list.getRandom() << std::endl;



  return 0;
}
