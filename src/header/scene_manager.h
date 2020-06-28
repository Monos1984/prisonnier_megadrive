/*****************************************************************
 * Nom ................. : scene_manager.h                       *
 * Role ................ : gestion des scenes du jeu             *
 * Auteur .............. : Monos et michel louvet                *
 * Version ............. : 24/03/2019                            *
 *****************************************************************/

#ifndef SCENE_MANAGER_H
  #define SCENE_MANAGER_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================
  
	#define SCENE_INIT 0
	#define SCENE_SPLASH 1
  #define SCENE_TITLE_SCREEN 2
	#define SCENE_GAME 10
  #define SCENE_LEVEL 11
	#define SCENE_OPTION 20
	#define SCENE_MAP 30
	#define SCENE_MENU 40
	#define SCENE_BATTLE 50
  #define SCENE_CREDIT 60
	// ================================
	// ** Déclaration des prototypes **
	// ================================
	void set_scene(unsigned char id_scene);
  unsigned char get_scene();

#endif
