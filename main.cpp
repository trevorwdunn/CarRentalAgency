#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"

bool isValidChoice(char choice);
void displayMenu(std::vector<Car> &cars);
void addCar(std::vector<Car> &cars);
bool deleteCar(std::vector<Car> &cars);
void displayCar(std::vector<Car> &cars);
void rentCar(std::vector<Car> &cars);

int main() {
	std::vector<Car> cars;

	displayMenu(cars);

	return 0;
}

bool isValidChoice(char choice) {
	return choice == 'a' || choice == 'd' || choice == 'u' || choice == 'u' ||
		   choice == 's' || choice == 'i' || choice == 'c' || choice == 'r' ||
		   choice == 'q';
}

void displayMenu(std::vector<Car> &cars) {
	char choice = ' ';
	do {

		std::cout << "CAR RENTAL INVENTORY MENU" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "a) Add a car to inventory" << std::endl;
		std::cout << "d) Delete a car by id from the inventory" << std::endl;
		std::cout << "u) Update a car by id condition in inventory"
				  << std::endl;
		std::cout << "s) Display one car by id from inventory" << std::endl;
		std::cout << "i) Display list of all cars in inventory" << std::endl;
		std::cout << "c) Rent a car by id in inventory" << std::endl;
		std::cout << "r) Return a car by id in inventory" << std::endl;
		std::cout << "q) Quit" << std::endl;

		std::cout << "Enter your choice: ";
		std::cin >> choice;
		choice = std::tolower(choice);
	}

	while (choice != 'q' && choice != 'a' && choice != 'd' && choice != 'u' &&
		   choice != 's' && choice != 'i' && choice != 'c' && choice != 'r');

	// Process the user's choice
	switch (choice) {
	case 'a':
		std::cout << "Add a car to inventory" << std::endl;
		addCar(cars);
		displayMenu(cars);
	case 'd':
		std::cout << "Delete a car by id from the inventory" << std::endl;
		break;
	case 'u':
		std::cout << "Update a car by id condition in inventory" << std::endl;
		break;
	case 's':
		std::cout << "Display one car by id from inventory" << std::endl;
		displayCar(cars);
		break;
	case 'i':
		std::cout << "Display list of all cars in inventory" << std::endl;
		break;
	case 'c':
		std::cout << "Rent a car by id in inventory" << std::endl;
		break;
	case 'r':
		std::cout << "Return a car by id in inventory" << std::endl;
		break;
	case 'q':
		break;
	default:
		std::cout << "Invalid choice. Please enter a valid option: \n";
	}
}

void addCar(std::vector<Car> &cars) {
	int id;
	std::string make, model, condition;
	int year;

	std::cout << "ADD CAR TO INVENTORY\n"
			  << "Enter an ID: ";
	std::cin >> id;
	std::cin.ignore();
	std::cout << "Enter the make: ";
	std::getline(std::cin, make);
	std::cout << "Enter the model: ";
	std::getline(std::cin, model);
	std::cout << "Enter the year: ";
	std::cin >> year;
	std::cout << "Enter the condition (new, slightly_used, used): ";
	std::cin.ignore();
	std::getline(std::cin, condition);

	cars.push_back(Car(id, make, model, year, condition));
}

void displayCar(std::vector<Car> &cars) {
	int id;
	std::cout << "Enter the ID of the car you want to display: ";
	std::cin >> id;

	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		std::cout << "Car ID: " << it->getID() << std::endl;
		std::cout << "Make: " << it->getMake() << std::endl;
		std::cout << "Model: " << it->getModel() << std::endl;
		std::cout << "Year: " << it->getYear() << std::endl;
		std::cout << "Condition: " << it->getCondition() << std::endl;
		std::cout << "Rented: " << it->isRented() << std::endl;
	} else {
		std::cout << "Car not found." << std::endl;
	}
}

void rentCar(std::vector<Car> &cars) {
	int id;
	std::cout << "Enter the ID of the car you want to display: ";
	std::cin >> id;

	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		if (it->isRented()) {
			std::cout << "Car is already rented." << std::endl;
		} else {
			std::cout << "Car is available for rent." << std::endl;
		}
	} else {
		std::cout << "Car not found." << std::endl;
	}
}