#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"

int main() {
	bool isValidChoice(char choice) {
		return choice == 'a' || choice == 'r' || choice == 'd' ||
			   choice == 's' || choice == 'q';
	}

	void displayMenu() {
		std::cout << "Car Rental Inventory Menu" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "a) Add a car" << std::endl;
		std::cout << "r) Remove a car" << std::endl;
		std::cout << "d) Display inventory" << std::endl;
		std::cout << "s) Search for a car" << std::endl;
		std::cout << "q) Quit" << std::endl;
	}

	int main() {
		char choice;

		do {
			displayMenu();
			std::cout << "Enter your choice: ";
			std::cin >> choice;

			while (!isValidChoice(choice)) {
				std::cout << "Invalid choice. Please enter a valid option: ";
				std::cin >> choice;
			}

			// Process the selected option

		} while (choice != 'q');

		std::cout << "Done" << std::endl;

		return 0;
	}
}