#include "bf_exec.h"

int main(int argc, char * * argv)
{
	int ascii_flag = 0;
	int integer_flag = 0;
	FILE * input_file;
	int * memptr_arr = calloc(1024, sizeof(int));
	// Validate command line input -- retrieve flags and file
	parseCmdLineInput(argc, argv, &ascii_flag, &integer_flag, &input_file);
	// Prompt user for input:
	char * user_input = calloc(1024, sizeof(char));
	printf("Input: ");
	scanf("%s", &user_input);
	// Create the file parser
	BFFile * bfptr = BFFile_constructor(&input_file, &user_input, &memptr_arr);



	return EXIT_SUCCESS;
}


/* To free:
 * memptr_arr
 * user_input
 * bfptr
 *
 *
 *
 *
 *
*/
