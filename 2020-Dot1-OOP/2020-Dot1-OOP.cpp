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
	Rectangle(int x, int y, int w, int h, DrawingShape* ds): Shape(ds)
	{
		this->x = x;
		this->y = y;
		this->width = w;
		this->height = h;
		this->drawer = ds;
	}
	void draw()
	{
	}
};

class Circle : public Shape
{
private:
	int x;
	int y;
	int radius;
public:
	Circle(int x, int y, int r, DrawingShape* ds) : Shape(ds)
	{
		this->x = x;
		this->y = y;
		this->radius = r;
		this->drawer = ds;
	}
	void draw()
	{
	}
};

int main()
{
	return 0;
}