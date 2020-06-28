/*****************************************************************
 * Nom ................. : scene_game.h                          *
 * Role ................ :                                       *
 * Auteur .............. : Monos                                 *
 * Version ............. :                                       *
 *****************************************************************/

#ifndef SCENE_OPTION_H
  #define SCENE_OPTION_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================
  #define MODE_ISOLA 0
  #define MODE_EXTRA 1

	// ================================
	// ** Déclaration des prototypes **
	// ================================
  unsigned char get_type_game();
  void set_id_game(unsigned char id_game);

#endif
