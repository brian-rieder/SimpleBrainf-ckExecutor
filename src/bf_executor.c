#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ________________________Brainf*ck Command Listing________________________
 * |         |                                                             | 
 * |    >    |  increment pointer                                          |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    <    |  decrement pointer                                          |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    +    |  increment value at pointer                                 |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    -    |  decrement value at pointer                                 |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    [    |  begin loop (continues while value at pointer is non-zero)  |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    ]    |  end loop                                                   |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    ,    |  read one character from input into value at pointer        |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    .    |  print value at pointer to output as specified by mode      |
 * |_________|_____________________________________________________________|
 * |         |                                                             |
 * |    #    |  display debugging info                                     |
 * |_________|_____________________________________________________________|
*/

#define INCPTR_CMD '>'
#define DECPTR_CMD '<'
#define INCVAL_CMD '+'
#define DECVAL_CMD '-'
#define STLOOP_CMD '['
#define ENDLOOP_CMD ']'
#define READCH_CMD ','
#define PRINTCH_CMD '.'
#define DEBUG_INFO '#'

void printHelp() 
{
	printf("Simple Brainf*ck Executor (by Brian Rieder, January 2015)\n"
	   "Usage: bfexec [--ascii] [--integer] [FILE]\n"
	   "When a number of arguments not equal to three is input, this message\n"
	   "will be displayed. Three arguments should always be input, as the\n"
	   "compiler command, a mode switch, and the file name.\n"
	   "Examples:"
	   "\n    bfexec --ascii sample.bf"
	   "\n    bfexec -a sample.bf"
	   "\n    bfexec --integer sample.bf"
	   "\n    bfexec -i sample.bf\n"
	   "This allows for the file to be interpreted in ASCII or integer mode.\n"
	   "ASCII Mode:"
	   "\n    Interprets all values in cells as ASCII characters for purposes of printing."
	   "Integer Mode:"
	   "\n    Interprets all values in cells as integers for purposes of printing.\n"
	   "A prompt will (as of now) always appear prompting for potential input to use.\n");
	exit(1);
}

void parseCmdLineInput(int num_args, char * * args, int * ascii_flag, int * integer_flag, FILE * * input_file)
{
	// Check number of arguments -- a flag and file are the only format allowed
	if(num_args != 3)
		printHelp();
	// Check and set flags
	if(strcmp("--ascii", args[1]) == 0 || strcmp("-a", args[1]) || strcmp("--ascii", args[2]) == 0 || strcmp("-a", args[2]))
		*ascii_flag = 1;
	else if(strcmp("--integer", args[1]) == 0 || strcmp("-i", args[1]) || strcmp("--integer", args[2]) == 0 || strcmp("-i", args[2]))
		*integer_flag = 1;
	if((*ascii_flag && *integer_flag) || (!(*ascii_flag) && !(*integer_flag)))
		printHelp();
	// Check file extension -- otherwise open it
	if(strcmp(".bf", &(args[1][strlen(args[1]) - 3])) == 0) {
		*input_file = fopen(args[1], "r");
	}
	else if(strcmp(".bf", &(args[2][strlen(args[2]) - 3])) == 0) {
		*input_file = fopen(args[2], "r");
	}
	else
		printHelp();
}

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
