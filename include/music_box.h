#include <gtk/gtk.h>
#include <libadwaita-1/adwaita.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <sqlite3.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef MUSIC_BOX_
#define MUSIC_BOX_

// **** MACROS **** //
#define MUSIC_BOX(a) ((MusicBox*)a)

// **** STRUCTS **** //

typedef struct _Headerbar {
	GtkWidget 		*bar;

	GMenu 			*burger_menu;

	GMenuItem 		*settings_opt;	
	GMenuItem		*help_opt;

	GtkWidget 		*burger_menu_button;
	GtkWidget		*mute_button; // do it
	GtkWidget		*flap_button;
	

} Headerbar;


typedef struct _MusicBox {
	GtkApplication 				*app;
	GtkWidget 					*window;
	
	Headerbar 					headerbar;

	GtkWidget					*flap;
	GtkWidget 					*side_panel_box;

	GtkWidget 					*content_flap;
	GtkWidget					*content_box;

	GtkWidget					*scrollable_settings;
	GtkWidget					*playlist_clamp;
	GtkWidget					*settings_box;
	GtkWidget					*settings_group;
	GtkWidget					*playlist_row;

	GtkFileChooserNative 		*file_chooser;
	

} MusicBox;

// **** GACTION FUNCTIONS **** //
void settings_activated(GSimpleAction *settings_act, GVariant *parameter, gpointer app_data);

void help_activated(GSimpleAction *help_act, GVariant *parameter, gpointer app_data);

// **** FUNCTIONS **** //
void startup(GtkApplication *app, gpointer app_data);

void activate(GtkApplication *app, gpointer app_data);

void shutdown(GtkApplication *app, gpointer app_data);

void flap_button_clicked(GtkWidget *button, gpointer app_data);

void get_playlist(GtkFileChooserNative *file_chooser, int response, gpointer app_data);


#endif
