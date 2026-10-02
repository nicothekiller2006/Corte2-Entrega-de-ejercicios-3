#include "crypto_square.h"
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>

namespace crypto_square {

encoder::encoder(std::string text) : input(text) {}

std::string encoder::ciphertext() {
    // 1. Normalizar el texto (solo letras y números, todo a minúsculas)
    std::string normalized = "";
    for (char c : input) {
        if (std::isalnum(c)) {
            normalized += std::tolower(c);
        }
    }

    if (normalized.empty()) {
        return "";
    }

    int L = normalized.length();
    
    // 2. Calcular filas (r) y columnas (c)
    int c = std::round(std::sqrt(L));
    int r = std::round(std::sqrt(L));
    
    if (r * c < L) {
        if (r < c) {
            r = c;
        } else {
            c = r;
        }
    }
    if (r * c < L) {
        c++;
    }

    // 3. Crear las filas de la matriz
    std::vector<std::string> rows;
    for (int i = 0; i < L; i += c) {
        rows.push_back(normalized.substr(i, c));
    }

    // 4. Leer por columnas y armar el texto cifrado
    std::string cipher = "";
    for (int col = 0; col < c; ++col) {
        std::string col_str = "";
        for (const std::string& row : rows) {
            if (col < row.length()) {
                col_str += row[col];
            } else {
                col_str += ' '; // Relleno con espacios si falta
            }
        }
        if (!cipher.empty()) {
            cipher += " ";
        }
        cipher += col_str;
    }

    return cipher;
}

} // namespace crypto_square
