#include <stdio.h>
#include <stdlib.h>

void printHelp() 
{
	printf("Simple Brainf*ck Executor (by Brian Rieder, January 2015)\n"
	   "Usage: bfexec [--help] [--ascii] [--integer] [FILE]\n"
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
	   "\n    Interprets all values in cells as integers for purposes of printing.\n");
	exit(1);
}

void parseCmdLineInput(int num_args, char * * args)
{
	int helpflag = 0;
	if(num_args != 3) {
		helpflag = 1;
	}
	if(helpflag == 1)
		printHelp();
}

int main(int argc, char * * argv)
{
	parseCmdLineInput(argc, argv);
	return 0;
}
