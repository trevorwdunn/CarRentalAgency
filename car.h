#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>

using namespace std;
class Car {
  private:
	int id;
	string make;
	string model;
	int year;
	string condition;
	bool rented;

  public:
	// Constructor
	Car(int id, const string &make, const string &model, int year,
		const string &condition);

	// Getters
	int getID() const;
	string getMake() const;
	string getModel() const;
	int getYear() const;
	string getCondition() const;
	bool isRented() const;

	// Setters
	string setCondition(std::string newCondition);
	void toggleRented();

	// Other Functions
	// void displayCar(int id, string make, string model, int year,
	void displayCar(int id, string make, string model, int year,
					string condition, bool rented);
};

#endif // CAR_H