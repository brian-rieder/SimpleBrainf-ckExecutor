#include "bf_exec.h"

int main(int argc, char * * argv)
{
	int ascii_flag = 0;
	int integer_flag = 0;
	FILE * input_file;
	// Validate command line input -- retrieve flags and file
	parseCmdLineInput(argc, argv, &ascii_flag, &integer_flag, &input_file);
	// Prompt user for input:
	char user_input[256];
	printf("Input: ");
	scanf("%s", &user_input);


	return 0;
}
