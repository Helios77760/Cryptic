//
// Created by Dylan Brasseur on 28/01/2018.
//
#include <zconf.h>
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
	return rinfo;
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
     * -l --lang language
     * -h --help display help
     * --alphabet alphabet
     * --list affiche liste algorithmes
     */
routineInfo parseArgs(int argc, char* argv[])
{
	routineInfo rinfo = initRoutineInfo();

	return rinfo;

}