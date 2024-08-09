#include <iostream>
#include "temperature.h"
#include "distance.h"

int main() {
	double temp, distance;

	std::cout << "Enter a temperature in celsius: ";
	std::cin >> temp;
	std::cout << temp << "C in Fahrenheit is: " <<
		celsius_to_fahrenheit(temp) << "F" << std::endl;

	std::cout << "Enter a temperature in fahrenheit: ";
	std::cin >> temp;
	std::cout << temp << "F in Celsius is: " <<
		fahrenheit_to_celsius(temp) << "C" << std::endl;

	std::cout << "Enter a distance in kilometers: ";
	std::cin >> distance;
	std::cout << distance << "km in miles is: " <<
		km_to_miles(distance) << " miles" << std::endl;

	std::cout << "Enter a distance in miles: ";
	std::cin >> distance;
	std::cout << distance << " miles in kilometers is: " <<
		miles_to_km(distance) << "km" << std::endl;

	std::cout << "Enter a distance in meters: ";
	std::cin >> distance;
	feet_inches result;
	result = meters_to_feet(distance);
	std::cout << distance << " meters in feet/inches is: " <<
		result.feet << "'" << result.inches << "''" << std::endl;

	return 0;
}

/* SHORT ANSWER QUESTIONS
Q1 - What errors does the compiler point out if you forget to include the header files?

If header files are not included the compiler will say that some of the functions are undeclared because the
declaration of the functions are in the header file.

Q2 - What error does the compiler point out if you forget to define the variables temp
and distance at the beginning of main()?

It will say that temp and distance is an undeclared variable.


Q3 - What errors does the compiler point out if you forget to add the semi-colon (;)
at the end of "std::cin >> temp;"

it will say that a ';' is expected at the end of the statement.

Q4 - Does the compiler gives an error if temp and distance are defined as ints,
instead of doubles? If not, how come functions defined to operate on doubles, can
operate on ints? Check: https://www.cplusplus.com/doc/tutorial/typecasting/

The compiler will not give an error because the return value will be automatically type-casted into an integer and
also the other way around when an int is passed into the function, it will be type-casted into a double. So,
the value that is returned to temp and distance won't be represented after the decimal point meaning that if
km_to_miles(double) returned 12.07, only 12 will be stored in distance because distance is declared as an integer.

*/