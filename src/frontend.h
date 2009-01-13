/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file frontend.h
 *     Header file for frontend.c.
 * @par Purpose:
 *     Functions to display and maintain the game menu.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     10 Nov 2008 - 22 Dec 2008
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef FRONTEND_H
#define FRONTEND_H

#include "globals.h"

struct GuiMenu;
struct GuiButton;

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
DLLIMPORT struct GuiButtonInit _DK_main_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_room_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_spell_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_spell_lost_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_trap_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_creature_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_event_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_options_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_query_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_instance_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_quit_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_load_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_save_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_video_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_sound_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_error_box_buttons[];
DLLIMPORT struct GuiButtonInit _DK_text_info_buttons[];
DLLIMPORT struct GuiButtonInit _DK_pause_buttons[];
DLLIMPORT struct GuiButtonInit _DK_hold_audience_buttons[];
DLLIMPORT struct GuiButtonInit _DK_armageddon_buttons[];
DLLIMPORT struct GuiButtonInit _DK_dungeon_special_buttons[];
DLLIMPORT struct GuiButtonInit _DK_battle_buttons[];
DLLIMPORT struct GuiButtonInit _DK_resurrect_creature_buttons[];
DLLIMPORT struct GuiButtonInit _DK_transfer_creature_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_main_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_load_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_net_service_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_net_session_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_net_start_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_net_modem_buttons[37];
DLLIMPORT struct GuiButtonInit _DK_frontend_net_serial_buttons[22];
DLLIMPORT struct GuiButtonInit _DK_frontend_statistics_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_high_score_score_buttons[];
DLLIMPORT struct GuiButtonInit _DK_creature_query_buttons1[];
DLLIMPORT struct GuiButtonInit _DK_creature_query_buttons2[];
DLLIMPORT struct GuiButtonInit _DK_creature_query_buttons3[];
DLLIMPORT struct GuiButtonInit _DK_frontend_define_keys_buttons[];
DLLIMPORT struct GuiButtonInit _DK_autopilot_menu_buttons[];
DLLIMPORT struct GuiButtonInit _DK_frontend_option_buttons[];
DLLIMPORT struct GuiMenu _DK_main_menu;
DLLIMPORT struct GuiMenu _DK_room_menu;
DLLIMPORT struct GuiMenu _DK_spell_menu;
DLLIMPORT struct GuiMenu _DK_spell_lost_menu;
DLLIMPORT struct GuiMenu _DK_trap_menu;
DLLIMPORT struct GuiMenu _DK_creature_menu;
DLLIMPORT struct GuiMenu _DK_event_menu;
DLLIMPORT struct GuiMenu _DK_options_menu;
DLLIMPORT struct GuiMenu _DK_instance_menu;
DLLIMPORT struct GuiMenu _DK_query_menu;
DLLIMPORT struct GuiMenu _DK_quit_menu;
DLLIMPORT struct GuiMenu _DK_load_menu;
DLLIMPORT struct GuiMenu _DK_save_menu;
DLLIMPORT struct GuiMenu _DK_video_menu;
DLLIMPORT struct GuiMenu _DK_sound_menu;
DLLIMPORT struct GuiMenu _DK_error_box;
DLLIMPORT struct GuiMenu _DK_text_info_menu;
DLLIMPORT struct GuiMenu _DK_hold_audience_menu;
DLLIMPORT struct GuiMenu _DK_dungeon_special_menu;
DLLIMPORT struct GuiMenu _DK_resurrect_creature_menu;
DLLIMPORT struct GuiMenu _DK_transfer_creature_menu;
DLLIMPORT struct GuiMenu _DK_armageddon_menu;
DLLIMPORT struct GuiMenu _DK_frontend_main_menu;
DLLIMPORT struct GuiMenu _DK_frontend_load_menu;
DLLIMPORT struct GuiMenu _DK_frontend_net_service_menu;
DLLIMPORT struct GuiMenu _DK_frontend_net_session_menu;
DLLIMPORT struct GuiMenu _DK_frontend_net_start_menu;
DLLIMPORT struct GuiMenu _DK_frontend_net_modem_menu;
DLLIMPORT struct GuiMenu _DK_frontend_net_serial_menu;
DLLIMPORT struct GuiMenu _DK_frontend_statistics_menu;
DLLIMPORT struct GuiMenu _DK_frontend_high_score_table_menu;
DLLIMPORT struct GuiMenu _DK_creature_query_menu1;
DLLIMPORT struct GuiMenu _DK_creature_query_menu2;
DLLIMPORT struct GuiMenu _DK_creature_query_menu3;
DLLIMPORT struct GuiMenu _DK_battle_menu;
DLLIMPORT struct GuiMenu _DK_frontend_define_keys_menu;
DLLIMPORT struct GuiMenu _DK_autopilot_menu;
DLLIMPORT struct GuiMenu _DK_frontend_option_menu;
DLLIMPORT struct GuiMenu *_DK_menu_list[40];

DLLIMPORT char _DK_info_tag;
DLLIMPORT char _DK_room_tag;
DLLIMPORT char _DK_spell_tag;
DLLIMPORT char _DK_trap_tag;
DLLIMPORT char _DK_creature_tag;
DLLIMPORT char _DK_input_string[8][16];
#define input_string _DK_input_string
DLLIMPORT extern struct GuiButton *_DK_input_button;
#define input_button _DK_input_button
DLLIMPORT extern struct ToolTipBox _DK_tool_tip_box;
#define tool_tip_box _DK_tool_tip_box
DLLIMPORT char _DK_error_box_message[256];
#define error_box_message _DK_error_box_message
DLLIMPORT long _DK_net_service_scroll_offset;
#define net_service_scroll_offset _DK_net_service_scroll_offset
DLLIMPORT long _DK_net_number_of_services;
#define net_number_of_services _DK_net_number_of_services
DLLIMPORT extern struct TbSprite *_DK_frontend_font[4];
#define frontend_font _DK_frontend_font

/******************************************************************************/
// Variables - no linger imported
extern struct GuiMenu main_menu;
extern struct GuiMenu room_menu;
extern struct GuiMenu spell_menu;
extern struct GuiMenu spell_lost_menu;
extern struct GuiMenu trap_menu;
extern struct GuiMenu creature_menu;
extern struct GuiMenu event_menu;
extern struct GuiMenu options_menu;
extern struct GuiMenu instance_menu;
extern struct GuiMenu query_menu;
extern struct GuiMenu quit_menu;
extern struct GuiMenu load_menu;
extern struct GuiMenu save_menu;
extern struct GuiMenu video_menu;
extern struct GuiMenu sound_menu;
extern struct GuiMenu error_box;
extern struct GuiMenu text_info_menu;
extern struct GuiMenu hold_audience_menu;
extern struct GuiMenu dungeon_special_menu;
extern struct GuiMenu resurrect_creature_menu;
extern struct GuiMenu transfer_creature_menu;
extern struct GuiMenu armageddon_menu;
extern struct GuiMenu frontend_main_menu;
extern struct GuiMenu frontend_load_menu;
extern struct GuiMenu frontend_net_service_menu;
extern struct GuiMenu frontend_net_session_menu;
extern struct GuiMenu frontend_net_start_menu;
extern struct GuiMenu frontend_net_modem_menu;
extern struct GuiMenu frontend_net_serial_menu;
extern struct GuiMenu frontend_statistics_menu;
extern struct GuiMenu frontend_high_score_table_menu;
extern struct GuiMenu creature_query_menu1;
extern struct GuiMenu creature_query_menu2;
extern struct GuiMenu creature_query_menu3;
extern struct GuiMenu battle_menu;
extern struct GuiMenu frontend_define_keys_menu;
extern struct GuiMenu autopilot_menu;
extern struct GuiMenu frontend_option_menu;
extern struct FrontEndButtonData frontend_button_info[];

extern struct GuiMenu *menu_list[40];

/******************************************************************************/

DLLIMPORT void _DK_gui_activity_background(struct GuiMenu *gmnu);
DLLIMPORT void _DK_gui_pretty_background(struct GuiMenu *gmnu);
DLLIMPORT void _DK_frontend_copy_background(struct GuiMenu *gmnu);
DLLIMPORT void _DK_gui_round_glass_background(struct GuiMenu *gmnu);
DLLIMPORT void _DK_gui_creature_query_background1(struct GuiMenu *gmnu);
DLLIMPORT void _DK_gui_creature_query_background2(struct GuiMenu *gmnu);
DLLIMPORT void _DK_reset_scroll_window(struct GuiMenu *gmnu);
DLLIMPORT void _DK_init_load_menu(struct GuiMenu *gmnu);
DLLIMPORT void _DK_init_save_menu(struct GuiMenu *gmnu);
DLLIMPORT void _DK_init_video_menu(struct GuiMenu *gmnu);
DLLIMPORT void _DK_init_audio_menu(struct GuiMenu *gmnu);
DLLIMPORT void _DK_frontend_init_options_menu(struct GuiMenu *gmnu);
DLLIMPORT void _DK_frontend_draw_large_menu_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_scroll_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_scroll_box(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_slider_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_services_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_text(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_service_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_large_menu_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_change_state(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_over_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_set_player_name(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_text_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_enter_text(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_sessions_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_session_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_session_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_players_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_net_session_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_join(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_create(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_return_to_main_menu(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_small_menu_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_join_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_net_start_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_select_alliance(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_grid(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_maintain_alliance(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_bottom_scroll_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_toggle_computer_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_computer_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_messages_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_current_message(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_messages(struct GuiButton *gbtn);
DLLIMPORT void _DK_set_packet_start(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_start_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_return_to_session_menu(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_small_scroll_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_small_scroll_box(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_select_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_select_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_text_cont_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_init(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_hangup(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_dial(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_phone_number(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_modem_start(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_modem_start_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_answer(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_serial_start(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_serial_start_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_zoom_in(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_zoom_out(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_map(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_new_normal_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_turn_on_autopilot(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_turn_on_autopilot(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_autopilot_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_menu_mode(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_draw_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_menu_tab_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_open_event(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_kill_event(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_event_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_event_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_choose_room(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_room(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_over_room_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_room_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_room(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_new_null_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_new_no_anim_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_big_room(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_remove_area_for_rooms(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_big_room_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_choose_spell(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_spell(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_spell_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_spell(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_choose_special_spell(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_big_spell_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_big_spell(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_choose_trap(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_trap(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_over_trap_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_trap(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_trap_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_door(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_door(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_over_door_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_remove_area_for_traps(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_big_trap_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_big_trap(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_no_anim_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_loadsave(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_normal_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_new_normal_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_tend_to(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_flash_cycle_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_prison_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_flash_cycle_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_query(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_payday_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_research_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_workshop_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_player_creature_info(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_room_and_creature_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_player_room_info(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_toggle_ally(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_ally(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_quit_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_ally(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_save_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_shadows(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_view_distance_level(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_rotate_mode(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_cluedo_mode(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_gamma_correction(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_sound_volume(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_music_volume(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_video_cluedo_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_slider(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_smiley_anger_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_experience_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_instance_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_instance(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_stat_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_define_key_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_define_key_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_define_key(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_set_autopilot(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_icon(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_slider(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_set_mouse_sensitivity(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_small_slider(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_invert_mouse(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_invert_mouse(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontstats_draw_main_stats(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontstats_draw_scrolling_stats(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontstats_leave(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_vlarge_menu_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_high_score_table(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_quit_high_score_table(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_maintain_high_score_ok_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_load_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_load_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_draw_load_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_scroll_window(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_event(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_zoom_to_event(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_close_objective(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_text_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_text_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_scroll_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_scroll_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_text_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_choose_hold_audience(struct GuiButton *gbtn);
DLLIMPORT void _DK_choose_armageddon(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_games_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_draw_load_game_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_start_new_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_load_continue_game(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_continue_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_main_menu_load_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_main_menu_netservice_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontend_main_menu_highscores_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_previous_battle(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_next_battle(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_get_creature_in_battle(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_person_in_battle(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_setup_friend_over(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_friendly_battlers(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_setup_enemy_over(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_enemy_battlers(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_null(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_resurrect_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_resurrect_creature_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_draw_resurrect_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_resurrect_creature_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_resurrect_creature_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_resurrect_creature_scroll(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_transfer_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_draw_transfer_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_transfer_creature_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_transfer_creature_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_select_transfer_creature_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_transfer_creature_scroll(struct GuiButton *gbtn);

DLLIMPORT void _DK_spell_lost_first_person(struct GuiButton *gbtn);
DLLIMPORT void _DK_pick_up_next_wanderer(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_wanderer(struct GuiButton *gbtn);
DLLIMPORT void _DK_pick_up_next_worker(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_worker(struct GuiButton *gbtn);
DLLIMPORT void _DK_pick_up_next_fighter(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_fighter(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_activity_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_activity_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_activity_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_scroll_activity_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_activity_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_activity_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_activity_pic(struct GuiButton *gbtn);
DLLIMPORT void _DK_pick_up_next_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_creature(struct GuiButton *gbtn);
DLLIMPORT void _DK_pick_up_creature_doing_activity(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_go_to_next_creature_activity(struct GuiButton *gbtn);
DLLIMPORT void _DK_gui_area_anger_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_maintain_activity_row(struct GuiButton *gbtn);

DLLIMPORT char _DK_get_button_area_input(struct GuiButton *gbtn, int);
DLLIMPORT void _DK_gui_area_text(struct GuiButton *gbtn);
DLLIMPORT void _DK_setup_gui_tooltip(struct GuiButton *gbtn);

/******************************************************************************/
// Reworked functions

void gui_activity_background(struct GuiMenu *gmnu);
void gui_pretty_background(struct GuiMenu *gmnu);
void frontend_copy_background(struct GuiMenu *gmnu);
void gui_round_glass_background(struct GuiMenu *gmnu);
void gui_creature_query_background1(struct GuiMenu *gmnu);
void gui_creature_query_background2(struct GuiMenu *gmnu);
void reset_scroll_window(struct GuiMenu *gmnu);
void init_load_menu(struct GuiMenu *gmnu);
void init_save_menu(struct GuiMenu *gmnu);
void init_video_menu(struct GuiMenu *gmnu);
void init_audio_menu(struct GuiMenu *gmnu);
void frontend_init_options_menu(struct GuiMenu *gmnu);
void frontend_load_game_maintain(struct GuiButton *gbtn);
void frontnet_service_select(struct GuiButton *gbtn);
void frontnet_service_up_maintain(struct GuiButton *gbtn);
void frontnet_service_down_maintain(struct GuiButton *gbtn);
void frontnet_service_up(struct GuiButton *gbtn);
void frontnet_service_down(struct GuiButton *gbtn);
void frontnet_service_maintain(struct GuiButton *gbtn);
void frontnet_draw_service_button(struct GuiButton *gbtn);

int frontend_set_state(long nstate);
int get_startup_menu_state(void);
void frontend_input(void);
void turn_off_menu(short mnu_idx);
void frontend_update(short *finish_menu);
short frontend_draw(void);

/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif