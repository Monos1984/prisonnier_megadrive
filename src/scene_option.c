/*****************************************************************
 * Nom ................. : scene_option.c                        *
 * Role ................ : gestion option du jeu                 *
 * Auteur .............. : Monos                                 *
 * Version ............. : 6/05/2020                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// =====================
// ** Variable global **
// =====================
unsigned char g_id_game;

// =============================
// ** Récuprer le type du jeu **
// =============================
unsigned char get_type_game()
{
  return g_id_game;
}

// ===============================
// ** Parametrer le type de jeu **
// ===============================
void set_id_game(unsigned char id_game)
{
  g_id_game = id_game;
}
