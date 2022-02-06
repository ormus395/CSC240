#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double askForPercentage();
int computeDucks(int initialPop, double gRateOfDucks,
	double gRateOfDucksWBoots, double gRateOfDucksWOBoots,
	int months, int printTable);

/*

Program algorithm

while the user wants to:

	Ask for birth rate of ducks per month
	Ask for Initial Pop
	Ask for Standard Deathrate
	Ask for fungal death rate with boots
	Ask for death rate with fungus and no boots
	Ask for percentage with boots
	Ask for length of time in months
	Ask the user if they want to display a table of results

	compute the duck population results

	if table print table

	CALCULATIONS:
	Use the following formula to calculate how many ducks you have at the end of each month:
 Bnew = Bold  + Bold • g
 where:
  Bnew = the number of ducks at the end of the month
  Bold  = the number of ducks at the beginning of the month
  g      = the growth rate

The growth rate represents how fast the flock is multiplying, as a percentage of the current population.  The
growth rate is computed as follows:
g = b - d
where:
b = birth rate (percentage of baby ducks per duck per month)
d = death rate (percentage of dead ducks per duck per month),

A birth rate of 0.10 means that the number of baby ducks is 10% of the number of ducks.

Notice that the birth rate and death rate are percentages of the current population, so the number of new babies
born or the number of deaths each month increases as the population grows.

To consider the effect of the foot fungus and the duck boots, we will also use the following variation to the basic
formula.  Separate the ducks into two groups: those that have boots and those that don't.  To compute the
population of the ducks in the presence of the fungus, use the following instead...
  g = b - (d  + f)
where:
b = birth rate (percentage of baby ducks per duck per month)
d = standard death rate (percentage of dead ducks per duck per month),
f = death rate from the foot fungus

The death rate will be two different numbers for the two groups:
 fA = fungus death rate for ducks with boots
 fB = fungus death rate for ducks without boots

To compute how fast the duck population is growing, repeat these calculations for however many months are
necessary.  Compute two sets of results: the population without the fungus, and the population with the fungus.

You must use double precision variables to do the calculations, but the current population (the number of ducks) at
the end of each month must be rounded to the nearest integer.  (No fractional ducks; too messy.)  The integer
result must be used as the starting population for the next month.


*/
int main() {
	// b = birthrate
	// double regular g rate
	// g = b - d
	// double groowth of ducks with boots and fungus
	// g = b - (d + aF)

	// double growth of ducks without boots and fungus
	// g = b - (d +Bf)

	double birthrate = 0.6;
	double deathrate = 0.1;
	double growthrate = birthrate - deathrate;

	cout << computeDucks(400, growthrate, 0, 0, 5, 0);
	return 0;
}

// THis method will be given the initual pop of ducks
// 3 growth rates (without fungus, with fungus with boots, 
// with fungus wuhtout boots
// and an int 0 or 1 indicating the user wants a printed table of results
// This method computes the monthly population of ducks

// bNew = bOld + bOld * g
// g = b - d
// b = %
// g = b - (d + Af) growth rate affected by ducks with boots
// g = b - (d + Bf) without boots

// compute the growth rates pass to this method
// growth rates do no change
int computeDucks
(int initialPop, double gRateOfDucks,
	double gRateOfDucksWBoots, double gRateOfDucksWOBoots,
	int months, int printTable) {
	//Bnew = Bold  + Bold • g 
	int popOfDucks = initialPop;
	int popOfDucksWBoots = 0;
	int popOfDucksWOBoots = 0;

	for (int i = 0; i < months; i++) {
		popOfDucks = popOfDucks + (popOfDucks * gRateOfDucks);
	}

	return popOfDucks;
}


// this method asks fpr number between 0 and 1 and returns it
double askForPercentage() {
	double dRate = 0.0;

	do {
		cout << "Please enter a number between 0 and 1, with 1 being inclusive: ";

		cin >> dRate;
	} while (dRate > 1.0 || dRate < 0.0);

	return dRate;
}

// 
double getPositiveNumber() {
	double positiveNumber;

	do {
		cout << "Please enter a positive number: ";
		cin >> positiveNumber;
	} while (positiveNumber < 0);

	return positiveNumber;
}