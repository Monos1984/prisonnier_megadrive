/*******************************************************
* Nom .............. : main.h
* Role ............. : Header
* Modification ..... : 7/12/2018
********************************************************
* Fichier header main du programme.
* Ce fichier a pour but de regrouper les autres fichier
* include du programme, et librairie.
*******************************************************/

#ifndef MAIN_H 
	#define MAIN_H 

	// ===============================
	// ** Fichier include du projet **
	// ===============================

	// ----------------------
	// * Librairie générale *
	// ----------------------
	#include <genesis.h>
  #include "data.h"
  #include "../../res/resources.h"
	
	// ---------------------------------
	// * Fichier includes du programme *
	// ---------------------------------

  // ---------------------
  // * - fichier scene - *
  // ---------------------
  #include "scene_manager.h"
  #include "scene_game.h"
  #include "scene_option.h"

  // -------------------------
  // * - Les fichier class - *
  // -------------------------
  #include "class_map.h"
  #include "class_player.h"
  #include "class_input.h"



  // ==========================
  // ** Define decalage tiles**
  // ==========================
  #define TILES_DX 3
  #define TILES_DY 3
 #endif