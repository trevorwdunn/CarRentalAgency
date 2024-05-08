#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"

using namespace std;

bool isValidChoice(char choice);
void displayMenu(vector<Car> &cars);
void addCar(vector<Car> &cars);
bool deleteCar(vector<Car> &cars);
void displayCar(vector<Car> &cars);
void rentCar(vector<Car> &cars);
void returnCar(vector<Car> &cars);
void displayInventory(vector<Car> &cars);
void updateCarCondition(vector<Car> &cars);

int main() {
	vector<Car> cars;

	displayMenu(cars);

	return 0;
}

bool isValidChoice(char choice) {
	return choice == 'a' || choice == 'd' || choice == 'u' || choice == 'u' ||
		   choice == 's' || choice == 'i' || choice == 'c' || choice == 'r' ||
		   choice == 'q';
}

void displayMenu(vector<Car> &cars) {
	char choice = ' ';
	do {

		cout << "CAR RENTAL AGENCY MENU" << endl;
		cout << "a - Add car to inventory" << endl;
		cout << "d - Delete car by id from inventory" << endl;
		cout << "u - Update car by id condition in inventory" << endl;
		cout << "s - Display one car by id from inventory" << endl;
		cout << "i - Display list of all cars in inventory" << endl;
		cout << "c - Rent a car by id in inventory" << endl;
		cout << "r - Return a car by id to inventory" << endl;
		cout << "q - Quit" << endl;

		cout << "Choose an option: \n";
		cin >> choice;
		choice = tolower(choice);
	}

	while (choice != 'q' && choice != 'a' && choice != 'd' && choice != 'u' &&
		   choice != 's' && choice != 'i' && choice != 'c' && choice != 'r');

	// Process the user's choice
	switch (choice) {
	case 'a':
		addCar(cars);
		break;
	case 'd':
		deleteCar(cars);
		break;
	case 'u':
		updateCarCondition(cars);
		break;
	case 's':
		displayCar(cars);
		break;
	case 'i':
		displayInventory(cars);
		break;
	case 'c':
		rentCar(cars);
		break;
	case 'r':
		returnCar(cars);
		break;
	case 'q':
		break;
	default:
		cout << "Invalid choice. Please enter a valid option: \n";
	}
}

void addCar(vector<Car> &cars) {
	int id;
	string make, model, condition;
	int year;

	cout << "ADD CAR TO INVENTORY\n"
		 << "Enter an ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter the make: ";
	getline(cin, make);
	cout << "Enter the model: ";
	getline(cin, model);
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the condition (new, slightly_used, used): ";
	cin.ignore();
	getline(cin, condition);

	cars.push_back(Car(id, make, model, year, condition));
	cout << "Car added to inventory." << endl;
	cin.get(); // Wait for user to press a key
}

void displayCar(vector<Car> &cars) {
	int id;
	cout << "Enter the ID of the car you want to display: ";
	cin >> id;

	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		cout << "Car ID: " << it->getID() << " || "
			 << "Make: " << it->getMake() << " || "
			 << "Model: " << it->getModel() << " || "
			 << "Year: " << it->getYear() << " || "
			 << "Condition: " << it->getCondition() << " || "
			 << "Rented: " << it->isRented() << endl;
	} else {
		cout << "Car not found." << endl;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void rentCar(vector<Car> &cars) {
	int id;
	cout << "Enter the ID of the car you want to display: ";
	cin >> id;

	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		if (it->isRented()) {
			cout << "Car is already rented." << endl;
		} else {
			it->toggleRented();
			cout << "Car rented." << endl;
		}
	} else {
		cout << "Car not found." << endl;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void returnCar(vector<Car> &cars) {
	int id;
	cout << "Enter the ID of the car you want to display: ";
	cin >> id;

	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		if (!it->isRented()) {
			cout << "Car is already returned." << endl;
		} else {
			it->toggleRented();
			cout << "Car returned." << endl;
		}
	} else {
		cout << "Car not found." << endl;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void displayInventory(vector<Car> &cars) {
	cout << "Current Inventory:\n";
	cout << "==================\n";

	for (const auto &car : cars) {
		cout << "Car ID: " << car.getID() << " || "
			 << " Make: " << car.getMake() << " || "
			 << " Model: " << car.getModel() << " || "
			 << " Year: " << car.getYear()
			 << " Condition: " << car.getCondition() << " || "
			 << " Rented: "
			 << " || " << car.isRented() << endl;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void updateCarCondition(vector<Car> &cars) {
	int id;
	string newCondition;
	cout << "Enter the ID of the car you want to update: ";
	cin >> id;
	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });
	if (it != cars.end()) {
		// Car object found, call setCondition on it
		cout << "What is the new condition of the vehicle?";
		cin >> newCondition;
		it->setCondition(newCondition);
	} else {
		cout << "Car not found." << endl;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

bool deleteCar(vector<Car> &cars) {
	int id;
	bool result;
	cout << "Enter the ID of the car you want to delete: ";
	cin >> id;
	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });
	if (it != cars.end()) {
		// Car object found, call setCondition on it
		cars.erase(it);
		result = true;
	} else {
		cout << "Car not found." << endl;
		result = false;
	}

	cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
	return result;
}