#ifndef JV_BUILDINGS_H
#define JV_BUILDINGS_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"

#include "bn_sprite_items_buildings_sprites.h"

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
    unsigned char _width;
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
                this->_width = 64;
            break;
            case 1:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(2));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(3));
                _sprite_1.set_position(_x - 16, _y);
                _sprite_2.set_position(_x + 16, _y);
                this->_width = 64;
            break;
            case 2:
                _sprite_1.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(4));
                _sprite_2.set_tiles(bn::sprite_items::buildings_sprites.tiles_item().create_tiles(5));
                _sprite_1.set_position(_x, _y - 32);
                _sprite_2.set_position(_x, _y);
                this->_width = 32;
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
        this->_width = 32;
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
                this-> _width = 64;
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
                this-> _width = 128;
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
                this-> _width = 64;
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
                this-> _width = 64;
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
                this-> _width = 64;
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
#endif