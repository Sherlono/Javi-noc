#include "bn_core.h"
#include "bn_random.h"
#include "bn_keypad.h"
#include "bn_fixed.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_regular_bg_ptr.h"

#include "jv_buildings.h"
#include "jv_draw.h"
#include "bn_regular_bg_items_ground_bg.h"
#include "bn_sprite_items_person.h"
#include "bn_sprite_items_hair.h"
#include "bn_sprite_items_cable.h"
#include "bn_sprite_items_light_post.h"

int main()
{
    bn::core::init();
    
    bn::random randomizer;
    bn::regular_bg_ptr background = bn::regular_bg_items::ground_bg.create_bg(0, 0);

    // Sprite items load here so they can be fed to drawing function and be handeled there
    bn::sprite_ptr person = bn::sprite_items::person.create_sprite(0, 0);
    bn::sprite_ptr hair = bn::sprite_items::hair.create_sprite(0, 0);
    hair.set_bg_priority(0);
    bn::sprite_ptr cable = bn::sprite_items::cable.create_sprite(0, 0);

    bn::sprite_ptr post_low = bn::sprite_items::light_post.create_sprite(-152, 128, 1);
    bn::sprite_ptr post_high = bn::sprite_items::light_post.create_sprite(-152, 64, 0);
    post_low.set_bg_priority(0);
    post_high.set_bg_priority(0);

    const unsigned char f_delay = 2;                        // Increasing this will make the animation slower
    const unsigned int time_window = f_delay * 4;           // Since person and cable are made up of 4 sprites, this variable is the delay times 4
    unsigned char key_frame = 0;
    unsigned int post_frame = 0;
    bn::vector<bn::sprite_ptr, 4> cable_vector, person_vector;

    bn::vector<jv::Building*, MAXBUILDINGS> buildings_vector;

    // Initial buildings
    for(unsigned char i = 0; i < MAXBUILDINGS; i++){
        jv::builder(buildings_vector, randomizer, -120*2 + (64 + 30) * i, 16);
    }

    // Main loop
    while(true)
    {
        for(unsigned int f = 0; f < time_window; f++){
            unsigned int cable_frame = key_frame*16 + ((f / f_delay) % time_window)*4;
            
            // Foreground
            switch(key_frame){
                case 0:
                    jv::draw_person(person_vector, person, key_frame, -76, -30);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(2));
                    hair.set_position(-76 + 28, -30 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                    break;
                case 1:
                    jv::draw_person(person_vector, person, key_frame, -28, -12);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(3));
                    hair.set_position(-28 + 28, -12 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                    break;
                case 2:
                    jv::draw_person(person_vector, person, key_frame, 0, -12);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(0));
                    hair.set_position(0 + 28, -12 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                    break;
                case 3:
                    jv::draw_person(person_vector, person, key_frame, -20, -46);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(0));
                    hair.set_position(-20 + 28, -46 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                    break;
                case 4:
                    jv::draw_person(person_vector, person, key_frame-1, -50, -50);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(1));
                    hair.set_position(-50 + 28, -50 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame - 16);      // Same animation as case 3
                    break;
                case 5:
                    jv::draw_person(person_vector, person, key_frame-1, -70, -38);
                    hair.set_tiles(bn::sprite_items::hair.tiles_item().create_tiles(2));
                    hair.set_position(-70 + 28, -38 - 6);
                    jv::draw_cable(cable_vector, cable, cable_frame - 32);      // Same animation as case 3
                    break;
                default:
                    key_frame = 0;
                    break;
            }
            
            // Buildings
            for(unsigned char i = 0; i < buildings_vector.size(); i++){
                // Horizontal scroll
                buildings_vector[i]->set_position(buildings_vector[i]->x() + bn::fixed(0.25), buildings_vector[i]->y());
                // Delete offscreen buildings
                if (buildings_vector[i]->x() > 120 + buildings_vector[i]->_width/2) {
                    delete buildings_vector[i];
                    buildings_vector.erase(buildings_vector.begin()+i);
                }
            }
            // Refill Buildings vector
            if(buildings_vector.size() < MAXBUILDINGS){
                jv::builder(buildings_vector, randomizer, -200, 16);
            }
            // Light post
            unsigned int post_delay = 512;                  // Increasing this makes the post less frequent
            unsigned int x_increment = post_frame * 6;      // Increasing this makes the post move faster
            if(x_increment > post_delay){
                if(post_low.x() < 152){
                    for(unsigned char i = 0; i < 2; i++){
                        bn::fixed x = -152 - post_delay + x_increment;
                        bn::fixed y = -(post_low.x()-15)*(post_low.x()-15)/600 + 64;    // Parabolic arch of post trajectory (Thanks Desmos graphing calculator!)
                        post_low.set_position(x, y + 64);
                        post_high.set_position(x, y);
                    }
                }else{
                    // Reset light post
                    post_frame = 0;
                    post_low.set_position(-152, 64);
                    post_high.set_position(-152, 0);
                }
            }
            post_frame++;

            bn::core::update();
            cable_vector.clear();
            person_vector.clear();
        }
        key_frame++;
        
        // Listen, computers really struggle with random number generation so you gotta help it ok?
        if(bn::keypad::any_held()){
            randomizer.update();
        }
        // Reset combo
        if(bn::keypad::a_held() && bn::keypad::b_held() && bn::keypad::start_held() && bn::keypad::select_held()){
                bn::core::reset();
        }
    }
}
