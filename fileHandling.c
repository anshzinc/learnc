#include <stdio.h>
#include <stdlib.h>

void write_file()
{
	//--- File handling excercise---//
	// data
	char *names[] = {"Alpha", "Bravo", "Charlie", "Delta"};

	int i = 0;
	for (i = 0; i < 4; i++) {
		printf("Names are: %s\n", names[i]);
	}
	
	// write to a file named allNames.txt
	FILE *file; 
	file =  fopen("./allNames.txt", "w");
	
	if (!file) {
		printf("ERROR: failed at fopen.");
		exit(1);
	}

	for (i = 0; i < 4; i++) {
		fprintf(file, "%s ", names[i]);
	}
	
	fclose(file);
}

void read_file()
{
	char names[70];	

	FILE *file;

	file = fopen("./allNames.txt", "r");	

	while(fgets(names, 70, file) != NULL) {
		printf("Names are: %s\n", names);
	}
	
	fclose(file);
}

int main(int argc, char *argv[])
{
	read_file();

	return 0;
}
