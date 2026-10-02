#include <iostream>
#include <thread>
#include <vector>
#include "bank_account.h"

void worker(BankAccount& acc, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        acc.deposit(10);
        acc.withdraw(10);
    }
}

int main() {
    BankAccount my_bank;
    my_bank.open();

    std::cout << "Saldo inicial: " << my_bank.get_balance() << std::endl;

    // Creamos varios hilos para simular transacciones concurrentes (paralelo)
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(worker, std::ref(my_bank), 100);
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Saldo final despues de hilos concurrentes: " << my_bank.get_balance() << std::endl;

    my_bank.close();
    std::cout << "Cuenta cerrada exitosamente." << std::endl;

    return 0;
}
