#ifndef BN_SPRITE_ITEMS_PERSON_H
#define BN_SPRITE_ITEMS_PERSON_H

#include "bn_sprite_item.h"

//{{BLOCK(person_bn_gfx)

//======================================================================
//
//	person_bn_gfx, 64x1280@4, 
//	+ palette 16 entries, not compressed
//	+ 1280 tiles not compressed
//	Total size: 32 + 40960 = 40992
//
//	Time-stamp: 2024-01-20, 22:08:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PERSON_BN_GFX_H
#define GRIT_PERSON_BN_GFX_H

#define person_bn_gfxTilesLen 40960
extern const bn::tile person_bn_gfxTiles[1280];

#define person_bn_gfxPalLen 32
extern const bn::color person_bn_gfxPal[16];

#endif // GRIT_PERSON_BN_GFX_H

//}}BLOCK(person_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item person(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(person_bn_gfxTiles, 1280), bpp_mode::BPP_4, compression_type::NONE, 20), 
            sprite_palette_item(span<const color>(person_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

