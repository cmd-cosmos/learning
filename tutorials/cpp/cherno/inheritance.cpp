#include <iostream>

class Entity
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity
{
public:
	const char* Name;
	void PrintName()
	{
		std::cout << Name << '\n';
	}
	void PrintLocation()
	{
		std::cout << "Player Coordinates: " << "(" << X << ',' << Y << ")\n";
	}
};

int main()
{
	Player player1;
	player1.Name = "batman";
	player1.PrintName();
	player1.X = 0;
	player1.Y = 0;
	std::cout << "Initial Coordinates: " << "(" << player1.X << ',' << player1.Y << ")\n";
	player1.Move(3.0, 6.5);
	player1.PrintLocation();
    return 0;
}