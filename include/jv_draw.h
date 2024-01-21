#ifndef JV_DRAW_H
#define JV_DRAW_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_vector.h"

#include "bn_sprite_items_cable.h"
#include "bn_sprite_items_person.h"

namespace jv{
void draw_person(bn::vector<bn::sprite_ptr, 4> &sprite_vector, bn::sprite_ptr &sprite, unsigned char frame, int x, int y){
    for(unsigned char i = 0; i < 4; i++){
        sprite = bn::sprite_items::person.create_sprite(x + 64 * i - 128 * ((i/2)%2), y + 64 * ((i/2)%2), i + frame*4);
        sprite.set_bg_priority(0);
        sprite_vector.push_back(sprite);
    }
}

void draw_cable(bn::vector<bn::sprite_ptr, 4> &sprite_vector, bn::sprite_ptr &sprite, unsigned char frame, int y = 50){
    for(unsigned char i = 0; i < 4; i++){
        sprite = bn::sprite_items::cable.create_sprite(-88 + 64 * i, y, i + frame);
        sprite.set_bg_priority(0);
        sprite_vector.push_back(sprite);
    }
}
}

#endif