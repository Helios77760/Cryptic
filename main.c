//
// Created by Dylan Brasseur on 28/01/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "includes/auto.h"
#include "includes/caesar.h"
#include "includes/playfair.h"
#include "includes/railfence.h"
#include "includes/vigenere.h"
#include "utils.h"





char* algorithms[] = {"caesar", "vigenere", "auto", "playfair", "railfence", "", "", "", "", ""};
void* encryptFileRoutines[] = {ef_caesar, ef_vigenere, ef_auto, ef_playfair, ef_railfence, ef_none, ef_none, ef_none, ef_none, ef_none};

void encryptFile(int inputfile, int outputfile, int algorithm, char* key)
{

}

void decryptFile(int inputfile, int outputfile, int algorithm, char* key)
{

}

void crackFile(int inputfile, int outputfile, int algorithm, void* info)
{

}

char* encryptString(char* data, int algorithm, char* key)
{

}

char* decryptString(char* data, int algorithm, char* key)
{

}

char* crackString(char* data, int algorithm, void* info)
{

}
int main(int argc, char* argv[]) {
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
     */
    return 0;
}