#include<bits/stdc++.h>

using namespace std;

class Shape
{
    public:
        virtual void draw() = 0;
        virtual ~Shape() {};
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

class AbstractShapeFactory
{
    public:
        virtual std::unique_ptr<Shape> createShape() = 0;
        virtual ~AbstractShapeFactory() {}
};

class circleShapeFactory : public AbstractShapeFactory
{
    public:
        std::unique_ptr<Shape> createShape() override
        {
            return std::make_unique<Circle>();
        }
};

class rectangleShapeFactory : public AbstractShapeFactory
{
    public:
        std::unique_ptr<Shape> createShape() override
        {
            return std::make_unique<Rectangle>();
        }
};

class squareShapeFactory : public AbstractShapeFactory
{
    public:
        std::unique_ptr<Shape> createShape() override
        {
            return std::make_unique<Square>();
        }
};

//This is extendable if any other shape is added in future, we just need to create a new factory class for that shape and implement the createShape() method. This way we are following the Open-Closed Principle (OCP) of Object-Oriented Design.

int main()
{
    std::unique_ptr<AbstractShapeFactory> circleFactory = std::make_unique<circleShapeFactory>();
    std::unique_ptr<Shape> circle = circleFactory->createShape();
    circle->draw();

    std::unique_ptr<AbstractShapeFactory> rectangleFactory = std::make_unique<rectangleShapeFactory>();
    std::unique_ptr<Shape> rectangle = rectangleFactory->createShape();
    rectangle->draw();

    std::unique_ptr<AbstractShapeFactory> squareFactory = std::make_unique<squareShapeFactory>();
    std::unique_ptr<Shape> square = squareFactory->createShape();
    square->draw();

    return 0;
}