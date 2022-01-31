#include <gtk/gtk.h>
#include <libadwaita-1/adwaita.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef MUSIC_BOX_
#define MUSIC_BOX_

// **** MACROS **** //
#define WIDGETS(a) ((Widgets*)a)

// **** STRUCTS **** //

typedef struct _Headerbar {
	GtkWidget 		*bar;

	GMenu 			*burger_menu;

	GMenuItem 		*settings_opt;	
	GMenuItem		*help_opt;	// do it

	GtkWidget 		*burger_menu_button;
	GtkWidget		*mute_button; // do it

} Headerbar;


typedef struct _Widgets {
	GtkApplication 				*app;
	GtkWidget 					*window;
	GtkFileChooserNative 		*file_chooser;
	Headerbar 					*headerbar;
} Widgets;

// **** GACTION FUNCTIONS **** //
void settings_activated(GSimpleAction *settings_act, gpointer app_data);

void help_activated(GSimpleAction *help_act, gpointer app_data);

// **** FUNCTIONS **** //
void startup(GtkApplication *app, gpointer app_data);

void activate(GtkApplication *app, gpointer app_data);

void shutdown(GtkApplication *app, gpointer app_data);

void get_playlist(GtkFileChooserNative *file_chooser, int response, gpointer app_data);


#endif
