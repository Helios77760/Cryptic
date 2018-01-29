//
// Created by Dylan Brasseur on 28/01/2018.
//
#include <zconf.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "constants.h"

void ef_none(routineInfo info)
{

}

void df_none(routineInfo info)
{

}
void cf_none(routineInfo info)
{

}
void es_none(routineInfo info)
{

}
void ds_none(routineInfo info)
{

}
void cs_none(routineInfo info)
{

}

routineInfo initRoutineInfo()
{
	routineInfo rinfo;
	rinfo.typeInput		= 0; //file
	rinfo.inputFile 	= STDIN_FILENO;
	rinfo.outputFile 	= STDOUT_FILENO;
	rinfo.brute 		= 0;
	rinfo.key 			= NULL;
	rinfo.lang			= 0; //fr
	rinfo.string 		= NULL;
	rinfo.alphabet		= ALPHABET_DEFAULT;
	rinfo.operationType	= INVALID;
	return rinfo;
}

void extendedToShortArgs(char* arg)
{
	if(!strcmp(arg, "--file"))
		strcpy(arg,"-f");
	else if(!strcmp(arg, "--output"))
		strcpy(arg,"-o");
	else if(!strcmp(arg, "--string"))
		strcpy(arg,"-s");
	else if(!strcmp(arg, "--encrypt"))
		strcpy(arg,"-e");
	else if(!strcmp(arg, "--decrypt"))
		strcpy(arg,"-d");
	else if(!strcmp(arg, "--algorithm"))
		strcpy(arg,"-a");
	else if(!strcmp(arg, "--key"))
		strcpy(arg,"-k");
	else if(!strcmp(arg, "--crack"))
		strcpy(arg,"-c");
	else if(!strcmp(arg, "--brute"))
		strcpy(arg,"-b");
	else if(!strcmp(arg, "--language"))
		strcpy(arg,"-L");
	else if(!strcmp(arg, "--help"))
		strcpy(arg,"-h");
	else if(!strcmp(arg, "--alphabet"))
		strcpy(arg,"-x");
	else if(!strcmp(arg, "--list"))
		strcpy(arg,"-l");
}

/*Options :
     * -f --file inputFile
     * -o --output outputFile
     * -s --string string
     * -e --encrypt encrypt
     * -d --decrypt decrypt
     * -a --algorithm algorithm
     * -k --key key
     * -c --crack crack
     * -b --brute bruteforce
     * -L --lang language
     * -h --help display help
     * -x --alphabet alphabet
     * -l --list affiche liste algorithmes
     */
routineInfo parseArgs(int argc, char* argv[])
{
	routineInfo rinfo = initRoutineInfo();
	char* arg;
	for(int i=0; i<argc; i++)
	{
		arg = argv[i];
		if(arg[0]=='-')
		{
			if(arg[1]=='-')
			{
				extendedToShortArgs(arg);
			}
			switch(arg[1])
			{
				case 'f':
					rinfo.inputFile = open(argv[++i], O_RDONLY);
					if(rinfo.inputFile ==-1)
						displayError("Cannot open input file");
					break;
				case 'o':
					rinfo.outputFile = open(argv[++i], O_WRONLY | O_CREAT, 0777);
					if(rinfo.outputFile ==-1)
						displayError("Cannot open output file");
					break;
				case 's':
					rinfo.string = argv[++i];
					break;
				case 'e':
					rinfo.operationType = ENCRYPT;
					break;
				case 'd':
					rinfo.operationType = DECRYPT;
					break;
				case 'a':
					rinfo.algorithm = findIndexString(algorithms, argv[++i], NUMBEROFALGO);
					if(rinfo.algorithm == UNDEFINED)
					{
						displayAlgorithms();
						displayError("Can't find algorithm");
					}

					break;
				case 'k':
					rinfo.key = argv[++i];
					break;
				case 'c':
					rinfo.operationType = CRACK;
					break;
				case 'b':
					rinfo.brute = 1;
					break;
				case 'l':
					displayAlgorithms();
					exit(EXIT_SUCCESS);
				case 'h':
					displayHelp();
					break;
				case 'x':
					rinfo.alphabet = argv[++i];
					break;
				case 'L':
					rinfo.lang = findIndexString(langs, argv[++i], NUMBEROFLANG);
					if(rinfo.lang == UNDEFINED)
					{
						displayLangs();
						displayError("Can't find language");
					}
					break;
				default:
					break;

			}
		}
	}

	return rinfo;

}

int findIndexString(char* array[], char* value, size_t length)
{
	for(int i=0; i < length; i++)
	{
		if(!strcmp(array[i], value))
			return i;
	}
	return UNDEFINED;
}

void displayError(char* message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void displayAlgorithms()
{
	printf("Available algorithms :\n");
	for(int i=0; i<NUMBEROFALGO;i++)
		printf("- %s\n", algorithms[i]);
}

void displayHelp()
{

}

void displayUsage()
{

}

void displayLangs()
{
	printf("Available languages :\n");
	for(int i=0; i<NUMBEROFLANG;i++)
		printf("- %s\n", langs[i]);
}