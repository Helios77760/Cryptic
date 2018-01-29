//
// Created by Dylan Brasseur on 29/01/18.
//

#ifndef CRYPTIC_CONSTANTS_H
#define CRYPTIC_CONSTANTS_H

#define ALPHABET_DEFAULT "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_ALPHANUM "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

#include "includes/auto.h"
#include "includes/caesar.h"
#include "includes/playfair.h"
#include "includes/railfence.h"
#include "includes/vigenere.h"

char* algorithms[] 				= {"caesar", "vigenere", "auto", "playfair", "railfence", "", "", "", "", ""};
void* encryptFileRoutines[] 	= {ef_caesar, ef_vigenere, ef_auto, ef_playfair, ef_railfence, ef_none, ef_none, ef_none, ef_none, ef_none};
void* decryptFileRoutines[] 	= {df_caesar, df_vigenere, df_auto, df_playfair, df_railfence, df_none, df_none, df_none, df_none, df_none};
void* crackFileRoutines[] 		= {cf_caesar, cf_vigenere, cf_auto, cf_playfair, cf_railfence, cf_none, cf_none, cf_none, cf_none, cf_none};
void* encryptStringRoutines[] 	= {es_caesar, es_vigenere, es_auto, es_playfair, es_railfence, es_none, es_none, es_none, es_none, es_none};
void* decryptStringRoutines[] 	= {ds_caesar, ds_vigenere, ds_auto, ds_playfair, ds_railfence, ds_none, ds_none, ds_none, ds_none, ds_none};
void* crackStringRoutines[] 	= {cs_caesar, cs_vigenere, cs_auto, cs_playfair, cs_railfence, cs_none, cs_none, cs_none, cs_none, cs_none};

#endif //CRYPTIC_CONSTANTS_H
