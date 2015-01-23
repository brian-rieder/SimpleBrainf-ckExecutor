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
	// scanf("%s", &user_input);
	int input_itr = 0;
	char ch = getchar();
	while(ch != '\n' && input_itr < 1024) {
		user_input[input_itr] = ch;
		ch = getchar();
		++input_itr;
	}
	user_input[input_itr] = '\0';
	// Create the file parser
	BFFile * bfptr = BFFile_constructor(&input_file, &user_input, &memptr_arr);
	// Begin parsing the file
	if(ascii_flag)
		parseBFFile_ascii(bfptr);
	else if(integer_flag)
		parseBFFile_integer(bfptr);
	else
		FATAL("Flag error");
	// Exit message upon completion
	printf("Execution complete.\n");
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
