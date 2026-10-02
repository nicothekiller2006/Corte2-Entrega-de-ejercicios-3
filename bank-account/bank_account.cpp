#include "bank_account.h"
#include <stdexcept>

BankAccount::BankAccount() : balance(0), is_open(false) {}

void BankAccount::open() {
    std::lock_guard<std::mutex> lock(mtx);
    if (is_open) {
        throw std::runtime_error("Account is already open.");
    }
    is_open = true;
    balance = 0;
}

void BankAccount::close() {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is already closed.");
    }
    is_open = false;
}

int BankAccount::get_balance() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed.");
    }
    return balance;
}

void BankAccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed.");
    }
    if (amount < 0) {
        throw std::runtime_error("Cannot deposit negative amounts.");
    }
    balance += amount;
}

void BankAccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed.");
    }
    if (amount < 0 || amount > balance) {
        throw std::runtime_error("Invalid withdrawal amount.");
    }
    balance -= amount;
}
