#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>

class BankAccount {
private:
    int balance;
    bool is_open;
    mutable std::mutex mtx; // Mutex para garantizar exclusión mutua en hilos

public:
    BankAccount();
    void open();
    void close();
    int get_balance() const;
    void deposit(int amount);
    void withdraw(int amount);
};

#endif
