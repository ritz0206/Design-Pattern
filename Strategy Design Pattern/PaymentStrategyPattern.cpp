#include <bits/stdc++.h>

using namespace std;

// Strategy Pattern
class PaymentStrategy
{
    public:
        virtual void pay() = 0;
        virtual ~PaymentStrategy() = default;
};
class UpiPayment : public PaymentStrategy
{
    public:
        void pay() override
        {
            cout << "Upi Transaction selected."<< endl;
        }
};
class CashPayment : public PaymentStrategy
{
    public:
        void pay() override
        {
            cout << "Cash Transaction selected."<< endl;
        }
};
class CreditCardPayment : public PaymentStrategy
{
    public:
        void pay() override
        {
            cout << "Credit Card Transaction selected."<< endl;
        }
};
class PaymentContext
{
    protected:
        PaymentStrategy* paymentMode;

    public:
        PaymentContext(PaymentStrategy* payMode) : paymentMode(payMode){}
        void payAmount()
        {
            paymentMode->pay();
        }
};
class BookMyShowContext : public PaymentContext
{
    public:
        BookMyShowContext() : PaymentContext(new UpiPayment()) {}
};
class ZomatoContext : public PaymentContext
{
    public:
        ZomatoContext(PaymentStrategy* payMode) : PaymentContext(payMode) {}
};
class VendorContext : public PaymentContext
{
    public:
        VendorContext() : PaymentContext(new CashPayment()) {}
};

int main()
{
    PaymentContext* bookMyShow = new BookMyShowContext();
    PaymentContext* zomatoCreditCard = new ZomatoContext(new CreditCardPayment());
    PaymentContext* zomatoUpi = new ZomatoContext(new UpiPayment());
    PaymentContext* vendor = new VendorContext();

    bookMyShow->payAmount();           // Upi Transaction selected.
    zomatoCreditCard->payAmount();     // Credit Card Transaction selected.
    zomatoUpi->payAmount();            // Upi Transaction selected.
    vendor->payAmount();               // Cash Transaction selected.

    return 0;
}