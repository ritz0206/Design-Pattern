#include<bits/stdc++.h>

using namespace std;

class BasePizza 
{
    public:
        virtual double getCost() = 0;
        virtual string getDescription() = 0;

        virtual ~BasePizza() {};
    
};

class Margherita : public BasePizza
{
    public:
        double getCost()
        {
            return 120.16;
        }
        string getDescription()
        {
            return "Margherita.";
        }
};

class VegDelight : public BasePizza
{
    public:
        double getCost()
        {
            return 156.74;
        }
        string getDescription()
        {
            return "Veg-Delight.";
        }
};

class Farmhouse : public BasePizza
{
    public:
        double getCost()
        {
            return 175.56;
        }
        string getDescription()
        {
            return "Farmhouse.";
        }
};

class ToppingsDecorator : public BasePizza
{
    public:
        virtual ~ToppingsDecorator() {}
};

class ExtraCheese : public ToppingsDecorator
{
    public:
        shared_ptr<BasePizza> basePizza;

        ExtraCheese(shared_ptr<BasePizza> basePizza)
        {
            this->basePizza = basePizza;
        }
        double getCost()
        {
            return this->basePizza->getCost() + 10.24;
        }
        string getDescription()
        {
            return this->basePizza->getDescription() + " + Extra Cheese";
        }
};

class Mushroom : public ToppingsDecorator
{
    public:
        shared_ptr<BasePizza> basePizza;

        Mushroom(shared_ptr<BasePizza> basePizza)
        {
            this->basePizza = basePizza;
        }
        double getCost()
        {
            return this->basePizza->getCost() + 25.50;
        }
        string getDescription()
        {
            return this->basePizza->getDescription() + " + Mushroom";
        }
};

class Jalapenoes : public ToppingsDecorator
{
    public:
        shared_ptr<BasePizza> basePizza;

        Jalapenoes(shared_ptr<BasePizza> basePizza)
        {
            this->basePizza = basePizza;
        }
        double getCost()
        {
            return this->basePizza->getCost() + 30.75;
        }
        string getDescription()
        {
            return this->basePizza->getDescription() + " + Jalapenoes";
        }
};

int main()
{
    int choice;
    shared_ptr<BasePizza> pizza;

    cout << "===== Welcome to Pizza Ordering Machine =====\n";
    cout << "Select Base Pizza:\n";
    cout << "1. Margherita (120.16)\n";
    cout << "2. Veg Delight (156.74)\n";
    cout << "3. Farmhouse (175.56)\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            pizza = make_shared<Margherita>();
            break;
        case 2:
            pizza = make_shared<VegDelight>();
            break;
        case 3:
            pizza = make_shared<Farmhouse>();
            break;
        default:
            cout << "Invalid choice. Exiting.\n";
            return 0;
    }

    // Toppings selection loop
    while (true) {
        cout << "\nAdd Toppings:\n";
        cout << "1. Extra Cheese (10.24)\n";
        cout << "2. Jalapenoes (25.50)\n";
        cout << "3. Mushroom (30.75)\n";
        cout << "4. Finish Order\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice) {
            case 1:
                pizza = make_shared<ExtraCheese>(pizza);
                cout << "Added Extra Cheese\n";
                break;
            case 2:
                pizza = make_shared<Jalapenoes>(pizza);
                cout << "Added Jalapenoes\n";
                break;
            case 3:
                pizza = make_shared<Mushroom>(pizza);
                cout << "Added Mushroom\n";
                break;
            case 4:
                cout << "\n===== Final Order =====\n";
                cout << "Pizza: " << pizza->getDescription() << endl;
                cout << "Total Cost: " << pizza->getCost() << endl;
                cout << "Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}


