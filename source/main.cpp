#include "bn_core.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_string.h"
#include "bn_fixed.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"

#include "bn_regular_bg_items_ground_bg.h"

#include "bn_sprite_items_buildings_sprites.h"

#include "bn_sprite_items_string_a.h"
#include "bn_sprite_items_string_b.h"
#include "bn_sprite_items_string_c.h"
#include "bn_sprite_items_string_d.h"

#include "bn_sprite_items_person_1.h"
#include "bn_sprite_items_person_2.h"
#include "bn_sprite_items_person_3.h"
#include "bn_sprite_items_person_4.h"
#include "bn_sprite_items_person_5.h"

#include "bn_sprite_items_light_post.h"

namespace jv
{
class Building{
public:
    virtual ~Building(){};
    [[nodiscard]] bn::fixed x(){
        return this-> _x;
    }

    [[nodiscard]] bn::fixed y(){
        return this-> _y;
    }

    virtual void set_position(bn::fixed x_pos, bn::fixed y_pos){
        this->_x = x_pos;
        this->_y = y_pos;
    }

    bn::fixed _x, _y;
    int _size;
};

class Small : public Building{
public:
    Small(char type, int x_pos, int y_pos):
    _sprite_1(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_2(bn::sprite_items::buildings_sprites.create_sprite(_x , _y))
    {
        this->_x = x_pos;
        this->_y = y_pos;

        switch(type){
            case 0:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(0));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(1));
                _sprite_1.set_position(_x - 16, _y);
                _sprite_2.set_position(_x + 16, _y);
                this->_size = 64;
            break;
            case 1:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(2));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(3));
                _sprite_1.set_position(_x - 16, _y);
                _sprite_2.set_position(_x + 16, _y);
                this->_size = 64;
            break;
            case 2:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(4));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(5));
                _sprite_1.set_position(_x, _y - 32);
                _sprite_2.set_position(_x, _y);
                this->_size = 32;
            break;
            default:
                this->~Small();
            break;
        }
        _sprite_1.set_bg_priority(1);
        _sprite_2.set_bg_priority(1);
    }
    ~Small() {};
    void set_position(bn::fixed x_pos, bn::fixed y_pos) override{
        _sprite_1.set_position(x_pos + (_sprite_1.x() - _x), y_pos + (_sprite_1.y() - _y));
        _sprite_2.set_position(x_pos + (_sprite_2.x() - _x), y_pos + (_sprite_2.y() - _y));
        _x = x_pos;
        _y = y_pos;
    }
    
    bn::sprite_ptr _sprite_1, _sprite_2;
};

class Medium : public Building{
public:
    Medium(char type, int x_pos, int y_pos):
    _sprite_1(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_2(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_3(bn::sprite_items::buildings_sprites.create_sprite(_x , _y))
    {
        this->_x = x_pos;
        this->_y = y_pos;

        switch(type){
            case 3:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(6));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(7));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(8));
                _sprite_1.set_position(_x, _y - 64);
                _sprite_2.set_position(_x, _y - 32);
                _sprite_3.set_position(_x, _y);
            break;
            case 4:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(9));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_1.set_position(_x, _y - 64);
                _sprite_2.set_position(_x, _y - 32);
                _sprite_3.set_position(_x, _y);
            break;
            case 5:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(10));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_1.set_position(_x, _y - 64);
                _sprite_2.set_position(_x, _y - 32);
                _sprite_3.set_position(_x, _y);
            break;
            default:
                this->~Medium();
            break;
        }
        _sprite_1.set_bg_priority(1);
        _sprite_2.set_bg_priority(1);
        _sprite_3.set_bg_priority(1);
        this->_size = 32;
    }
    ~Medium() {};
    void set_position(bn::fixed x_pos, bn::fixed y_pos) override{
        _sprite_1.set_position(x_pos + (_sprite_1.x() - _x), y_pos + (_sprite_1.y() - _y));
        _sprite_2.set_position(x_pos + (_sprite_2.x() - _x), y_pos + (_sprite_2.y() - _y));
        _sprite_3.set_position(x_pos + (_sprite_3.x() - _x), y_pos + (_sprite_3.y() - _y));
        _x = x_pos;
        _y = y_pos;
    }
    
    bn::sprite_ptr _sprite_1, _sprite_2, _sprite_3;
};

class Big : public Building{
public:
    Big(char type, int x_pos, int y_pos):
    _sprite_1(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_2(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_3(bn::sprite_items::buildings_sprites.create_sprite(_x , _y)),
    _sprite_4(bn::sprite_items::buildings_sprites.create_sprite(_x , _y))
    {
        this->_x = x_pos;
        this->_y = y_pos;
        
        switch(type){
            case 6:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(12));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(13));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_4.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(11));
                _sprite_1.set_position(_x - 16, _y - 32);
                _sprite_2.set_position(_x + 16, _y - 32);
                _sprite_3.set_position(_x - 16, _y);
                _sprite_4.set_position(_x + 16, _y);
                this-> _size = 64;
            break;
            case 7:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(14));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(15));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(16));
                _sprite_4.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(17));
                _sprite_1.set_position(_x - 16 - 32, _y);
                _sprite_2.set_position(_x - 16, _y);
                _sprite_3.set_position(_x + 16, _y);
                _sprite_4.set_position(_x + 16 + 32, _y);
                this-> _size = 128;
            break;
            case 8:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(18));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(19));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(20));
                _sprite_4.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(21));
                _sprite_1.set_position(_x - 16, _y - 32);
                _sprite_2.set_position(_x - 16, _y);
                _sprite_3.set_position(_x + 16, _y - 32);
                _sprite_4.set_position(_x + 16, _y);
                this-> _size = 64;
            break;
            case 9:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(22));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(23));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(24));
                _sprite_4.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(25));
                _sprite_1.set_position(_x - 16, _y - 32);
                _sprite_2.set_position(_x - 16, _y);
                _sprite_3.set_position(_x + 16, _y - 32);
                _sprite_4.set_position(_x + 16, _y);
                this-> _size = 64;
            break;
            case 10:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(26));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(27));
                _sprite_3.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(28));
                _sprite_4.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(29));
                _sprite_1.set_position(_x - 16, _y - 32);
                _sprite_2.set_position(_x - 16, _y);
                _sprite_3.set_position(_x + 16, _y - 32);
                _sprite_4.set_position(_x + 16, _y);
                this-> _size = 64;
            break;
            default:
                this->~Big();
            break;
        }
        _sprite_1.set_bg_priority(1);
        _sprite_2.set_bg_priority(1);
        _sprite_3.set_bg_priority(1);
        _sprite_4.set_bg_priority(1);
    }
    ~Big() {};
    void set_position(bn::fixed x_pos, bn::fixed y_pos) override{
        _sprite_1.set_position(x_pos + (_sprite_1.x() - _x), y_pos + (_sprite_1.y() - _y));
        _sprite_2.set_position(x_pos + (_sprite_2.x() - _x), y_pos + (_sprite_2.y() - _y));
        _sprite_3.set_position(x_pos + (_sprite_3.x() - _x), y_pos + (_sprite_3.y() - _y));
        _sprite_4.set_position(x_pos + (_sprite_4.x() - _x), y_pos + (_sprite_4.y() - _y));
        _x = x_pos;
        _y = y_pos;
    }
    
    bn::sprite_ptr _sprite_1, _sprite_2, _sprite_3, _sprite_4;
};
}

int main()
{
    bn::core::init();
    
    bn::random randomizer;
    unsigned char random;
    bn::regular_bg_ptr background = bn::regular_bg_items::ground_bg.create_bg(0, 0);

    bn::sprite_ptr post_low = bn::sprite_items::light_post.create_sprite(-152, 128, 1);
    bn::sprite_ptr post_high = bn::sprite_items::light_post.create_sprite(-152, 64, 0);
    post_low.set_bg_priority(0);
    post_high.set_bg_priority(0);

    const unsigned char f_delay = 2;
    const unsigned int time_window = f_delay * 4;
    unsigned int key_frame = 0;
    unsigned int post_frame = 0;
    bn::vector<bn::sprite_ptr, 4> string_vector, person_vector;

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
        building->set_position(building->x() - building->_size/2, building->y());
        buildings_vector.push_back(building);
    }
    // Main loop
    while(true)
    {
        for(unsigned int f = 0; f < time_window; f++){
            unsigned int string_y_offset = 50;
            unsigned int mod = f / f_delay;
            
            // Foreground
            switch(key_frame){
                case 0:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_1.create_sprite(-76 + 64 * i - 128 * ((i/2)%2), -30 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_a.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_a.create_sprite(-88 + 64 * i, string_y_offset, i + 4);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_a.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_a.create_sprite(-88 + 64 * i, string_y_offset, i + 12);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
                    break;
                case 1:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_2.create_sprite(- 28 + 64 * i - 128 * ((i/2)%2), -12 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_b.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_b.create_sprite(-88 + 64 * i, string_y_offset, i + 4);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_b.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_b.create_sprite(-88 + 64 * i, string_y_offset, i + 12);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
                break;
                case 2:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_3.create_sprite(64 * i - 128 * ((i/2)%2), -12 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_c.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_c.create_sprite(-88 + 64 * i, string_y_offset, i + 4);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_c.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_c.create_sprite(-88 + 64 * i, string_y_offset, i + 12);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
                break;
                case 3:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_4.create_sprite(- 20 + 64 * i - 128 * ((i/2)%2), -46 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
                break;
                case 4:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_4.create_sprite(-50 + 64 * i - 128 * ((i/2)%2), -50 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
                break;
                case 5:
                    // Person
                    for(unsigned char i = 0; i < 4; i++){
                        bn::sprite_ptr person = bn::sprite_items::person_5.create_sprite(-70 + 64 * i - 128 * ((i/2)%2), -38 + 64*((i/2)%2), i);
                        person.set_bg_priority(0);
                        person_vector.push_back(person);
                    }
                    
                    // String
                    if(mod % time_window == 0){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 1){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else if(mod % time_window == 2){
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }else{
                        for(char i = 0;i < 4;i++){
                            bn::sprite_ptr string = bn::sprite_items::string_d.create_sprite(-88 + 64 * i, string_y_offset, i + 8);
                            string_vector.push_back(string);
                            string_vector[i].set_bg_priority(0);
                        }
                    }
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
                if (buildings_vector[i]->x() > 120 + buildings_vector[i]->_size/2) {
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
                building->set_position(building->x() - building->_size/2, building->y());
                buildings_vector.push_back(building);
            }
            // Light post
            static unsigned int delay = 512;
            if(post_frame > delay){
                if(post_low.x() < 120 + 32){
                    for(unsigned p = 0; p < 2; p++){
                        bn::fixed x = -152 - delay + post_frame;
                        bn::fixed y = -(((post_low.x()-15)*(post_low.x()-15))/600) + 72;
                        post_low.set_position(x, y + 64);
                        post_high.set_position(x, y);
                    }
                }else{
                    post_frame = 0;
                    post_low.set_position(-152, 64);
                    post_high.set_position(-152, 0);
                }
            }
            post_frame += 6;

            bn::core::update();
            string_vector.clear();
            person_vector.clear();
        }
        key_frame++;
    }
}
