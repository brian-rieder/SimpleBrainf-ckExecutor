#include "bf_exec.h"

BFFile * BFFile_constructor(FILE * * file_ptr, char * * user_input, int * * memptr_arr) {
	BFFile * bfptr = malloc(sizeof(BFFile));
	bfptr->file_ptr = *file_ptr;
	bfptr->val_at_fileptr = '0';
	bfptr->curr_mem_index = 0;
	bfptr->curr_inp_index = 0;
	bfptr->memptr_arr = *memptr_arr;
	bfptr->user_input = *user_input;
	return bfptr;
}
