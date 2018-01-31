//
// Created by Helios on 31/01/2018.
//

#include <stdio.h>
#include <fcntl.h>
#include "../utils.h"
#include "../constants.h"
#include "../includes/subst.h"

void ef_subst(routineInfo info )
{
	char buffer;
	while(read(info.inputFile, &buffer, 1))
	{
		char* characterInAlphabet = strchr(info.alphabet, buffer);
		if(characterInAlphabet)
		{
			buffer = info.key[(characterInAlphabet-info.alphabet)];
		}
		write(info.outputFile, &buffer, 1);
	}
}

void df_subst(routineInfo info)
{
	char buffer;
	while(read(info.inputFile, &buffer, 1))
	{
		char* characterInAlphabet = strchr(info.key, buffer);
		if(characterInAlphabet)
		{
			buffer = info.alphabet[(characterInAlphabet-info.key)];
		}
		write(info.outputFile, &buffer, 1);
	}
}

void cf_subst(routineInfo info)
{
	lseek(info.inputFile, 0L, SEEK_END);
	long size = tell(info.inputFile);
	if(size <= 0)
	{
		displayError("cf_caesar : Can't read content of file");
	}
	if(size > MAXSTRINGSIZE)
	{
		warnSize("File too big", size, MAXSTRINGSIZE, "Truncating");
		size = MAXSTRINGSIZE;
	}
	lseek(info.inputFile, 0L, SEEK_SET);
	char* text = malloc((size+1) * sizeof(char));
	if(!text)
	{
		displayError("cf_caesar : Can't allocate");
	}
	if(read(info.inputFile, text, (unsigned int)size)==-1)
	{
		displayError("cf_caesar : Can't read inputfile");
	}
	text[size] = '\0';
	routineInfo rinfo = clone(info);
	rinfo.key = malloc(sizeof(char)*3);
	rinfo.string = text;
	char* result=NULL;
	char* frequencyAlpha = getFrequencyAlphabetFile(info);
	char* tempFreq = malloc(sizeof(char)*(strlen(rinfo.frequency)+1));
	strcpy(tempFreq, rinfo.frequency);
	rearrangeWithFrequencyAlphabet(frequencyAlpha, tempFreq, rinfo.alphabetSize);
	for(int i=0; i<info.alphabetSize; i++)
	{
		rinfo.key = frequencyAlpha;
		result = ds_subst(rinfo);
		printf("Key : %s\nText : %s", rinfo.key, result);
		if(proposeSolution())
			break;
		free(result);
		result=NULL;
	}
	if(result)
	{
		printf("\nKey = %s\n", rinfo.key);
		write(info.outputFile, result, (unsigned int)size);
	}else
	{
		printf("\nKey not found");
	}
	free(rinfo.key);
	rinfo.key = NULL;
}

char* es_subst(routineInfo info)
{
	int size = (int)strlen(info.string);
	char* result = malloc(sizeof(char)*(size+1));
	if(!result)
	{
		displayError("es_caesar : Can't allocate");
	}
	char newLetter;
	for(int i=0; i<size; i++)
	{
		newLetter = info.string[i];
		char* characterInAlphabet = strchr(info.alphabet, newLetter);
		if(characterInAlphabet)
		{
			newLetter = info.key[characterInAlphabet-info.alphabet];
		}

		result[i] = newLetter;
	}
	result[size]='\0';
	return result;
}

char* ds_subst(routineInfo info)
{
	int size = (int)strlen(info.string);
	char* result = malloc(sizeof(char)*(size+1));
	if(!result)
	{
		displayError("es_caesar : Can't allocate");
	}
	char newLetter;
	for(int i=0; i<size; i++)
	{
		newLetter = info.string[i];
		char* characterInAlphabet = strchr(info.key, newLetter);
		if(characterInAlphabet)
		{
			newLetter = info.alphabet[characterInAlphabet-info.key];
		}

		result[i] = newLetter;
	}
	result[size]='\0';
	return result;
}

char* cs_subst(routineInfo info)
{
	return NULL;
}