#include<bits/stdc++.h>
using namespace std;

class ObserverInterface
{
    public:
        virtual void update(string name) = 0;
        virtual ~ObserverInterface() {};
};

class User : public ObserverInterface
{
    private:
        string name;

    public:
        User(string name)
        {
            this->name = name;
        }
        void update(string name) override
        {
            
            cout << "Hello " << this->name 
             << ", Product '" <<  name
             << "' is now back in stock!\n";
        }
};

class SubjectInterface 
{
    protected:
        vector<ObserverInterface*> obsList;

    public:
        virtual void attach(ObserverInterface* obj) = 0;
        virtual void detach(ObserverInterface* obj) = 0;
        virtual void notify() = 0;
        virtual void updateProductQuantity(int quantity) = 0;
        virtual ~SubjectInterface() {};
};

class Product : public SubjectInterface
{
    private:
        string productName;
        int productQuantity;
        bool inStock = false;
    public:
        Product(string productName, int productQuantity)
        {
            this->productName = productName;
            this->productQuantity = productQuantity;
        }
        void attach(ObserverInterface* obj) override
        {
            obsList.push_back(obj);
        }
        void detach(ObserverInterface* obj) override
        {
            obsList.erase(remove(obsList.begin(), obsList.end(), obj), obsList.end());
        }
        void notify() override
        {
            for (auto obs : obsList) 
            {
                obs->update(productName);
            }
        }
        void updateProductQuantity(int quantity) override
        {
            productQuantity = quantity;
           if (quantity == 0) 
           {
                inStock = false;
           } 
           else 
           {
                if (!inStock) {
                    notify();
                }
                inStock = true;
           }

        }

};

int main()
{
    Product iphone("iPhone 15", 0);

    User u1("Alice");
    User u2("Bob");
    User u3("Charlie");

    // Users subscribe
    iphone.attach(&u1);
    iphone.attach(&u2);
    iphone.attach(&u3);

    cout << "Product is currently out of stock...\n\n";

    // Stock arrives
    cout << "Stock updated 1\n\n";
    iphone.updateProductQuantity(20);

    // Stock arrives again
    cout << "Stock updated 2\n\n";
    iphone.updateProductQuantity(30);

    // Stock depletes
    cout << "Stock updated 3\n\n";
    iphone.updateProductQuantity(2);

    // out of stock
    cout << "Stock updated 4\n\n";
    iphone.updateProductQuantity(0);

    // if stock arrives again, users will be notified again
    cout << "Stock updated 5\n\n";
    iphone.updateProductQuantity(15);

    return 0;
}