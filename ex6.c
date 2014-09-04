#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Adolf";
	char last_name[] = "Hitler";
	char empty_string = "";

	printf("My empty string is here: %s", empty_string);
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last_name %s.\n", last_name);
	// intentionally wrong code	
printf("My whole name is %s %c. %s.\n", initial,first_name, last_name);

	return 0;
	
}
