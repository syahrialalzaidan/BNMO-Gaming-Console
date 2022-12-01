/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KARAKINATOR_H_
#define __MESIN_KARAKINATOR_H_

#include "../boolean/boolean.h"
#define MARKakin '\n'
#define BLANKakin ' '
/* State Mesin */
extern char currentCharakin;
extern boolean EOPakin;
extern boolean isFileakin;

void LoadPitaAkin(char* filenameakin, boolean isFakin);
void StopLoadPitaAkin();
void STARTakin();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentCharakin adalah karakter pertama pada pita
          Jika currentCharakin != MARK maka EOP akan padam (false)
          Jika currentCharakin = MARK maka EOP akan menyala (true) */

void ADVakin();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharakin, currentCharakin != MARK
   F.S. : currentCharakin adalah karakter berikutnya dari currentCharakin yang lama,
          currentCharakin mungkin = MARK
          Jika  currentCharakin = MARK maka EOP akan menyala (true) */

char GetCCakin();
/* Mengirimkan currentCharakin */

boolean IsEOPakin();
/* Mengirimkan true jika currentCharakin = MARK */


#endif