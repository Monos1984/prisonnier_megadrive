/*****************************************************************
 * Nom ................. : inir.c                                *
 * Role ................ : gestion initiation                    *
 * Auteur .............. : Monos                                 *
 * Version ............. : 0.0.0                                 *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// ===================
// * int main()      *
// ===================

void set_init_megadrive()
{
  // --------------------------------------------
  // * Reglage de la résolution de la megadrive *
  // --------------------------------------------

  // Resolution en 256 * 224 pixel soit  16 x 14 tiles (16x16)

  VDP_setScreenWidth256(); // 256 px (16 tiles à l'écran)
  VDP_setScreenHeight224 (); // 224px (14 tiles à l'écran)
  VDP_setPlaneSize	(64,32,FALSE); // Tailles virtuel de 32x16 tiles)

}