/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file creature_control.c
 *     CreatureControl structure support functions.
 * @par Purpose:
 *     Functions to use CreatureControl for controlling creatures.
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     23 Apr 2009 - 16 May 2009
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "creature_control.h"
#include "globals.h"

#include "bflib_sound.h"
#include "keeperfx.h"
#include "config_creature.h"
#include "frontend.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
DLLIMPORT struct Thing *_DK_create_and_control_creature_as_controller(struct PlayerInfo *player, long a2, struct Coord3d *pos);
/******************************************************************************/
struct CreatureSounds creature_sounds[] = {
{  {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, },
{ {   1, 4}, { 609, 3}, { 607, 1}, { 608, 1}, { 609, 3}, { 612, 2}, { 614, 1}, { 615, 1}, { 616, 3}, { 619, 1}, { 604, 3}, },
{ {   1, 4}, { 626, 3}, { 624, 1}, { 625, 1}, { 626, 3}, { 629, 2}, { 631, 1}, { 632, 1}, { 633, 3}, { 636, 1}, { 621, 3}, },
{ {   1, 4}, { 643, 3}, { 641, 1}, { 642, 1}, { 643, 3}, { 646, 2}, { 648, 1}, { 649, 1}, { 650, 3}, { 653, 1}, { 638, 3}, },
{ {   9, 4}, { 660, 3}, { 658, 1}, { 659, 1}, { 660, 3}, { 663, 2}, { 665, 1}, { 666, 1}, { 667, 3}, { 670, 1}, { 655, 3}, },
{ {   1, 4}, { 728, 3}, { 726, 1}, { 727, 1}, { 728, 3}, { 731, 2}, { 733, 1}, { 734, 1}, { 735, 3}, { 738, 1}, { 723, 3}, },
{ {   5, 4}, { 694, 3}, { 692, 1}, { 693, 1}, { 694, 3}, { 697, 2}, { 699, 1}, { 700, 1}, { 701, 3}, { 704, 1}, { 689, 3}, },
{ {   5, 4}, { 711, 3}, { 709, 1}, { 710, 1}, { 711, 3}, { 714, 2}, { 716, 1}, { 717, 1}, { 718, 3}, { 721, 1}, { 706, 3}, },
{ {   1, 4}, { 677, 3}, { 675, 1}, { 676, 1}, { 677, 3}, { 680, 2}, { 682, 1}, { 683, 1}, { 684, 3}, { 687, 1}, { 672, 3}, },
{ {  13, 4}, { 745, 3}, { 743, 1}, { 744, 1}, { 745, 3}, { 748, 2}, { 750, 1}, { 751, 1}, { 752, 3}, { 755, 1}, { 740, 3}, },
{ {  17, 4}, { 762, 3}, { 760, 1}, { 761, 1}, { 762, 3}, { 765, 2}, { 767, 1}, { 768, 1}, { 769, 3}, { 772, 1}, { 757, 3}, },
{ {  13, 4}, { 779, 3}, { 777, 1}, { 778, 1}, { 779, 3}, { 782, 2}, { 784, 1}, { 785, 1}, { 786, 3}, { 789, 1}, { 774, 3}, },
{ {   1, 4}, { 796, 3}, { 794, 1}, { 795, 1}, { 796, 3}, { 799, 2}, { 801, 1}, { 802, 1}, { 803, 3}, { 806, 1}, { 791, 3}, },
{ {   5, 4}, { 813, 3}, { 811, 1}, { 812, 1}, { 813, 3}, { 816, 2}, { 818, 1}, { 819, 1}, { 820, 3}, { 823, 1}, { 808, 3}, },
{ {   1, 4}, { 337, 3}, { 335, 1}, { 336, 1}, { 337, 3}, { 340, 2}, { 342, 1}, { 343, 1}, { 344, 3}, { 347, 1}, { 332, 3}, },
{ {   1, 4}, { 354, 3}, { 352, 1}, { 353, 1}, { 354, 3}, { 357, 2}, { 359, 1}, { 360, 1}, { 361, 3}, { 364, 1}, { 349, 3}, },
{ {   9, 4}, { 371, 3}, { 369, 1}, { 370, 1}, { 371, 3}, { 374, 2}, { 376, 1}, { 377, 1}, { 378, 3}, { 381, 1}, { 366, 3}, },
{ {  17, 4}, { 388, 3}, { 386, 1}, { 387, 1}, { 388, 3}, { 391, 2}, { 393, 1}, { 394, 1}, { 395, 3}, { 398, 1}, { 383, 3}, },
{ {   9, 4}, { 405, 3}, { 403, 1}, { 404, 1}, { 405, 3}, { 408, 2}, { 410, 1}, { 411, 1}, { 412, 3}, { 415, 1}, { 400, 3}, },
{ {   9, 4}, { 422, 3}, { 420, 1}, { 421, 1}, { 422, 3}, { 425, 2}, { 427, 1}, { 428, 1}, { 429, 3}, { 432, 1}, { 417, 3}, },
{ {  13, 4}, { 439, 3}, { 437, 1}, { 438, 1}, { 439, 3}, { 442, 2}, { 444, 1}, { 445, 1}, { 446, 3}, { 449, 1}, { 434, 3}, },
{ {   1, 4}, { 456, 3}, { 454, 1}, { 455, 1}, { 456, 3}, { 459, 2}, { 461, 1}, { 462, 1}, { 463, 3}, { 466, 1}, { 451, 3}, },
{ {  17, 4}, { 473, 3}, { 471, 1}, { 472, 1}, { 473, 3}, { 476, 2}, { 478, 1}, { 479, 1}, { 480, 3}, { 483, 1}, { 468, 3}, },
{ {   9, 4}, { 490, 3}, { 488, 1}, { 489, 1}, { 490, 3}, { 493, 2}, { 495, 1}, { 496, 1}, { 497, 3}, { 500, 1}, { 485, 3}, },
{ {   9, 4}, { 507, 3}, { 505, 1}, { 506, 1}, { 507, 3}, { 510, 2}, { 512, 1}, { 513, 1}, { 514, 3}, { 517, 1}, { 502, 3}, },
{ {   1, 4}, { 524, 3}, { 522, 1}, { 523, 1}, { 524, 3}, { 527, 2}, { 529, 1}, { 530, 1}, { 531, 3}, { 534, 1}, { 519, 3}, },
{ {   9, 4}, { 541, 3}, { 539, 1}, { 540, 1}, { 541, 3}, { 544, 2}, { 546, 1}, { 547, 1}, { 548, 3}, { 551, 1}, { 536, 3}, },
{ {   9, 4}, { 558, 3}, { 556, 1}, { 557, 1}, { 558, 3}, { 561, 2}, { 563, 1}, { 564, 1}, { 565, 3}, { 568, 1}, { 553, 3}, },
{ {   0, 0}, { 575, 3}, { 573, 1}, { 574, 1}, { 575, 3}, { 578, 2}, { 580, 1}, { 581, 1}, { 582, 3}, { 585, 1}, { 570, 3}, },
{ {   9, 4}, { 592, 3}, { 590, 1}, { 591, 1}, { 592, 3}, { 595, 2}, { 597, 1}, { 598, 1}, { 599, 3}, { 602, 1}, { 587, 3}, },
{ {   9, 4}, { 371, 3}, { 369, 1}, { 370, 1}, { 371, 3}, { 374, 2}, { 376, 1}, { 377, 1}, { 378, 3}, { 381, 1}, { 366, 3}, },
{ {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, {   0, 0}, },
};
/******************************************************************************/
/*
 * Returns CreatureControl of given index.
 */
struct CreatureControl *creature_control_get(long cctrl_idx)
{
  if ((cctrl_idx < 1) || (cctrl_idx > CREATURES_COUNT))
    return game.persons.cctrl_lookup[0];
  return game.persons.cctrl_lookup[cctrl_idx];
}

/*
 * Returns CreatureControl assigned to given thing.
 * Thing must be a creature.
 */
struct CreatureControl *creature_control_get_from_thing(struct Thing *thing)
{
  if ((thing->field_64 < 1) || (thing->field_64 > CREATURES_COUNT))
    return game.persons.cctrl_lookup[0];
  return game.persons.cctrl_lookup[thing->field_64];
}

/*
 * Returns if given CreatureControl pointer is incorrect.
 */
TbBool creature_control_invalid(struct CreatureControl *cctrl)
{
  return (cctrl <= game.persons.cctrl_lookup[0]) || (cctrl == NULL);
}

struct Thing *create_and_control_creature_as_controller(struct PlayerInfo *player, long kind, struct Coord3d *pos)
{
  struct CreatureStats *crstat;
  struct CreatureControl *cctrl;
  struct Dungeon *dungeon;
  struct Thing *thing;
  struct Camera *cam;
  struct InitLight ilght;
  SYNCDBG(6,"Starting");
  //return _DK_create_and_control_creature_as_controller(player, a2, pos);
  thing = create_creature(pos, kind, player->field_2B);
  if (thing_is_invalid(thing))
    return NULL;
  dungeon = &(game.dungeon[thing->owner%DUNGEONS_COUNT]);
  dungeon->field_919--;
  dungeon->field_91A[thing->model]--;
  if (is_my_player(player))
  {
    toggle_status_menu(0);
    turn_off_roaming_menus();
  }
  cam = player->acamera;
  player->field_2F = thing->index;
  player->field_31 = thing->field_9;
  player->field_4B5 = cam->field_6;
  thing->field_0 |= 0x20;
  thing->field_4F |= 0x01;
  cctrl = creature_control_get_from_thing(thing);
  cctrl->field_2 |= 0x02;
  cctrl->max_speed = calculate_correct_creature_maxspeed(thing);
  set_player_mode(player, 2);
  set_start_state(thing);
  // Preparing light object
  ilght.mappos.x.val = thing->mappos.x.val;
  ilght.mappos.y.val = thing->mappos.y.val;
  ilght.mappos.z.val = thing->mappos.z.val;
  ilght.field_2 = 36;
  ilght.field_3 = 1;
  ilght.field_11 = 1;
  ilght.field_0 = 2560;
  thing->field_62 = light_create_light(&ilght);
  if (thing->field_62 != 0)
  {
    light_set_light_never_cache(thing->field_62);
  } else
  {
    ERRORLOG("Cannot allocate light to new hero");
  }
  if (is_my_player_number(thing->owner))
  {
    if (thing->class_id == TCls_Creature)
    {
      crstat = creature_stats_get_from_thing(thing);
      setup_eye_lens(crstat->eye_effect);
    }
  }
  return thing;
}

TbBool disband_creatures_group(struct Thing *thing)
{
  struct CreatureControl *cctrl;
  struct Thing *ntng;
  struct Thing *ctng;
  long i,k;
  cctrl = creature_control_get_from_thing(thing);
  if ((cctrl->field_7A & 0xFFF) == 0)
    return true;
  ctng = thing;
  k = 0;
  while (cctrl->field_76 > 0)
  {
    ctng = thing_get(cctrl->field_76);
    cctrl = creature_control_get_from_thing(ctng);
    k++;
    if (k > CREATURES_COUNT)
    {
      ERRORLOG("Infinite loop detected when sweeping creatures group");
      break;
    }
  }
  // Disband the group, removing creatures from end
  k = 0;
  while (ctng != NULL)
  {
    cctrl = creature_control_get_from_thing(ctng);
    ntng = thing_get(cctrl->field_78);
    if (!thing_is_invalid(ntng))
    {
      remove_creature_from_group(ctng);
      ctng = ntng;
    } else
    {
      ctng = NULL;
    }
    k++;
    if (k > CREATURES_COUNT)
    {
      ERRORLOG("Infinite loop detected when sweeping creatures group");
      return false;
    }
  }
  return true;
}

struct CreatureSound *get_creature_sound(struct Thing *thing, long snd_idx)
{
  switch (snd_idx)
  {
    case 1:
      return &creature_sounds[thing->model].snd05;
    case 2:
      return &creature_sounds[thing->model].snd02;
    case 3:
      return &creature_sounds[thing->model].snd03;
    case 4:
      return &creature_sounds[thing->model].snd04;
    case 5:
      return &creature_sounds[thing->model].snd07;
    case 6:
      return &creature_sounds[thing->model].snd08;
    case 7:
      return &creature_sounds[thing->model].snd09;
    case 8:
      return &creature_sounds[thing->model].snd10;
    case 9:
      return &creature_sounds[thing->model].snd06;
    case 10:
      return &creature_sounds[thing->model].snd01;
    case 11:
      return &creature_sounds[thing->model].snd11;
    default:
      return NULL;
  }
}

TbBool playing_creature_sound(struct Thing *thing, long snd_idx)
{
  struct CreatureSound *crsound;
  long i;
  crsound = get_creature_sound(thing, snd_idx);
  if (crsound == NULL)
    return false;
  for (i=0; i < crsound->count; i++)
  {
    if (S3DEmitterIsPlayingSample(thing->field_66, crsound->index+i, 0))
      return true;
  }
  return false;
}

void play_creature_sound(struct Thing *thing, long snd_idx, long a3, long a4)
{
  struct CreatureSound *crsound;
  long i;
  SYNCDBG(8,"Starting");
  if (playing_creature_sound(thing, snd_idx))
    return;
  crsound = get_creature_sound(thing, snd_idx);
  if (crsound == NULL)
  {
    //SYNCLOG("No sample %d for creature %d",snd_idx,thing->model);
    return;
  }
  i = seed_check_random(crsound->count, &game.rand_14BB4E, __func__, 5634);
  //SYNCLOG("Playing sample %d (index %d) for creature %d",snd_idx,crsound->index+i,thing->model);
  if ( a4 )
    thing_play_sample(thing, crsound->index+i, 100, 0, 3, 8, a3, 256);
  else
    thing_play_sample(thing, crsound->index+i, 100, 0, 3, 0, a3, 256);
}

/******************************************************************************/
#ifdef __cplusplus
}
#endif