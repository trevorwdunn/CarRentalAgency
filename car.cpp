#include "car.h"
#include <iostream>

using namespace std;

// Constructor

Car::Car(int id, const string &make, const string &model, int year,
		 const string &condition)
	: id(id), make(make), model(model), year(year), condition(condition),
	  rented(false) {}

// Getters
int Car::getID() const { return id; }

string Car::getMake() const { return make; }

string Car::getModel() const { return model; }

int Car::getYear() const { return year; }

string Car::getCondition() const { return condition; }

bool Car::isRented() const { return rented; }

// Setters
string Car::setCondition(std::string newCondition) {
	condition = newCondition;
	return condition;
}

void Car::toggleRented() {
	if (rented) {
		rented = false;
	} else {
		rented = true;
	}
}

void displayCar(int id, string make, string model, int year, string condition,
				bool rented) {
	cout << "Car ID: " << id << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Condition: " << condition << endl;
	cout << "Rented: " << rented << endl;
}
