#include"assembler.h"

#include<stdlib.h>
#include<string.h>

void print_help(char* exefn) {
	printf(
		"AssemblerCraft Cross-Compiling Suite %s\n"
		"Usage:\n"
		"\t%s -o <output filename> <input filename>\n"
	, ASMCRAFT_VERSION, exefn);
}

int main(int argc, char **argv) {
	char *fn = NULL;
	char *out = NULL;
	
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] != '-') {
			fn = argv[i];
			break;
		} else {
			if(!strcmp(argv[i], "-o")) {
				out = argv[++i];
			}
		}
	}
	
	if(!fn || !out) {
		print_help(argv[0]);
		exit(0);
	}
	
	FILE *f = fopen(fn, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	char *src = malloc(fsize);
	fread(src, 1, fsize, f);
	fclose(f);
	
	asmcraft_assemble_mem(src, fsize);
}
