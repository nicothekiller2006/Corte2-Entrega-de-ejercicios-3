#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>

namespace crypto_square {
    class encoder {
        std::string input;
    public:
        explicit encoder(std::string text);
        std::string ciphertext();
    };
}

#endif
