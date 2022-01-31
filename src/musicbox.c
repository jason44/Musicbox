#include "music_box.h"

// **** G_Action Functions **** //
void settings_activated(GSimpleAction *settings_act, gpointer app_data) {
	printf("Hello\n");
}

void help_activated(GSimpleAction *help_act, gpointer app_data) {
	printf("Hellofj\n");
}

// **** Functions **** //

void get_playlist(GtkFileChooserNative *file_chooser, int response, gpointer app_data) {
	if (response == GTK_RESPONSE_ACCEPT) {
		GFile *playlist_dir = gtk_file_chooser_get_file(GTK_FILE_CHOOSER(file_chooser));
		printf("%s\n", g_file_get_path(playlist_dir));
		// GFileEnumerator *something
		// g_file_enumerate_children
		// access GFileEnumerator and get the GFile info
		// g_file_info_get_name
		// g_file_get_child --> pass in the name obtained from prev.
		// Linked List of GFile
		
		
		g_object_unref(playlist_dir);
	}
	gtk_native_dialog_hide(GTK_NATIVE_DIALOG(file_chooser));
	
}





