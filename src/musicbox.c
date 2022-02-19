#include "music_box.h"

// **** GACTION FUNCTIONS **** // Found in startup.c
void settings_activated(GSimpleAction *settings_act, GVariant *parameter, gpointer app_data) {
	printf("TEST DIDN't WORK\n");
	GtkWidget *content_flap = MUSIC_BOX(app_data)->content_flap;
		if (adw_flap_get_reveal_flap(ADW_FLAP(content_flap)) == false) {
		adw_flap_set_reveal_flap(ADW_FLAP(content_flap), true);
		printf("reveal\n");
		//gtk_widget_set_child_visible(MUSIC_BOX(app_data)->content_box, false);
		gtk_widget_hide(MUSIC_BOX(app_data)->content_box);
	}
	else {
		adw_flap_set_reveal_flap(ADW_FLAP(content_flap), false);
		printf("hide\n");
		//gtk_widget_set_child_visible(MUSIC_BOX(app_data)->content_box, true);
		gtk_widget_show(MUSIC_BOX(app_data)->content_box);

	}
	return;
}

void help_activated(GSimpleAction *help_act, GVariant *parameter, gpointer app_data) {
	printf("Hellofj\n");
}

// **** CALLBACK FUNCTIONS **** //
void flap_button_clicked(GtkWidget *button, gpointer app_data) {
	GtkWidget *flap_p = MUSIC_BOX(app_data)->flap;
	if (adw_flap_get_reveal_flap(ADW_FLAP(flap_p)) == false) {
		adw_flap_set_reveal_flap(ADW_FLAP(flap_p), true);
		printf("reveal\n");
	}
	else {
		adw_flap_set_reveal_flap(ADW_FLAP(flap_p), false);
		printf("hide\n");
	}
	return;
}

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





