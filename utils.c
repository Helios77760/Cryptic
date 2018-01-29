//
// Created by Dylan Brasseur on 28/01/2018.
//
#include <zconf.h>
#include "utils.h"
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
	rinfo.inputFile 	= STDIN_FILENO;
	rinfo.outputFile 	= STDOUT_FILENO;
	rinfo.brute 		= 0;
	rinfo.key 			= "";
	rinfo.lang			= 0;
	rinfo.string 		= NULL;
}