#include "music_box.h"

void activate(GtkApplication *app, gpointer app_data) {
	MusicBox *music_box = MUSIC_BOX(app_data);

    // **** WINDOW **** // 
	music_box->window = gtk_application_window_new(app);
	    gtk_window_set_title(GTK_WINDOW(music_box->window), "Musicbox");
	    gtk_window_set_default_size(GTK_WINDOW(music_box->window), 870, 550);

    // **** HEADERBAR **** //
	music_box->headerbar.bar = gtk_header_bar_new();
		gtk_window_set_titlebar(GTK_WINDOW(music_box->window), music_box->headerbar.bar);
    // ** HAMBURGER MENU ** //
	music_box->headerbar.burger_menu = g_menu_new();
    	music_box->headerbar.settings_opt = g_menu_item_new("Settings", "app.settings");
        music_box->headerbar.help_opt = g_menu_item_new("Help", "app.help");
        g_menu_append_item(music_box->headerbar.burger_menu, music_box->headerbar.settings_opt);
        g_menu_append_item(music_box->headerbar.burger_menu, music_box->headerbar.help_opt);

	// ** BURGER BUTTON ** //
	music_box->headerbar.burger_menu_button = gtk_menu_button_new();
		gtk_menu_button_set_icon_name(GTK_MENU_BUTTON(music_box->headerbar.burger_menu_button), "open-menu");
        gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(music_box->headerbar.burger_menu_button), G_MENU_MODEL(music_box->headerbar.burger_menu));
        gtk_menu_button_set_has_frame(GTK_MENU_BUTTON(music_box->headerbar.burger_menu_button), true);

		gtk_header_bar_pack_end(GTK_HEADER_BAR(music_box->headerbar.bar), music_box->headerbar.burger_menu_button);
    
		g_object_unref(music_box->headerbar.settings_opt);
    	g_object_unref(music_box->headerbar.help_opt);
		g_object_unref(music_box->headerbar.burger_menu);

	// ** SHOW FLAP BUTTON ** //
	music_box->headerbar.flap_button = gtk_button_new_from_icon_name("pan-start");
		gtk_header_bar_pack_start(GTK_HEADER_BAR(music_box->headerbar.bar), music_box->headerbar.flap_button);
		g_signal_connect(music_box->headerbar.flap_button, "clicked", G_CALLBACK(flap_button_clicked), app_data);

	printf("SOMEHWRESIDEFL\n");
    // **** SIDE PANEL FLAP **** //
	music_box->flap = adw_flap_new();
		adw_flap_set_fold_policy(ADW_FLAP(music_box->flap), ADW_FLAP_FOLD_POLICY_NEVER); // Above content
	music_box->content_flap = adw_flap_new();
		adw_flap_set_flap_position(ADW_FLAP(music_box->content_flap), GTK_PACK_END);
		adw_flap_set_reveal_flap(ADW_FLAP(music_box->content_flap), false);
		adw_flap_set_fold_threshold_policy(ADW_FLAP(music_box->content_flap), ADW_FOLD_THRESHOLD_POLICY_NATURAL);
		adw_flap_set_fold_policy(ADW_FLAP(music_box->content_flap), ADW_FLAP_FOLD_POLICY_NEVER);
	music_box->side_panel_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);

	adw_flap_set_content(ADW_FLAP(music_box->flap), music_box->content_flap);
	adw_flap_set_flap(ADW_FLAP(music_box->flap), music_box->side_panel_box);
	gtk_window_set_child(GTK_WINDOW(music_box->window), music_box->flap);
	// ** SUDE PANEL BOX ** //
	for (int i = 0; i < 14; i++) {
	GtkWidget *button11 = gtk_button_new_with_label("TEST GOOD BAD NEXT");
	gtk_box_append(GTK_BOX(music_box->side_panel_box), button11);
	}
	printf("somehweresidleflaom\n");
	// **** CONTENT & SETTINGS FLAP **** //
	music_box->content_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	music_box->scrollable_settings = gtk_scrolled_window_new();
		gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(music_box->scrollable_settings), gtk_widget_get_height(music_box->window));
	music_box->settings_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		gtk_widget_set_hexpand(music_box->settings_box, true);
		gtk_widget_set_vexpand(music_box->settings_box, true);
		gtk_widget_set_margin_top(music_box->settings_box, 15);
		gtk_widget_set_margin_bottom(music_box->settings_box, 15);
		gtk_widget_set_margin_start(music_box->settings_box, 20);
		gtk_widget_set_margin_end(music_box->settings_box, 20);

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(music_box->scrollable_settings), music_box->settings_box);

	adw_flap_set_content(ADW_FLAP(music_box->content_flap), music_box->content_box);
	adw_flap_set_flap(ADW_FLAP(music_box->content_flap), music_box->scrollable_settings);

	printf("CONTENTBOXSOMEHTWE\n");
	// ** CONTENT BOX ** //
	GtkWidget *content_button = gtk_button_new_with_label("TESTEST");
		gtk_actionable_set_action_name(GTK_ACTIONABLE(content_button), "app.settings");
		gtk_box_append(GTK_BOX(music_box->content_box), content_button);

	printf("SETTINGINSBOXWSOM\n");
	// ** SETTINGS BOX ** //
	music_box->playlist_clamp = adw_clamp_new();
		adw_clamp_set_maximum_size(ADW_CLAMP(music_box->playlist_clamp), 500);
	music_box->settings_group = adw_preferences_group_new();
		adw_preferences_group_set_title(ADW_PREFERENCES_GROUP(music_box->settings_group), "Playlist");
	music_box->playlist_row = adw_expander_row_new();
	for (int i=0; i < 15; i++) {
		GtkWidget *playtemp = adw_action_row_new();
		adw_preferences_group_add(ADW_PREFERENCES_GROUP(music_box->settings_group), playtemp);
	}
	adw_preferences_group_add(ADW_PREFERENCES_GROUP(music_box->settings_group), music_box->playlist_row);
	
	adw_clamp_set_child(ADW_CLAMP(music_box->playlist_clamp), music_box->settings_group);

	gtk_box_append(GTK_BOX(music_box->settings_box), music_box->playlist_clamp);

	printf("dfsgserogjo;irg\n");

	//gtk_native_dialog_show(GTK_NATIVE_DIALOG(MUSIC_BOX(app_data)->file_chooser));
	gtk_widget_show(music_box->window);
}

void shutdown(GtkApplication *app, gpointer app_data) {
	g_object_unref(MUSIC_BOX(app_data)->file_chooser);
}