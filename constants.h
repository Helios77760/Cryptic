//
// Created by Dylan Brasseur on 29/01/18.
//

#ifndef CRYPTIC_CONSTANTS_H
#define CRYPTIC_CONSTANTS_H

#define MAXSTRINGSIZE 1048576

#define ALPHABET_DEFAULT "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_DEFAULT_SIZE 26
#define ALPHABET_ALPHANUM "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define ALPHABET_ALPHANUM_SIZE 36
#define ENCRYPT 0
#define DECRYPT 1
#define CRACK	2

#define NUMBEROFALGO 6
#define UNDEFINED (-1)
#define CAESAR 0
#define VIGENERE 1
#define AUTO 2
#define PLAYFAIR 3
#define RAILFENCE 4
#define SUBST 5

#define NUMBEROFLANG 2
#define FR 0
#define EN 1

#define FREQUENCY_FR "ESAITNRULODCPMVQFBGHJXYZWK"
#define FREQUENCY_EN "ETAOINSHRDLCUMWFGYPBVKJXQZ"

#define FILETYPE 0
#define STRINGTYPE 1

#include "utils.h"

extern char* algorithms[];

extern void (*encryptFileRoutines[])(routineInfo);
extern void (*decryptFileRoutines[])(routineInfo);
extern void (*crackFileRoutines[])(routineInfo);
extern char* (*encryptStringRoutines[])(routineInfo);
extern char* (*decryptStringRoutines[])(routineInfo);
extern char* (*crackStringRoutines[])(routineInfo);

extern char* langs[];


#endif //CRYPTIC_CONSTANTS_H
