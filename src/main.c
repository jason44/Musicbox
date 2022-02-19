#include "music_box.h"

int main(int argc, char *argv[]) {
	MusicBox * music_box;
	if (music_box == NULL) {printf("Runtime error: failed to initialize app data\n"); return 1;}

	GtkApplication *app = gtk_application_new("com.github.jason44", G_APPLICATION_FLAGS_NONE);
		music_box->app = app;
		g_signal_connect(app, "startup", G_CALLBACK(startup), music_box);
		g_signal_connect(app, "activate", G_CALLBACK(activate), music_box);
		g_signal_connect(app, "shutdown", G_CALLBACK(shutdown), music_box);

	int status = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref(app);
	return status;
}








