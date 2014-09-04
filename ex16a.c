#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
	struct Person who;
	
	who.name = name;
	who.age = age;
	who.height = height;
	who.weight = weight;	

	return who;
}

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("Age: %d\n", who.age);
	printf("Height: %d\n", who.height);
	printf("Weight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	struct Person peter = Person_create("Peter Griffin", 34, 120, 90);
	struct Person parker = Person_create("Parker Pen", 44, 132, 70);

	Person_print(peter);
	Person_print(parker);

	return 0;
}
