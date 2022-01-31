#include "music_box.h"

void activate(GtkApplication *app, gpointer app_data) {
    // WINDOW
	GtkWidget *window = gtk_application_window_new(WIDGETS(app_data)->app);
	    gtk_window_set_title(GTK_WINDOW(window), "Musicbox");
	    gtk_window_set_default_size(GTK_WINDOW(window), 500, 450);
        WIDGETS(app_data)->window = window;

    // HEADERBAR
	Headerbar headerbar;
	headerbar.bar = gtk_header_bar_new();
    	gtk_window_set_titlebar(GTK_WINDOW(window), headerbar.bar);
    
    // HAMBURGER MENU
	headerbar.burger_menu = g_menu_new();
    	headerbar.settings_opt = g_menu_item_new("Settings", "app.settings");
        headerbar.help_opt = g_menu_item_new("Help", "app.help");
        g_menu_append_item(headerbar.burger_menu, headerbar.settings_opt);
        g_menu_append_item(headerbar.burger_menu, headerbar.help_opt);

	headerbar.burger_menu_button = gtk_menu_button_new();
        gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(headerbar.burger_menu_button), G_MENU_MODEL(headerbar.burger_menu));
        gtk_menu_button_set_has_frame(GTK_MENU_BUTTON(headerbar.burger_menu_button), false);

	gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar.bar), headerbar.burger_menu_button);
    
	WIDGETS(app_data)->headerbar = &headerbar;

	g_object_unref(headerbar.settings_opt);
    g_object_unref(headerbar.help_opt);

    // ****  **** //
	GtkWidget *button = gtk_button_new_with_label("Activate");
	gtk_window_set_child(GTK_WINDOW(window), button);
	
	
	gtk_native_dialog_show(GTK_NATIVE_DIALOG(WIDGETS(app_data)->file_chooser));
	gtk_widget_show(window);
}

void shutdown(GtkApplication *app, gpointer app_data) {
	g_object_unref(WIDGETS(app_data)->file_chooser);
}