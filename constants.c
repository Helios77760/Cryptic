//
// Created by Dylan Brasseur on 30/01/2018.
//


#include "includes/auto.h"
#include "includes/caesar.h"
#include "includes/playfair.h"
#include "includes/railfence.h"
#include "includes/vigenere.h"
#include "constants.h"

char* algorithms[] 				= {"caesar", "vigenere", "auto", "playfair", "railfence", "", "", "", "", ""};

void (*encryptFileRoutines[])(routineInfo) 	= {ef_caesar, ef_vigenere, ef_auto, ef_playfair, ef_railfence, ef_none, ef_none, ef_none, ef_none, ef_none};
void (*decryptFileRoutines[])(routineInfo) 	= {df_caesar, df_vigenere, df_auto, df_playfair, df_railfence, df_none, df_none, df_none, df_none, df_none};
void (*crackFileRoutines[])(routineInfo) 		= {cf_caesar, cf_vigenere, cf_auto, cf_playfair, cf_railfence, cf_none, cf_none, cf_none, cf_none, cf_none};
char* (*encryptStringRoutines[])(routineInfo) 	= {es_caesar, es_vigenere, es_auto, es_playfair, es_railfence, es_none, es_none, es_none, es_none, es_none};
char* (*decryptStringRoutines[])(routineInfo) 	= {ds_caesar, ds_vigenere, ds_auto, ds_playfair, ds_railfence, ds_none, ds_none, ds_none, ds_none, ds_none};
char* (*crackStringRoutines[])(routineInfo) 	= {cs_caesar, cs_vigenere, cs_auto, cs_playfair, cs_railfence, cs_none, cs_none, cs_none, cs_none, cs_none};

char* langs[] = {"FR", "EN"};