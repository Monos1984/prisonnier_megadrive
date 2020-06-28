/*****************************************************************
 * Nom ................. : scene_manager.c                       *
 * Role ................ : gestion des scenes du jeu             *
 * Auteur .............. : Monos et michel louvet                *
 * Version ............. : 24/03/2019                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// ========================================
// ** Déclaration des variables globales **
// ========================================
unsigned char scene;

/***************************************************
 *             set_scene(id_scene)                 *
 ***************************************************
 *  But:                                           *
 *     Définit la variable scene                   *
 *                                                 *
 *  Paramètres :                                   *
 *     id_scene : Numeros de la scene              *
 *                                                 *
 *  Sortie :                                       * 
 *     Aucun                                       * 
 ***************************************************/
void set_scene(unsigned char id_scene)
{
  scene = id_scene;
}

/***************************************************
 *             get_scene()                         *
 ***************************************************
 *  But:                                           *
 *     Renvois la valeur de la variable scene      *
 *                                                 *
 *  Paramètres :                                   *
 *     Aucun                                       *
 *                                                 *
 *  Sortie :                                       * 
 *     Le numero de la scene en cours              * 
 ***************************************************/
unsigned char get_scene()
{
  return scene;
}
