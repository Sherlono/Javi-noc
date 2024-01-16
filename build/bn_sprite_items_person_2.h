#ifndef BN_SPRITE_ITEMS_PERSON_2_H
#define BN_SPRITE_ITEMS_PERSON_2_H

#include "bn_sprite_item.h"

//{{BLOCK(person_2_bn_gfx)

//======================================================================
//
//	person_2_bn_gfx, 64x256@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2024-01-16, 01:23:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PERSON_2_BN_GFX_H
#define GRIT_PERSON_2_BN_GFX_H

#define person_2_bn_gfxTilesLen 8192
extern const bn::tile person_2_bn_gfxTiles[256];

#define person_2_bn_gfxPalLen 32
extern const bn::color person_2_bn_gfxPal[16];

#endif // GRIT_PERSON_2_BN_GFX_H

//}}BLOCK(person_2_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item person_2(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(person_2_bn_gfxTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(person_2_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

