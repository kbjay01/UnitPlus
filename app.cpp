#include <iostream>
#include <conio.h>

/*
**UNDER CONSTRUCTION**
**WORK IN PROGRESS**
*/

unsigned char getChar(unsigned char stage) {
	char ch = 0;
	bool legal = false;

	/*Stage codes and their meaning
	0 - Default initial value
	-------------------------
	1 - Works for Main Menu -> menu()
	---------------------------------
	2 - Works as a unit choice -> unitChoice()
	------------------------------------------
	21 - Works as a choice for output unit -> insideGramUnitChoice()
	----------------------------------------------------------------
	22 - Works as a choice for output unit -> insideKilogramUnitChoice()
	--------------------------------------------------------------------
	*/

	while (legal == false) {
		ch = _getch();
		std::cout << ch;

		if (stage == 1) {
			// First main menu
			if (ch == '0' || ch == '1' || ch == '2') legal = true;
		}

		if (stage == 2) {
			// Weight menu
			if (ch == '0' || ch == '1' || ch == '2') legal = true;

			if (stage == 21) {
				// Weight, Grams to -> ?
				if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4') legal = true;
			}

			if (stage == 22) {
				// Weight, Kilograms to -> ?
				if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || (ch == '5')) legal = true;
			}
		}
		return ch;
	}
}

void drawHeader() {
	system("cls");
	std::cout << "Unit Converter" << std::endl;
	std::cout << "--------------" << std::endl;
}

// **WEIGHT**

// **WEIGHT CONVERSION FUNCTIONS**

// Kilograms -> something
double kilogramsToGrams(double kilograms) { return (kilograms * 1000); }
double kilogramsToMiligrams(double kilograms) { return (kilograms * 1000000); }
double kilogramsToOunces(double kilograms) { return (kilograms * 35.2739619); }
double kilogramsToPounds(double kilograms) { return (kilograms * 2.20462262); }
double kilogramsToTons(double kilograms) { return (kilograms / 1000); }

// Grams -> something
double gramsToKilograms(double grams) { return (grams / 1000); }
double gramsToMiligrams(double grams) { return (grams * 1000); }
double gramsToOunces(double grams) { return (grams * 0.0352739619); }
double gramsToPounds(double grams) { return (grams * 0.00220462262); }

// **WEIGHT MENUS**

char insideKilogramUnitChoice() {
	drawHeader();
	std::cout << "1. Kilograms to Grams" << std::endl;
	std::cout << "2. Kilograms to Milligrams" << std::endl;
	std::cout << "3. Kilograms to Ounces" << std::endl;
	std::cout << "4. Kilograms to Pounds" << std::endl;
	std::cout << "5. Kilograms to Tons" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "0. Back" << std::endl;

	char second_unit_choice = getChar(22);
	// If user wants to go back -> run Second stage
	if (second_unit_choice == '0') return 4;


	drawHeader();
	double input_value = 0;

	std::cout << "Enter amount of kilograms: ";
	std::cin >> input_value;

	switch (second_unit_choice) {
	case '1':
		// kg -> g
		std::cout << input_value << "kg is " << kilogramsToGrams(input_value) << " g" << std::endl;
		break;

	case '2':
		// kg -> mg
		std::cout << input_value << "kg is " << kilogramsToMiligrams(input_value) << " mg" << std::endl;
		break;

	case '3':
		// kg -> oz
		std::cout << input_value << "kg is " << kilogramsToOunces(input_value) << " oz" << std::endl;
		break;

	case '4':
		// kg -> lb
		std::cout << input_value << "kg is " << kilogramsToPounds(input_value) << " lb" << std::endl;
		break;
	case '5':
		//kg -> t
		std::cout << input_value << "kg is " << kilogramsToTons(input_value) << " t" << std::endl;

	}
	return _getch();
}

char insideGramUnitChoice() {
	drawHeader();
	std::cout << "1. Grams to Kilograms" << std::endl;
	std::cout << "2. Grams to Milligrams" << std::endl;
	std::cout << "3. Grams to Ounces" << std::endl;
	std::cout << "4. Grams to Pounds" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "0. Back" << std::endl;

	char second_unit_choice = getChar(21);

	// If user wants to go back -> run Second stage
	if (second_unit_choice == '0') return 2;

	drawHeader();
	double input_value = 0;
	std::cout << "Enter amount of grams: ";
	std::cin >> input_value;

	switch (second_unit_choice) {
	case '1':
		// g -> kg
		std::cout << input_value << "g is " << gramsToKilograms(input_value) << " kg" << std::endl;
		break;

	case '2':
		// g -> mg
		std::cout << input_value << "g is " << gramsToMiligrams(input_value) << " mg" << std::endl;
		break;

	case '3':
		// g -> oz
		std::cout << input_value << "g is " << gramsToOunces(input_value) << " oz" << std::endl;
		break;

	case '4':
		// g -> lb
		std::cout << input_value << "g is " << gramsToPounds(input_value) << " lb" << std::endl;
		break;
	}
	return _getch();

}

unsigned char unitWeightChoice() {
	// This is Weight menu stage
	drawHeader();
	std::cout << "1. Grams" << std::endl;
	std::cout << "2. Kilograms" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "0. Back" << std::endl;

	char unit_choice = getChar(2);

	switch (unit_choice) {
	case '1':
		// run insideGramUnitChoice()
		return 1;
	case '2':
		// run insideKilogramUnitChoice()
		return 3;

	case '0':
		// run menu()
		return 255;
	}
	return 255;
}

// **LENGTH**

unsigned char unitLengthChoice() {
	// This is Length menu stage
	drawHeader();
	std::cout << "1. Centimeters" << std::endl;
	std::cout << "2. Meters" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "0. Back" << std::endl;

	char unit_choice = getChar(2);

	switch (unit_choice) {
	case '1':
		// run insideGramUnitChoice()
		return 1;
	case '2':
		// run insideKilogramUnitChoice()
		return 3;

	case '0':
		// run menu()
		return 255;
	}
	return 255;
}


void weightFunctionsHandler(char action) {
	char message = 0;

	/* Message codes and their meaning
	0 - Default initial value
	--------------------------
	1 - Returned value from unitWeightChoice(), runs insideGramUnitChoice()
	------------------------------------------------------------------
	2 - Returned value from insideGramUnitChoice(), falls back to previous
	menu, starts unitWeightChoice() again
	-------------------------------------
	3 - Returned value from unitWeightChoice(), runs insideKilogramUnitChoice()
	----------------------------------------------------------------------
	4 - Returned value from insideKilogramUnitChoice(), falls back to
	previous menu, starts unitWeightChoice() again
	----------------------------------------------
	*/

	if (action == 0) message = unitWeightChoice();
	if (message == 1) message = insideGramUnitChoice();
	if (message == 2) message = unitWeightChoice();
	if (message == 3) message = insideKilogramUnitChoice();
	if (message == 4) message = unitWeightChoice();
}

// **THIS IS MAIN MENU**
bool menu() {
	drawHeader();
	std::cout << "1. Weight" << std::endl;
	std::cout << "2. Length" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << "0. Exit" << std::endl;
	char unit_category = getChar(1);

	switch (unit_category) {
	case '1':
		weightFunctionsHandler(0);
		break;
	case '0':
		system("cls");
		std::cout << "Thanks. Goodbye :)";
		return false;
	}
	return true;
}


int main() {
	bool active = true;
	while (active == true) active = menu();
	return 255;
}
