#include <iostream>
#include <string>



class Player{

	public:
		int i_Lives, i_Score;

	Player(int i_Lives, int i_Score) {
		/*this is references to an entity of the class itself. It allows us to reference the same 
		variables as are passed into the member function.*/
		this->i_Lives = i_Lives;
		this->i_Score = i_Score;
	}

};

class Vector3d {
	public:
		float x, y, z;

	Vector3d(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3d Add(const Vector3d& other) const {
		return Vector3d(x + other.x, y + other.y,z + other.z);
	}

	Vector3d Minus(const Vector3d& other) const {
		return Vector3d(x - other.x, y - other.y, z - other.z);
	}
};

//A way to print out variables with using cout.
class Utility {

	public:
	Utility() {};

	//funtion overloading
	void Print(const float& x) {
		std::cout << x << std::endl;
	}

	void Print(const float& x, const float& y) {
		std::cout << x << " " << y << std::endl;
	}

	void Print(const float& x, const float& y, const float& z) {
		std::cout << x << " " << y << " " << z << std::endl;
	}

	void Print(const Vector3d& input) {

		std::cout << "The vector is: " << std::endl;
		std::cout << input.x << " " << input.y << " " << input.z << std::endl;
	}
};

int main()
{

	Player p(10, 20);

	//Class to control player.
	Vector3d position (10.f, 10.f, 10.f);
	Vector3d movement (30.f, 20.f, 10.f);
	Vector3d gravity(0.f, 9.8f, 0.f);

	Vector3d flyTo = position.Add(movement);
	Vector3d movementTo = position.Add(movement.Minus(gravity)); //Very complex to interpret.

	//Class for processes needed across objects.
	Utility u;
	u.Print(flyTo);
	u.Print(movementTo);
	u.Print(headTo);
	return 0;
}

