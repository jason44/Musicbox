#include "music_box.h"

int main(int argc, char *argv[]) {
	Widgets *app_data = WIDGETS(malloc(sizeof(Widgets)));
	if (app_data == NULL) {printf("Runtime error: failed to initialize app data\n"); return 1;}

	GtkApplication *app = gtk_application_new("com.github.jason44", G_APPLICATION_FLAGS_NONE);
	application_init(app, app_data);
	printf("no innit yet app\n");
	int status = g_application_run(G_APPLICATION(app), argc, argv);

	free(app_data);
	g_object_unref(app);
	return status;
}

void startup(GtkApplication *app, gpointer app_data) {
	GSimpleAction *settings_act = g_simple_action_new("settings", NULL);
	g_signal_connect(settings_act, "activate", G_CALLBACK(settings_activated), app_data);
	g_action_map_add_action(G_ACTION_MAP(WIDGETS(app_data)->app), G_ACTION(settings_act));

	GtkWidget *file_chooser = gtk_file_chooser_dialog_new("Choose Playlist",
													GTK_WINDOW(WIDGETS(app_data)->window),
													GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
													("_Cancel"),
													GTK_RESPONSE_CANCEL,
													("_Select"),
													GTK_RESPONSE_ACCEPT,
													NULL);
	WIDGETS(app_data)->file_chooser = file_chooser;
}

void activate(GtkApplication *app, gpointer app_data) {
	GtkWidget *window = gtk_application_window_new(WIDGETS(app_data)->app);
	app_window_init(window, app_data);

	Headerbar headerbar;
	headerbar.bar = gtk_header_bar_new();
	headerbar.settings_opt = g_menu_item_new("Settings", "app.settings");
	headerbar.menu = g_menu_new();
	headerbar.menu_button = gtk_menu_button_new();
	headerbar_init(&headerbar, app_data);

	GtkWidget *button = gtk_button_new_with_label("Activate");
	gtk_window_set_child(GTK_WINDOW(window), button);

	
	
	
	gtk_widget_show(WIDGETS(app_data)->file_chooser);
	gtk_widget_show(window);
}



