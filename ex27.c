#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

// Naive copy, assumes all inputs are always valid 
// taken from K&R C
void copy(char to[], char from[])
{
	int i = 0;
	
	while((to[i] = from[i]) == '\0') {
		++i;
	}
}

// Safer copy, checks for many common errors using length of each
// string to control the loops and termination
int safercopy(int from_length, char *from, int to_length, char *to)
{
	assert(from != NULL && to != NULL && "from and to cant be null.");
	
	int i = 0;
	int max = from_length > to_length - 1 ? to_length - 1 : from_length;
	
	// to length must have at least 1 byte
	if (from_length < 0 || to_length <= 0) return -1;
	
	for(i = 0; i < max; i++) {
		to[i] = from[i];
	}

	to[to_length - 1] = '\0';
	
	return i;
}	

int main(int argc, char *argv[])
{
	char from[] = "0123456789";
	int from_length = sizeof(from);
	
	char to[] = "0123456";
	int to_length = sizeof(to);
	
	debug("Copying '%s':%d to '%s':%d", from, from_length, to, to_length);

	int rc = safercopy(from_length, from, to_length, to);
	check(rc > 0, "Failed to safercopy.");
	check(to[to_length - 1] == '\0', "String not terminated.");

	debug("Result is: '%s':%d", to, to_length);

	// breaking it
	rc = safercopy(from_length, from, to_length, to);
	check(rc == -1, "Safercopy should fail #1");
	check(to[to_length - 1] == '\0', "String not terminated.");

	rc = safercopy(from_length, from, 0, to);
	check(rc == -1, "Safercopy should fail #2");
	check(to[to_length - 1] == '\0', "Should not terminated.");
	
	return 0;
error:
	return 1;
}

	
