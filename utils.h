//
// Created by Dylan Brasseur on 28/01/2018.
//

#ifndef CRYPTIC_UTILS_H
#define CRYPTIC_UTILS_H

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
} routineInfo;

void ef_none(routineInfo info);
void df_none(routineInfo info);
void cf_none(routineInfo info);
void es_none(routineInfo info);
void ds_none(routineInfo info);
void cs_none(routineInfo info);

void displayHelp();
void displayUsage();
void diplayAlgorithms();

routineInfo initRoutineInfo();
routineInfo parseArgs(int argc, char* argv[]);

#endif //CRYPTIC_UTILS_H
