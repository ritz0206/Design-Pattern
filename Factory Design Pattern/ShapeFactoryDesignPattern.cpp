#include<bits/stdc++.h>
#include <memory>

using namespace std;

class Shape
{
    public:
        virtual void draw() = 0;
        virtual ~Shape() {}
};

class Circle : public Shape{
    public:
        void draw() override
        {
            cout<<"Circle Object Created"<<endl;
        }
};

class Rectangle : public Shape{
    public:
        void draw() override
        {
            cout<<"Rectangle Object Created"<<endl;
        }
};

class Square : public Shape{
    public:
        void draw() override
        {
            cout<<"Square Object Created"<<endl;
        }
};
class ShapeFactory
{
    public:
        static std::unique_ptr<Shape> getShape(const std::string& shapeType) 
        {
            if (shapeType == "Circle")
                return std::make_unique<Circle>();
            else if (shapeType == "Rectangle")
                return std::make_unique<Rectangle>();
            else if (shapeType == "Square")
                return std::make_unique<Square>();
            return nullptr;
        }
};

int main()
{

    auto shape1 = ShapeFactory::getShape("Circle");
    shape1->draw();

    auto shape2 = ShapeFactory::getShape("Rectangle");
    shape2->draw();

    auto shape3 = ShapeFactory::getShape("Square");
    shape3->draw();
    
    return 0;
}
