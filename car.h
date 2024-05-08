#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>

class Car {
  private:
	int id;
	std::string make;
	std::string model;
	int year;
	std::string condition;
	bool rented;

  public:
	// Constructor
	Car(int id, const std::string &make, const std::string &model, int year,
		const std::string &condition)
		: id(id), make(make), model(model), year(year), condition(condition),
		  rented(false) {}

	// Getters
	int getID() const;
	std::string getMake() const;
	std::string getModel() const;
	int getYear() const;
	std::string getCondition() const;
	bool isRented() const;

	// Setters
	std::string setCondition();
	void toggleRented();

	// Other Functions
	// void displayCar(int id, std::string make, std::string model, int year,
	void displayCar(int id, std::string make, std::string model, int year,
					std::string condition, bool rented);
};

#endif // CAR_H