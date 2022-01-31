#include "music_box.h"

int main(int argc, char *argv[]) {
	Widgets *app_data = WIDGETS(malloc(sizeof(Widgets)));
	if (app_data == NULL) {printf("Runtime error: failed to initialize app data\n"); return 1;}

	GtkApplication *app = gtk_application_new("com.github.jason44", G_APPLICATION_FLAGS_NONE);
		g_signal_connect(app, "startup", G_CALLBACK(startup), app_data);
		g_signal_connect(app, "activate", G_CALLBACK(activate), app_data);
		g_signal_connect(app, "shutdown", G_CALLBACK(shutdown), app_data);

	app_data->app = app;

	int status = g_application_run(G_APPLICATION(app), argc, argv);

	free(app_data);
	g_object_unref(app);
	return status;
}








