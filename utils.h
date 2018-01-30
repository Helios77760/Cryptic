//
// Created by Dylan Brasseur on 28/01/2018.
//

#ifndef CRYPTIC_UTILS_H
#define CRYPTIC_UTILS_H

#include <stdlib.h>

typedef struct _routineInfo
{
	int typeInput;
    int inputFile;
    int outputFile;
    char* key;
    int lang;
    int brute;
    char* string;
	char* alphabet;
	int operationType;
	int algorithm;
} routineInfo;

void ef_none(routineInfo info);
void df_none(routineInfo info);
void cf_none(routineInfo info);
char* es_none(routineInfo info);
char* ds_none(routineInfo info);
char* cs_none(routineInfo info);

void displayHelp();
void displayUsage();
void displayAlgorithms();
void displayLangs();
void displayError(char* message);
void displayRoutineInfo(routineInfo rinfo);

routineInfo initRoutineInfo();
routineInfo parseArgs(int argc, char* argv[]);
int validateRoutine(routineInfo rinfo);

void extendedToShortArg(char* arg);
int findIndexString(char* array[], char* value, size_t length);



#endif //CRYPTIC_UTILS_H
