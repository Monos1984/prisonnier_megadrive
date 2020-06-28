/*****************************************************************
 * Nom ................. : class_input.c                         *
 * Role ................ : gestion de la map                     *
 * Auteur .............. : Monos                                 *
 * Version ............. : 19/11/2019                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"


// =============
// * Get_Input *
// =============
unsigned char get_input(unsigned char id_pad)
{
 if (JOY_readJoypad(id_pad)	 & BUTTON_RIGHT)
 {
   return 6;
 }
 
 else if (JOY_readJoypad(id_pad) & BUTTON_LEFT)
 {
   return 4;
 }

 else if (JOY_readJoypad(id_pad) & BUTTON_UP)
 {
   return 8;
 }

 else if (JOY_readJoypad(id_pad) & BUTTON_DOWN)
 {
   return 2;
 }

 else if (JOY_readJoypad(id_pad) & BUTTON_A)
 {
   return 10;
 }

else if (JOY_readJoypad(id_pad) & BUTTON_B)
 {
   return 11;
 }

else if (JOY_readJoypad(id_pad) & BUTTON_C)
 {
   return 12;
 }

else if (JOY_readJoypad(id_pad) & BUTTON_START)
 {
   return 13;
 }



else
{
   return 0;
}


 return 0;
}




