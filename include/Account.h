#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    public:
        void calculate() { amount += amount * interestRate; }
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
};

#endif
