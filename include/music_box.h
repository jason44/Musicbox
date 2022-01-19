#include <gtk/gtk.h>
// #include <adwaita.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef MUSIC_BOX_
#define MUSIC_BOX_

// **** Macros **** //
#define WIDGETS(a) ((Widgets*)a)

// **** Structs **** //

typedef struct _Headerbar {
	GtkWidget 		*bar;
	GMenuItem 		*settings_opt;	
	GMenuItem		*help_opt;	// do it
	GMenu 			*menu;
	GtkWidget 		*menu_button;

} Headerbar;


typedef struct _Widgets {
	GtkApplication 	*app;
	GtkWidget 		*window;
	GtkWidget 		*file_chooser;
	Headerbar 		*headerbar;
} Widgets;

// **** G_Action Functions **** //
void settings_activated(GSimpleAction *settings_act, gpointer app_data);

void help_activated(GSimpleAction *help_act, gpointer app_data);

// **** Functions **** //
void startup(GtkApplication *app, gpointer app_data);

void activate(GtkApplication *app, gpointer app_data);

void application_init(GtkApplication *app, Widgets *app_data);

void app_window_init(GtkWidget *window, gpointer app_data);

void headerbar_init(Headerbar* headerbar, gpointer app_data);


#endif
