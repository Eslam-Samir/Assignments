#include <iostream>

using namespace std;

class Move
{
	private:
		double x;
		double y;
	public:
		Move(double a = 0, double b = 0); // sets x, y to a, b
		void showmove(); // shows current x, y values
		Move add(const Move & m);
		// this function adds x of m to x of invoking object to get new x,
		// adds y of m to y of invoking object to get new y, creates a new
		// move object initialized to new x, y values and returns it
		void reset(double a = 0, double b = 0); // resets x,y to a, b
};

void main()
{
	Move a;	// x = 0, y = 0
	Move b(5,6); // x = 5, y = 6

	// show a and b
	a.showmove();
	b.showmove();

	a.reset(3,4); // x = 3, y = 4
	b.reset(); // x = 0, y = 0

	// show a and b
	a.showmove();
	b.showmove();

	b.reset(5,6); // x = 5, y = 6

	Move c = a.add(b); // x = 3+5, y = 4+6

	// show c
	c.showmove();

	system("pause");
}

Move::Move(double a, double b)
{
	this->x = a;
	this->y = b;
}
void Move::showmove()
{
	cout<<"(x, y): ("<<this->x<<", "<<this->y<<")"<<endl;
}
Move Move::add(const Move & m)
{
	double x = this->x + m.x;
	double y = this->y + m.y;
	return Move(x, y);
}
void Move::reset(double a, double b)
{
	this->x = a;
	this->y = b;
}