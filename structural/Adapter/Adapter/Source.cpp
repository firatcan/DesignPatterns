#include<iostream>
using namespace std;

typedef int Coordinate;
typedef int Dimension;

class Rectangle
{
public:
	virtual void draw() = 0;
};

class LegacyRectangle
{
private:
	Coordinate x1_;
	Coordinate y1_;
	Coordinate x2_;
	Coordinate y2_;
public:
	LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
	{
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
		cout << "LegacyRectangle : create. (" << x1_ << "," << y1_ << ") => (" << x2_ << "," << y2_ << ")" << endl;
	}
	void oldDraw()
	{
		cout << "LegacyRectangle : odlDraw. (" << x1_ << "," << y1_ << ") => (" << x2_ << "," << y2_ << ")" << endl;
	}
};
class RectangleAdapter:public Rectangle, private LegacyRectangle
{
public:
	RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) :LegacyRectangle(x, y, x + w, y + h)
	{
		cout << "RectangleAdapter : create. (" << x << "," << y << "), width = " << w << ", height = " << h << endl;
	}
	virtual void draw()
	{
		cout << "RectangleAdapter : draw. " << endl;
		oldDraw();
	}
};
int main()
{
	Rectangle* r = new RectangleAdapter(120, 200, 60, 40);
	r->draw();
	system("pause");
	return 0;
}