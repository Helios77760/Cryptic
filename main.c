//
// Created by Dylan Brasseur on 28/01/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "constants.h"


int main(int argc, char* argv[]) {
    routineInfo rinfo = parseArgs(argc, argv);
    displayRoutineInfo(rinfo);

    if(validateRoutine(rinfo))
    {
        if(rinfo.typeInput == FILETYPE)
        {
            if(rinfo.operationType == ENCRYPT)
            {
                encryptFileRoutines[rinfo.algorithm](rinfo);
            }else if(rinfo.operationType == DECRYPT)
            {
                decryptFileRoutines[rinfo.algorithm](rinfo);
            }else if(rinfo.operationType == CRACK)
            {
                crackFileRoutines[rinfo.algorithm](rinfo);
            }
        }else if(rinfo.typeInput == STRINGTYPE)
        {
            FILE* fp = fdopen(rinfo.outputFile, "w");
            if(rinfo.operationType == ENCRYPT)
            {
                fprintf(fp, "%s", encryptStringRoutines[rinfo.algorithm](rinfo));
            }else if(rinfo.operationType == DECRYPT)
            {
                fprintf(fp, "%s", decryptStringRoutines[rinfo.algorithm](rinfo));
            }else if(rinfo.operationType == CRACK)
            {
                fprintf(fp, "%s", crackStringRoutines[rinfo.algorithm](rinfo));
            }
        }
	    printf("Operation success !");
    }else
    {
        printf("Invalid routine info\n");
    }
    return 0;
}