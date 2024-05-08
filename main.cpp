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
void returnCar(std::vector<Car> &cars);
void displayInventory(std::vector<Car> &cars);
void updateCarCondition(std::vector<Car> &cars);

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

		std::cout << "CAR RENTAL AGENCY MENU" << std::endl;
		std::cout << "a - Add car to inventory" << std::endl;
		std::cout << "d - Delete car by id from inventory" << std::endl;
		std::cout << "u - Update car by id condition in inventory" << std::endl;
		std::cout << "s - Display one car by id from inventory" << std::endl;
		std::cout << "i - Display list of all cars in inventory" << std::endl;
		std::cout << "c - Rent a car by id in inventory" << std::endl;
		std::cout << "r - Return a car by id to inventory" << std::endl;
		std::cout << "q - Quit" << std::endl;

		std::cout << "Choose an option: \n";
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
		break;
	case 'd':
		std::cout << "Delete a car by id from the inventory" << std::endl;
		deleteCar(cars);
		break;
	case 'u':
		std::cout << "Update a car by id condition in inventory" << std::endl;
		updateCarCondition(cars);
		break;
	case 's':
		std::cout << "Display one car by id from inventory" << std::endl;
		displayCar(cars);
		break;
	case 'i':
		std::cout << "Display list of all cars in inventory" << std::endl;
		displayInventory(cars);
		break;
	case 'c':
		std::cout << "Rent a car by id in inventory" << std::endl;
		rentCar(cars);
		break;
	case 'r':
		std::cout << "Return a car by id in inventory" << std::endl;
		returnCar(cars);
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
	std::cout << "Car added to inventory." << std::endl;
	std::cout << "Press any key to continue...";
	std::cin.get(); // Wait for user to press a key
}

void displayCar(std::vector<Car> &cars) {
	int id;
	std::cout << "Enter the ID of the car you want to display: ";
	std::cin >> id;

	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		std::cout << "Car ID: " << it->getID() << " Make: " << it->getMake()
				  << " Model: " << it->getModel() << " Year: " << it->getYear()
				  << " Condition: " << it->getCondition()
				  << " Rented: " << it->isRented() << std::endl;
	} else {
		std::cout << "Car not found." << std::endl;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
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
			it->toggleRented();
			std::cout << "Car rented." << std::endl;
		}
	} else {
		std::cout << "Car not found." << std::endl;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void returnCar(std::vector<Car> &cars) {
	int id;
	std::cout << "Enter the ID of the car you want to display: ";
	std::cin >> id;

	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		if (!it->isRented()) {
			std::cout << "Car is already returned." << std::endl;
		} else {
			it->toggleRented();
			std::cout << "Car returned." << std::endl;
		}
	} else {
		std::cout << "Car not found." << std::endl;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void displayInventory(std::vector<Car> &cars) {
	for (const auto &car : cars) {
		std::cout << "Car ID: " << car.getID() << " Make: " << car.getMake()
				  << " Model: " << car.getModel() << " Year: " << car.getYear()
				  << " Condition: " << car.getCondition()
				  << " Rented: " << car.isRented() << std::endl;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void updateCarCondition(std::vector<Car> &cars) {
	int id;
	std::cout << "Enter the ID of the car you want to update: ";
	std::cin >> id;
	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });
	if (it != cars.end()) {
		// Car object found, call setCondition on it
		it->setCondition();
	} else {
		std::cout << "Car not found." << std::endl;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

bool deleteCar(std::vector<Car> &cars) {
	int id;
	bool result;
	std::cout << "Enter the ID of the car you want to delete: ";
	std::cin >> id;
	auto it = std::find_if(cars.begin(), cars.end(),
						   [id](const Car &car) { return car.getID() == id; });
	if (it != cars.end()) {
		// Car object found, call setCondition on it
		cars.erase(it);
		result = true;
	} else {
		std::cout << "Car not found." << std::endl;
		result = false;
	}
	std::cout << "Press any key to continue...";
	std::cin.ignore();
	std::cin.get(); // Wait for user to press a key
	displayMenu(cars);
	return result;
}