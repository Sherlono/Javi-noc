#include "bn_core.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_fixed.h"
#include "bn_regular_bg_ptr.h"

#include "jv_buildings.h"
#include "jv_draw.h"
#include "bn_regular_bg_items_ground_bg.h"
#include "bn_sprite_items_cable.h"
#include "bn_sprite_items_person.h"
#include "bn_sprite_items_light_post.h"

int main()
{
    bn::core::init();
    
    bn::random randomizer;
    unsigned char random;
    bn::regular_bg_ptr background = bn::regular_bg_items::ground_bg.create_bg(0, 0);

    // Sprite items load here so they can be fed to drawing function and be handeled there
    bn::sprite_ptr person = bn::sprite_items::person.create_sprite(0, 0);
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

    const char MAXBUILDINGS = 7;
    bn::vector<jv::Building*, MAXBUILDINGS> buildings_vector;

    // Initial buildings
    int starting_point_y = 16;
    for(unsigned char b = 0; b < MAXBUILDINGS; b++){
        jv::Building* building;
        random = randomizer.get_int(11);
        if(random < 3){
            building = new jv::Small(random, -120*2 + (64 + 16) * b, starting_point_y);
        }else if(random < 6){
            building = new jv::Medium(random, -120*2 + (64 + 16) * b, starting_point_y);
        }else{
            building = new jv::Big(random, -120*2 + (64 + 16) * b, starting_point_y);
        }
        building->set_position(building->x() - building->_width/2, building->y());
        buildings_vector.push_back(building);
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
                    jv::draw_cable(cable_vector, cable, cable_frame);
                    break;
                case 1:
                    jv::draw_person(person_vector, person, key_frame, -28, -12);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                break;
                case 2:
                    jv::draw_person(person_vector, person, key_frame, 0, -12);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                break;
                case 3:
                    jv::draw_person(person_vector, person, key_frame, -20, -46);
                    jv::draw_cable(cable_vector, cable, cable_frame);
                break;
                case 4:
                    jv::draw_person(person_vector, person, key_frame-1, -50, -50);
                    jv::draw_cable(cable_vector, cable, cable_frame - 16);      // Same animation as case 3
                break;
                case 5:
                    jv::draw_person(person_vector, person, key_frame-1, -70, -38);
                    jv::draw_cable(cable_vector, cable, cable_frame - 32);      // Same animation as case 3
                break;
                default:
                    key_frame = 0;
                break;
            }
            
            // Buildings
            for(char i = 0;i < buildings_vector.size(); i++){
                // Move buildings
                buildings_vector[i]->set_position(buildings_vector[i]->x() + bn::fixed(0.25), buildings_vector[i]->y());
                // Delete offscreen buildings
                if (buildings_vector[i]->x() > 120 + buildings_vector[i]->_width/2) {
                    delete buildings_vector[i];
                    buildings_vector.erase(buildings_vector.begin()+i);
                }
            }
            // Refill Buildings vector
            static int start_point_x = -120 - 64 - 16;
            if(buildings_vector.size() < MAXBUILDINGS){
                jv::Building* building;
                random = randomizer.get_int(11);
                if(random < 3){
                    building = new jv::Small(random, start_point_x, starting_point_y);
                }else if(random < 6){
                    building = new jv::Medium(random, start_point_x, starting_point_y);
                }else{
                    building = new jv::Big(random, start_point_x, starting_point_y);
                }
                building->set_position(building->x() - building->_width/2, building->y());
                buildings_vector.push_back(building);
            }
            // Light post
            static unsigned int delay = 512;
            unsigned int x_increment = post_frame * 6;
            if(x_increment > delay){
                if(post_low.x() < 120 + 32){
                    for(unsigned p = 0; p < 2; p++){
                        bn::fixed x = -152 - delay + x_increment;
                        bn::fixed y = -(post_low.x()-15)*(post_low.x()-15)/600+ 64;
                        post_low.set_position(x, y + 64);
                        post_high.set_position(x, y);
                    }
                }else{
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
    }
}
