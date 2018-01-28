//
// Created by Dylan Brasseur on 28/01/2018.
//

#ifndef CRYPTIC_UTILS_H
#define CRYPTIC_UTILS_H

typedef struct _routineInfo
{
    int inputFile;
    int outputFile;
    char* key;
    int lang;
    int brute;
    char* string;
} routineInfo;

void ef_none(routineInfo info );

#endif //CRYPTIC_UTILS_H
