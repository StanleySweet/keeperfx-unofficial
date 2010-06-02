/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file creature_graphics.c
 *     Creature graphics support functions.
 * @par Purpose:
 *     Functions to maintain and use creature graphics sprites.
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     11 Mar 2010 - 23 May 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "creature_graphics.h"

#include "globals.h"
#include "bflib_basics.h"

#include "thing_creature.h"
#include "config_creature.h"
#include "creature_instances.h"
#include "engine_lenses.h"
#include "keeperfx.hpp"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
unsigned short creature_graphics[][22] = {
  {   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,
      0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,},
  { 426, 424, 424, 428,   0,   0,   0,  0, 430, 436, 442,
    438, 440, 444,  52, 432, 434, 946, 20, 164, 178,  20,},
  { 404, 402, 402, 406,   0,   0,   0,  0, 408, 414, 420,
    416, 418, 422,  62, 410, 412, 946, 21, 165, 180,  21,},
  { 382, 380, 380, 384,   0,   0,   0,  0, 386, 392, 398,
    394, 396, 400,  54, 388, 390, 946, 15, 168, 182,  24,},
  { 206, 204, 204, 208,   0,   0,   0,  0, 210, 216, 222,
    218, 220, 224,  48, 212, 214, 946, 15, 172, 184,  28,},
  { 360, 358, 358, 362,   0,   0,   0,  0, 364, 370, 376,
    372, 374, 378,  48, 366, 368, 946, 22, 166, 186,  22,},
  { 228, 226, 226, 230,   0,   0,   0,  0, 232, 238, 244,
    240, 242, 246,  60, 234, 236, 946, 18, 162, 188,  18,},
  { 162, 160, 160, 164,   0,   0,   0,  0, 166, 172, 178,
    174, 176, 180,  48, 168, 170, 946, 18, 214, 190,  18,},
  { 338, 336, 336, 340,   0,   0,   0,350, 342, 348, 354,
    350, 352, 356,  48, 344, 346, 946, 22, 167, 192,  23,},
  { 316, 314, 314, 318,   0,   0,   0,  0, 320, 326, 332,
    328, 330, 334,  48, 322, 324, 946, 26, 170, 194,  26,},
  { 294, 292, 292, 296,   0,   0,   0,  0, 298, 304, 310,
    306, 308, 312,  48, 300, 302, 946, 15, 169, 196,  25,},
  { 272, 270, 270, 274,   0,   0,   0,  0, 276, 282, 288,
    284, 286, 290,  58, 278, 280, 946, 15, 161, 198,  17,},
  { 250, 248, 248, 252,   0,   0,   0,  0, 254, 260, 266,
    262, 264, 268,  64, 256, 258, 946, 19, 163, 200,  19,},
  {  26,  24,  24,  28,   0,   0,   0,  0,  30,  36,  42,
     38,  40,  44,  48,  32,  34, 946, 15, 171, 202,  27,},
  { 754, 752, 752, 756, 766,   0,   0,  0, 758, 764, 770,
    766, 768, 772,  48, 760, 762, 946,  1, 145, 204,   1,},
  { 732, 730, 730, 734,   0,   0,   0,  0, 736, 742, 748,
    744, 746, 750,  92, 738, 740, 946,  2, 146, 206,   2,},
  { 710, 708, 708, 712,   0,   0,   0,  0, 714, 720, 726,
    722, 724, 728,  90, 716, 718, 946,  3, 147, 208,   3,},
  { 688, 686, 686, 690,   0,   0,   0,  0, 692, 698, 704,
    700, 702, 706,  88, 694, 696, 946,  4, 148, 210,   4,},
  { 666, 664, 664, 668,   0,   0,   0,  0, 670, 676, 682,
    678, 680, 684,  86, 672, 674, 946,  5, 149, 212,   5,},
  { 644, 644, 644, 646,   0,   0,   0,  0, 648, 654, 660,
    656, 658, 662,  84, 650, 652, 946,  6, 150, 214,   6,},
  { 624, 622, 622, 626,   0,   0,   0,  0, 628, 634, 640,
    636, 638, 642,  82, 630, 632, 946,  7, 151, 216,   7,},
  { 602, 600, 600, 604,   0,   0,   0,  0, 606, 612, 618,
    614, 616, 620,  80, 608, 610, 946,  8, 152, 218,   8,},
  { 580, 578, 578, 582,   0,   0,   0,  0, 584, 590, 596,
    592, 594, 598,  78, 586, 588, 946,  9, 153, 220,   9,},
  { 556, 554, 566, 558, 558, 568, 562,564, 560, 574, 576,
    564, 556, 556,  56, 570, 572, 946, 10, 154, 222,  10,},
  { 534, 532, 532, 536,   0,   0,   0,  0, 538, 544, 550,
    546, 548, 552,  76, 540, 542, 946, 11, 155, 224,  11,},
  { 512, 510, 510, 514,   0,   0,   0,  0, 516, 522, 528,
    524, 526, 530,  50, 518, 520, 946, 12, 156, 226,  12,},
  { 490, 488, 488, 492,   0,   0,   0,  0, 494, 500, 506,
    502, 504, 508,  74, 496, 498, 946, 13, 157, 228,  13,},
  {   2,   0,   0,   4,  22,   0,   0,  0,   6,  12,  18,
     14,  16,  20,  48,   8,  10, 946, 15, 159, 230,  15,},
  { 470, 468, 468, 472,   0,   0,   0,  0, 474, 480, 486,
    482, 484, 470,  48, 476, 478, 946, 16, 160, 232,  16,},
  { 448, 446, 446, 450,   0,   0,   0,  0, 452, 458, 464,
    460, 462, 466,  68, 454, 456, 946, 14, 158, 234,  14,},
  { 184, 182, 182, 186,   0,   0,   0,  0, 188, 194, 200,
    196, 198, 202,  66, 190, 192, 946, 19, 173, 496,  29,},
  { 980, 980, 980, 980, 980,   0,   0,  0, 980, 980, 980,
    980, 980, 980, 980, 980, 980, 980,  0,   0,   0,   0,},
};

struct CreaturePickedUpOffset creature_picked_up_offset[] = {
  {  0,   0,  0,  0},
  {  6, 122,  0,  0},
  { 38, 134,  0,  0},
  {  0,  82,  0,  0},
  { -1,  69,  0,  0},
  { 14,  44,  0,  0},
  {  8,  64,  0,  0},
  { 14,  76,  0,  0},
  { 12,  50,  0,  0},
  {  6,  74,  0,  0},
  { 10,  90,  0,  0},
  {  8, 116,  0,  0},
  { 10, 102,  0,  0},
  {  4, 104,  0,  0},
  {  4, 128,  0,  0},
  { -5,  54,  0,  0},
  {  4,  96,  0,  0},
  { 14, 120,  0,  0},
  {  0,  50,  0,  0},
  { 14,  68,  0,  0},
  { -6, 126,  0,  0},
  { -8,  84,  0,  0},
  { -8,  76,  0,  0},
  { -2,  46,  0,  0},
  { 22,  60,  0,  0},
  {  0,  70,  0,  0},
  {  2,  44,  0,  0},
  {-12,  80,  0,  0},
  { -8,  60,  0,  0},
  {  0,  74,  0,  0},
  {  5, 121,  0,  0},
  {  0,   0,  0,  0},
};

/******************************************************************************/
DLLIMPORT struct KeeperSprite *_DK_creature_table;
#define creature_table _DK_creature_table
DLLIMPORT unsigned short _DK_creature_list[CREATURE_FRAMELIST_LENGTH];
#define creature_list _DK_creature_list
/******************************************************************************/
DLLIMPORT void _DK_set_creature_graphic(struct Thing *thing);
/******************************************************************************/
extern struct CreaturePickedUpOffset creature_picked_up_offset[];
/******************************************************************************/
struct CreaturePickedUpOffset *get_creature_picked_up_offset(struct Thing *thing)
{
    int breed;
    breed = thing->model;
    if ((breed < 0) || (breed >= CREATURE_TYPES_COUNT))
        breed = 0;
    return &creature_picked_up_offset[breed];
}

unsigned char keepersprite_frames(unsigned short n)
{
  unsigned long i;
  if (n >= CREATURE_FRAMELIST_LENGTH)
      n = 0;
  i = creature_list[n];
  return creature_table[i].field_9;
}

long get_lifespan_of_animation(long ani, long frameskip)
{
    return (keepersprite_frames(ani) << 8) / frameskip;
}

unsigned long get_creature_breed_graphics(long breed, unsigned short seq_idx)
{
  if (seq_idx > 21)
      seq_idx = 0;
  if ((breed < 0) || (breed >= CREATURE_TYPES_COUNT))
      breed = 0;
  return creature_graphics[breed][seq_idx];
}

void set_creature_breed_graphics(long breed, unsigned short seq_idx, unsigned long val)
{
    if (seq_idx > 21)
        return;
    if ((breed < 0) || (breed >= CREATURE_TYPES_COUNT))
        return;
    creature_graphics[breed][seq_idx] = val;
}

unsigned long get_creature_anim(struct Thing *thing, unsigned short frame)
{
  unsigned long idx;
  idx = get_creature_breed_graphics(thing->model, frame);
  return convert_td_iso(idx);
}

void untint_thing(struct Thing *thing)
{
    thing->field_51 = 0;
    thing->field_4F &= 0xF3;
}

void tint_thing(struct Thing *thing, TbPixel colour, unsigned char nframe)
{
    thing->field_4F ^= (thing->field_4F ^ (nframe << 2)) & 0x0C;
    thing->field_51 = colour;
}

TbBool update_creature_anim(struct Thing *thing, long speed, long seq_idx)
{
    unsigned long i;
    i = get_creature_anim(thing, seq_idx);
    if (i != thing->field_44)
    {
        set_thing_draw(thing, i, speed, -1, -1, 0, 2);
        return true;
    }
    return false;
}

void set_creature_graphic(struct Thing *thing)
{
    struct CreatureControl *cctrl;
    struct CreatureStats *crstat;
    struct InstanceInfo *inst_inf;

    signed int v9;
    signed int v10;
    signed int v11;
    signed int v12;
    signed int v13;
    __int32 v20;
    __int32 v22;
    __int32 v23;
    char v24;
    char v25;
    unsigned char v26;

    //_DK_set_creature_graphic(thing); return;
    cctrl = creature_control_get_from_thing(thing);
    crstat = creature_stats_get_from_thing(thing);

    thing->field_4F &= ~0x01;
    thing->field_4F &= ~0x10;
    thing->field_4F &= ~0x20;
    thing->field_4F &= ~0x40;
    if (((thing->field_0 & 0x20) != 0) && is_my_player_number(thing->owner))
    {
        thing->field_4F |= 0x01;
    } else
    if (creatures[thing->model].field_7)
    {
        thing->field_4F |= 0x10;
        thing->field_4F |= 0x20;
    } else
    if (((cctrl->spell_flags & 0x20) != 0) && (cctrl->field_AF <= 0))
    {
      if (is_my_player_number(thing->owner))
      {
          thing->field_4F &= ~0x10;
          thing->field_4F |= 0x20;
      } else
      {
          thing->field_4F |= 0x01;
      }
    }

    if ((thing->field_50 & 0x01) != 0)
    {
      thing->field_50 &= 0x01;
      goto LABEL_124;
    }
    if ((thing->field_7 == 96) && (cctrl->field_282 >= 0))
    {
      thing->field_4F |= 0x01;
      goto LABEL_124;
    }
    if ((cctrl->field_AD & 0x02) == 0)
    {
        if ( cctrl->field_D2 )
        {
          if (cctrl->field_D2 == 45)
          {
              thing->field_4F &= ~0x30;
          }
          inst_inf = creature_instance_info_get(cctrl->field_D2);
          update_creature_anim(thing, cctrl->field_1CE, inst_inf->graphics_idx);
          goto LABEL_124;
        }
        if ((cctrl->field_B1 != 0) || (thing->health < 0) || ((cctrl->field_AB & 0x02) != 0))
        {
            update_creature_anim(thing, 256, 8);
            goto LABEL_124;
        } else
        if ((cctrl->field_AB & 0x01) != 0)
        {
            update_creature_anim(thing, 256, 0);
            goto LABEL_124;
        } else
        if (thing->field_7 == 66)
        {
            update_creature_anim(thing, 256, 10);
            goto LABEL_124;
        } else
        if ((thing->field_7 == 124) || (thing->field_7 == 125))
        {
            update_creature_anim(thing, 128, 4);
            goto LABEL_124;
        } else
        if (thing->field_7 == 67)
        {
            update_creature_anim(thing, 64, 16);
            thing->field_4F |= 0x40;
            goto LABEL_124;
        } else
        if (thing->field_7 == 26)
        {
            thing->field_4F &= 0xCF;
            update_creature_anim(thing, 128, 12);
            goto LABEL_124;
        } else
        if (cctrl->field_9 == 0)
        {
            update_creature_anim(thing, 256, 0);
            goto LABEL_124;
        } else
        if (thing->field_60 < (signed int)thing->mappos.z.val)
        {
            update_creature_anim(thing, 256, 0);
            goto LABEL_124;
        } else
        if ((cctrl->field_6E > 0) && thing_get(cctrl->field_6E)->field_1 & 0x01 )
        {
            v22 = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
            update_creature_anim(thing, v22, 2);
            goto LABEL_124;
        } else
        if (creatures[thing->model].field_6 != 4)
        {
            v22 = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
            if (update_creature_anim(thing, v22, 1))
            {
                goto LABEL_124;
            }
            if (creatures[thing->model].field_6 != 4)
            {
              thing->field_3E = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
            }
            goto LABEL_124;
        } else
        {
            if (update_creature_anim(thing, 256, 1))
            {
                goto LABEL_124;
            }
            if (creatures[thing->model].field_6 != 4)
            {
              thing->field_3E = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
            }
            goto LABEL_124;
        }
        goto LABEL_124;
    } else
    {
        thing->field_4F &= 0xCFu;
        if ( cctrl->field_9 )
        {
          if ( thing->field_60 >= (signed int)thing->mappos.z.val )
          {
              v11 = convert_td_iso(819);
            if ( thing->field_44 != v11 )
            {
              if ( creatures[thing->model].field_6 != 4 )
              {
                v12 = convert_td_iso(819);
                v26 = 2;
                v25 = 0;
                v24 = -1;
                v23 = -1;
                v22 = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
                v20 = v12;
                set_thing_draw(thing, v20, v22, v23, v24, v25, v26);
                goto LABEL_124;
              }
              v10 = convert_td_iso(819);
              v26 = 2;
              v25 = 0;
              v24 = -1;
              v23 = -1;
              v22 = 256;
              v20 = v10;
              set_thing_draw(thing, v20, v22, v23, v24, v25, v26);
              goto LABEL_124;
            }
            if ( creatures[thing->model].field_6 != 4 )
              thing->field_3E = (((long)cctrl->field_9) << 8) / (crstat->walking_anim_speed+1);
          }
          else
          {
            v9 = convert_td_iso(820);
            if ( thing->field_44 != v9 )
            {
              v10 = convert_td_iso(820);
              v26 = 2;
              v25 = 0;
              v24 = -1;
              v23 = -1;
              v22 = 256;
              set_thing_draw(thing, v10, v22, v23, v24, v25, v26);
              goto LABEL_124;
            }
          }
        }
        else
        {
          v13 = convert_td_iso(820);
          if ( thing->field_44 != v13 )
          {
            v26 = 2;
            v25 = 0;
            v24 = -1;
            v23 = -1;
            v22 = 256;
            set_thing_draw(thing, v13, v22, v23, v24, v25, v26);
            goto LABEL_124;
          }
        }
    }


LABEL_124:
    if ((cctrl->field_AB & 0x02) != 0)
    {
        tint_thing(thing, colours[4][4][15], 1);
    } else
    if (((cctrl->field_3 & 0x01) == 0) && ((cctrl->field_3 & 0x02) == 0))
    {
        untint_thing(thing);
    } else
    if ((game.play_gameturn % 3) == 0)
    {
        untint_thing(thing);
    } else
    {
        switch (thing->owner)
        {
        case 0:
            tint_thing(thing, colours[15][0][0], 1);
            break;
        case 1:
            tint_thing(thing, colours[0][0][15], 1);
            break;
        case 2:
            tint_thing(thing, colours[0][15][0], 1);
            break;
        case 3:
            tint_thing(thing, colours[13][13][2], 1);
            break;
        default:
            untint_thing(thing);
            break;
        }
    }
}
/******************************************************************************/
#ifdef __cplusplus
}
#endif