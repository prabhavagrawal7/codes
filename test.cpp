#include <gmp.h>
#include <iostream>

int main() {
  mpz_t value;
  mpz_init(value);

  // Set the value of value to 2^77
  mpz_ui_pow_ui(value, 2, 77);

  // Print the value of value in decimal
  std::cout << value << std::endl;

  mpz_clear(value);
  return 0;
}
