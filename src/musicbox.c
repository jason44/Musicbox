#include "music_box.h"

// **** G_Action Functions **** //
void settings_activated(GSimpleAction *settings_act, gpointer app_data) {
	printf("Hello\n");
}

// **** Functions **** //
void application_init(GtkApplication *app, Widgets *app_data) {
	g_signal_connect(app, "startup", G_CALLBACK(startup), app_data);
	g_signal_connect(app, "activate", G_CALLBACK(activate), app_data);
	app_data->app = app;
}

void app_window_init(GtkWidget *window, gpointer app_data) {
	gtk_window_set_title(GTK_WINDOW(window), "Musicbox");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 450);
	WIDGETS(app_data)->window = window;
}

void headerbar_init(Headerbar *headerbar, gpointer app_data) {
	g_menu_append_item(headerbar->menu, headerbar->settings_opt);
	gtk_menu_button_set_menu_model(headerbar->menu_button, G_MENU_MODEL(headerbar->menu));
	gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar->bar), headerbar->menu_button);
	gtk_window_set_titlebar(GTK_WINDOW(WIDGETS(app_data)->window), headerbar->bar);
	WIDGETS(app_data)->headerbar = headerbar;

	g_object_unref(headerbar->settings_opt);
}




