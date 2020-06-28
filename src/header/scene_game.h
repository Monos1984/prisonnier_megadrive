/*****************************************************************
 * Nom ................. : scene_game.h                          *
 * Role ................ :                                       *
 * Auteur .............. : Monos                                 *
 * Version ............. :                                       *
 *****************************************************************/

#ifndef SCENE_GAME_H
  #define SCENE_GAME_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================

	// ================================
	// ** Déclaration des prototypes **
	// ================================
	void scene_game();
  void move_curseur(unsigned char id_player);
  void moved_player(unsigned char id_player);
  void draw_trape_game(unsigned char id_player);
  unsigned char test_lost_player(unsigned char id_player);
  void testing_game_over();
 void return_title_screen();

#endif
