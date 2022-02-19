#include "music_box.h"

void startup(GtkApplication *app, gpointer app_data) {
    // **** GACTIONS **** //
	GSimpleAction *settings_action = g_simple_action_new("settings", NULL);	
	g_signal_connect(settings_action, "activate", G_CALLBACK(settings_activated), app_data);
	g_action_map_add_action(G_ACTION_MAP(MUSIC_BOX(app_data)->app), G_ACTION(settings_action));

    GSimpleAction *help_action = g_simple_action_new("help", NULL);
    g_signal_connect(help_action, "activate", G_CALLBACK(help_activated), app_data);
    g_action_map_add_action(G_ACTION_MAP(MUSIC_BOX(app_data)->app), G_ACTION(help_action));
	GtkFileChooserNative *file_chooser = gtk_file_chooser_native_new("Choose Playlist Folder",
														GTK_WINDOW(MUSIC_BOX(app_data)->window), 
														GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
														"Select", "Cancel");
	g_signal_connect(file_chooser, "response", G_CALLBACK(get_playlist), app_data);
	MUSIC_BOX(app_data)->file_chooser = file_chooser;
	// move file_chooser to activate

	//gtk_actionable_set_action_name -> to apply actions to widgets
}
