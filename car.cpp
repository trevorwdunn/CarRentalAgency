#include "car.h"
#include <iostream>

// Constructor
/*
Car::Car(int id, const std::string &make, const std::string &model, int year,
		 const std::string &condition)
	: id(id), make(make), model(model), year(year), condition(condition),
	  rented(false) {} */

// Getters
int Car::getID() const { return id; }

std::string Car::getMake() const { return make; }

std::string Car::getModel() const { return model; }

int Car::getYear() const { return year; }

std::string Car::getCondition() const { return condition; }

bool Car::isRented() const { return rented; }

// Setters
std::string Car::setCondition() {
	std::string newCondition;
	std::cout << "Enter the new condition of the car: ";
	std::cin >> newCondition;
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

void displayCar(int id, std::string make, std::string model, int year,
				std::string condition, bool rented) {
	std::cout << "Car ID: " << id << std::endl;
	std::cout << "Make: " << make << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Condition: " << condition << std::endl;
	std::cout << "Rented: " << rented << std::endl;
}
