//
// Created by Dylan Brasseur on 28/01/2018.
//

#include <zconf.h>
#include <errno.h>
#include <stdio.h>
#include "../includes/caesar.h"
#include "../constants.h"
void ef_caesar(routineInfo info)
{
	char* endptr;
	int key = strtol(info.key, &endptr, 10);
	if(errno == EINVAL || errno == ERANGE || *endptr!='\0' || info.key==endptr)
	{
		displayError("Invalid key");
	}

	key %= info.alphabetSize;
	char buffer[1];
	while(read(info.inputFile, buffer, 1))
	{
		char* characterInAlphabet = strchr(info.alphabet, buffer[0]);
		if(characterInAlphabet)
		{
			int newLetterIndex = ((int)(characterInAlphabet-info.alphabet)+key)%info.alphabetSize;
			if(newLetterIndex < 0)
				newLetterIndex+=info.alphabetSize;
			buffer[0] = *(newLetterIndex+info.alphabet);
		}
		write(info.outputFile, buffer, 1);
	}

}

void df_caesar(routineInfo info)
{
	char* endptr;
	int key = strtol(info.key, &endptr, 10);
	if(errno == EINVAL || errno == ERANGE || *endptr!='\0' || info.key==endptr)
	{
		displayError("Invalid key");
	}

	key %= info.alphabetSize;
	char buffer[1];
	while(read(info.inputFile, buffer, 1))
	{
		char* characterInAlphabet = strchr(info.alphabet, buffer[0]);
		if(characterInAlphabet)
		{
			int newLetterIndex = ((int)(characterInAlphabet-info.alphabet)-key)%info.alphabetSize;
			if(newLetterIndex < 0)
				newLetterIndex+=info.alphabetSize;
			buffer[0] = *(newLetterIndex+info.alphabet);
		}
		write(info.outputFile, buffer, 1);
	}
}

void cf_caesar(routineInfo info)
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

	if(info.brute)
	{
		routineInfo rinfo = clone(info);
		rinfo.key = malloc(sizeof(char)*3);
		rinfo.string = text;
		int i=0;
		char* result=NULL;
		for(; i<info.alphabetSize;i++)
		{
			sprintf(rinfo.key, "%d", i);
			result = ds_caesar(rinfo);
			printf("Key : %d\nText : %s", i, result);
			if(proposeSolution())
				break;
			free(result);
			result=NULL;
		}
		if(result)
		{
			printf("\nKey = %d\n", i);
			write(info.outputFile, result, (unsigned int)size);
		}else
		{
			printf("\nKey not found");
		}
		free(rinfo.key);
		rinfo.key = NULL;
	}else
	{
		routineInfo rinfo = clone(info);
		rinfo.key = malloc(sizeof(char)*3);
		rinfo.string = text;
		char* result=NULL;
		char* frequencyAlpha = getFrequencyAlphabetFile(info);
		char* frequenceLetters = info.lang == FR ? FREQUENCY_FR : (info.lang == EN ? FREQUENCY_EN : ALPHABET_DEFAULT);
		int key;
		for(int i=0; i<info.alphabetSize; i++)
		{
			for(int j=0; j<info.alphabetSize; i++)
			{
				printf("%c -> %c\n", frequencyAlpha[i], frequenceLetters[j]);
				key = frequencyAlpha[i] - frequenceLetters[j];
				sprintf(rinfo.key, "%d", key);
				result = ds_caesar(rinfo);
				printf("Key : %d\nText : %s", key, result);
				if(proposeSolution())
					break;
				free(result);
				result=NULL;
			}
		}
		if(result)
		{
			printf("\nKey = %d\n", key);
			write(info.outputFile, result, (unsigned int)size);
		}else
		{
			printf("\nKey not found");
		}
		free(rinfo.key);
		rinfo.key = NULL;
	}
}

char* es_caesar(routineInfo info)
{
	char* endptr;
	int key = strtol(info.key, &endptr, 10);
	if(errno == EINVAL || errno == ERANGE || *endptr!='\0' || info.key==endptr)
	{
		displayError("Invalid key");
	}

	key %= info.alphabetSize;
	int size = (int)strlen(info.string);
	char* result = malloc(sizeof(char)*(size+1));
	if(!result)
	{
		displayError("es_caesar : Can't allocate");
	}
	for(int i=0; i<size; i++)
	{

		char* characterInAlphabet = strchr(info.alphabet, info.string[i]);
		if(!characterInAlphabet)
		{
			displayError("Character not in alphabet");
		}
		int newLetterIndex = ((int)(characterInAlphabet-info.alphabet)+key)%info.alphabetSize;
		if(newLetterIndex < 0)
			newLetterIndex+=info.alphabetSize;
		result[i] = *(newLetterIndex+info.alphabet);
	}
	result[size]='\0';
	return result;
}

char* ds_caesar(routineInfo info)
{
	char* endptr;
	int key = strtol(info.key, &endptr, 10);
	if(errno == EINVAL || errno == ERANGE || *endptr!='\0' || info.key==endptr)
	{
		displayError("Invalid key");
	}

	key %= info.alphabetSize;
	int size = (int)strlen(info.string);
	char* result = malloc(sizeof(char)*(size+1));
	if(!result)
	{
		displayError("es_caesar : Can't allocate");
	}
	for(int i=0; i<size; i++)
	{
		char* characterInAlphabet = strchr(info.alphabet, info.string[i]);
		if(!characterInAlphabet)
		{
			result[i] = info.string[i];
		} else
		{
			int newLetterIndex = ((int)(characterInAlphabet-info.alphabet)-key)%info.alphabetSize;
			if(newLetterIndex < 0)
				newLetterIndex+=info.alphabetSize;
			result[i] = *(newLetterIndex+info.alphabet);
		}
	}
	result[size]='\0';
	return result;
}

char* cs_caesar(routineInfo info)
{
	return NULL;
}