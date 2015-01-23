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

// File Struct

 typedef struct {
 	FILE * file_ptr;
 	char val_at_fileptr;
 	int curr_mem_index;
 	int curr_inp_index;
 	int * memptr_arr;
 	char * user_input;
 } BFFile;

// Function Declarations

void printHelp();

void parseCmdLineInput(int num_args, char * * args, int * ascii_flag, int * integer_flag, FILE * * input_file);

BFFile * BFFile_constructor(FILE * * file_ptr, char * * user_input, int * * memptr_arr);

