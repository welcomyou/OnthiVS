#include <iostream>
using namespace std;

class DrawingShape;
class Shape;

class DrawingShape
{
public:
	virtual void draw(Shape* s) = 0;
};

class DrawingRectangle : public DrawingShape
{
public:
	void draw(Shape* s) {};
};
class DrawingCircle : public DrawingShape
{
public:
	void draw(Shape* s) {};
};

class Shape
{
protected:
	DrawingShape* drawer;
public:

	Shape(DrawingShape* ds)
	{
		drawer = ds;
	};
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0, DrawingShape* ds = NULL) : x(x), y(y), width(w), height(h), Shape(ds) {};
	void draw()
	{
		drawer->draw(this);
		cout << "Rectangle draw with x =" << x << ", y =" << y << ", width =" << width << ", height =" << height << endl;
	}
};

class Circle : public Shape
{
private:
	int x;
	int y;
	int radius;
public:
	Circle(int x = 0, int y = 0, int r = 0, DrawingShape* ds = NULL) : x(x), y(y), radius(r), Shape(ds) {};
	void draw()
	{
		drawer->draw(this);
		cout << "Circle draw with x =" << x << ", y =" << y << ", radius =" << radius << endl;
	}
};

int main()
{
	return 0;
}