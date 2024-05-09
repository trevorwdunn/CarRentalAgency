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
	cout << "CAR RENTAL AGENCY MENU" << endl;
	cout << "a - Add car to inventory" << endl;
	cout << "d - Delete car by id from inventory" << endl;
	cout << "u - Update car by id condition in inventory" << endl;
	cout << "s - Display one car by id from inventory" << endl;
	cout << "i - Display list of all cars in inventory" << endl;
	cout << "c - Rent a car by id in inventory" << endl;
	cout << "r - Return a car by id to inventory" << endl;
	cout << "q - Quit" << endl;
	do {
		cout << "Choose an option:\n\n";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'q' && choice != 'a' && choice != 'd' && choice != 'u' &&
			 choice != 's' && choice != 'i' && choice != 'c' && choice != 'r');

	// Process the user's choice
	switch (choice) {
	case 'a':
		addCar(cars);
		displayMenu(cars);
		break;
	case 'd':
		deleteCar(cars);
		displayMenu(cars);
		break;
	case 'u':
		updateCarCondition(cars);
		displayMenu(cars);
		break;
	case 's':
		displayCar(cars);
		displayMenu(cars);
		break;
	case 'i':
		displayInventory(cars);
		displayMenu(cars);
		break;
	case 'c':
		rentCar(cars);
		displayMenu(cars);
		break;
	case 'r':
		returnCar(cars);
		displayMenu(cars);
		break;
	case 'q':
		cout << "Done\n";
		exit(0);
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
		 << "Enter an ID:\n";
	cin >> id;
	cin.ignore();
	cout << "Enter the make:\n";
	getline(cin, make);
	cout << "Enter the model:\n";
	getline(cin, model);
	cout << "Enter the year:\n";
	cin >> year;
	cout << "Enter the condition (new, slightly_used, used):\n\n";
	cin >> condition;
	cars.push_back(Car(id, make, model, year, condition));
	// cin.get(); // Wait for user to press a key
}

void displayCar(vector<Car> &cars) {
	int id;
	cout << "DISPLAY CAR IN INVENTORY\n";
	cout << "Enter the ID of the car to display:\n\n";
	cin >> id;

	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });

	if (it != cars.end()) {
		cout << "ID: " << it->getID() << ", " << it->getMake() << " "
			 << it->getModel() << ", " << it->getYear() << ", "
			 << it->getCondition() << ", "
			 << (it->isRented() ? "not available\n" : "is available\n") << endl;
	} else {
		cout << "Car not found." << endl;
	}

	// cin.ignore();
	cin.get(); // Wait for user to press a key
			   // displayMenu(cars);
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

	// cin.ignore();
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

	// cin.ignore();
	cin.get(); // Wait for user to press a key
	displayMenu(cars);
}

void displayInventory(vector<Car> &cars) {
	cout << "DISPLAY ALL CARS IN INVENTORY\n";

	for (const auto &car : cars) {
		cout << "ID: " << car.getID() << ", " << car.getMake() << " "
			 << car.getModel() << ", " << car.getYear() << ", "
			 << car.getCondition() << ", "
			 << (car.isRented() ? "not available" : "is available") << endl;
	}
	cout << endl;

	// cin.ignore();
	cin.get(); // Wait for user to press a key
			   // displayMenu(cars);
}

void updateCarCondition(vector<Car> &cars) {
	int id;
	string newCondition;
	cout << "UPDATE CAR CONDITION IN INVENTORY\n";
	cout << "Enter the ID of the car to update condition:\n";
	cin >> id;
	auto it = find_if(cars.begin(), cars.end(),
					  [id](const Car &car) { return car.getID() == id; });
	if (it != cars.end()) {
		// Car object found, call setCondition on it
		cout << "Enter the condition (new, slightly_used, used):\n\n";
		cin >> newCondition;
		it->setCondition(newCondition);
	} else {
		cout << "Car not found." << endl;
	}

	// cin.ignore();
	cin.get(); // Wait for user to press a key
			   // displayMenu(cars);
}

bool deleteCar(vector<Car> &cars) {
	int id;
	bool result;
	cout << "REMOVE CAR FROM INVENTORY\n";
	cout << "Enter the ID of the car to delete:\n\n";
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

	// cin.ignore();
	cin.get(); // Wait for user to press a key
	return result;
}