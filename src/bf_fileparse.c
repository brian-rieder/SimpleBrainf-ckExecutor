#include "bf_exec.h"

BFFile * BFFile_constructor(FILE * * file_ptr, char * * user_input, int * * memptr_arr) 
{
	BFFile * bfptr = malloc(sizeof(BFFile));
	bfptr->file_ptr = *file_ptr;
	bfptr->val_at_fileptr = '0';
	bfptr->val_at_inputind = '0';
	bfptr->curr_mem_index = 0;
	bfptr->curr_inp_index = -1;
	bfptr->memptr_arr = *memptr_arr;
	bfptr->user_input = *user_input;
	return bfptr;
}

void debuginfos(BFFile * bfptr)
{
	printf("val_at_fileptr: %c\n", bfptr->val_at_fileptr);
	printf("curr_mem_index: %d\n", bfptr->curr_mem_index);
	printf("curr_inp_index: %d\n", bfptr->curr_inp_index);
	printf("memptr_arr (first five): %d %d %d %d %d\n", 
		bfptr->memptr_arr[0], bfptr->memptr_arr[1], bfptr->memptr_arr[2],
		bfptr->memptr_arr[3], bfptr->memptr_arr[4]);
	printf("user_input: %s\n", bfptr->user_input);
}

void parseBFFile_ascii(BFFile * bfptr)
{
	bfptr->val_at_fileptr = fgetc(bfptr->file_ptr);
	while(bfptr->val_at_fileptr != EOF) {
		switch(bfptr->val_at_fileptr) {
			case INCPTR_CMD:
				incptrHandler(bfptr);
				break;
			case DECPTR_CMD:
				decptrHandler(bfptr);
				break;
			case INCVAL_CMD:
				incvalHandler(bfptr);
				break;
			case DECVAL_CMD:
				decvalHandler(bfptr);
				break;
			case ENDLOOP_CMD:
				endloopHandler(bfptr);
				break;
			case STLOOP_CMD:
				startloopHandler(bfptr);
				break;
			case READCH_CMD:
				readchHandler(bfptr);
				break;
			case PRINTCH_CMD:
				printchHandler(bfptr);
				break;
		}
		// Iterate to next character in the file
		bfptr->val_at_fileptr = fgetc(bfptr->file_ptr);
	}
	debuginfos(bfptr);
}

void parseBFFile_integer(BFFile * bfptr)
{
	printf("Integer mode not yet enabled\n");
}

void incptrHandler(BFFile * bfptr)
{
	if(bfptr->curr_mem_index == 1023)
		FATAL("Overextended memory bounds -- aborting.")
	bfptr->curr_mem_index += 1;
}

void decptrHandler(BFFile * bfptr)
{
	if(bfptr->curr_mem_index == 0)
		FATAL("Cannot access memory below cell zero -- aborting.")
	bfptr->curr_mem_index -= 1;
}

void incvalHandler(BFFile * bfptr)
{
	bfptr->memptr_arr[bfptr->curr_mem_index] += 1;
}

void decvalHandler(BFFile * bfptr)
{
	bfptr->memptr_arr[bfptr->curr_mem_index] -= 1;
}

void startloopHandler(BFFile * bfptr)
{
	int cmd_count = 1;
	int * iterator = &(bfptr->memptr_arr[bfptr->curr_mem_index]);
	bfptr->val_at_fileptr = fgetc(bfptr->file_ptr);
	while(*iterator > 0)
	{
		while(bfptr->val_at_fileptr != ENDLOOP_CMD) {
			switch(bfptr->val_at_fileptr) {
				case INCPTR_CMD:
					incptrHandler(bfptr);
					break;
				case DECPTR_CMD:
					decptrHandler(bfptr);
					break;
				case INCVAL_CMD:
					incvalHandler(bfptr);
					break;
				case DECVAL_CMD:
					decvalHandler(bfptr);
					break;
				case STLOOP_CMD:
					startloopHandler(bfptr);
					break;
				case READCH_CMD:
					readchHandler(bfptr);
					break;
				case PRINTCH_CMD:
					printchHandler(bfptr);
					break;
				case EOF:
					FATAL("No loop terminator found before EOF -- aborting.")
					break;
			}
			++cmd_count;
			bfptr->val_at_fileptr = fgetc(bfptr->file_ptr);
		}
		iterator = &(bfptr->memptr_arr[bfptr->curr_mem_index]);
		if(*iterator != 0) {
			fseek(bfptr->file_ptr, (-1) * cmd_count, SEEK_CUR);
			cmd_count = 1;
		}
		bfptr->val_at_fileptr = fgetc(bfptr->file_ptr);
	}
}

void endloopHandler(BFFile * bfptr)
{
	FATAL("No initiated loop to terminate -- aborting.");
}

void readchHandler(BFFile * bfptr)
{
	++bfptr->curr_inp_index;
	bfptr->val_at_inputind = bfptr->user_input[curr_inp_index];
	bfptr->memptr_arr[curr_mem_index] = bfptr->val_at_inputind;
}

void printchHandler(BFFile * bfptr)
{

}
