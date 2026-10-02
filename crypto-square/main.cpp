#include <iostream>
#include "crypto_square.h"

int main() {
    // Texto de prueba oficial del ejercicio
    std::string test_text = "If man was meant to stay on the ground, god would have given us roots.";

    crypto_square::encoder enc(test_text);
    std::string result = enc.ciphertext();

    std::cout << "Texto cifrado obtenido:" << std::endl;
    std::cout << "\"" << result << "\"" << std::endl;

    return 0;
}
