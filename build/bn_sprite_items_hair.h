#ifndef BN_SPRITE_ITEMS_HAIR_H
#define BN_SPRITE_ITEMS_HAIR_H

#include "bn_sprite_item.h"

//{{BLOCK(hair_bn_gfx)

//======================================================================
//
//	hair_bn_gfx, 32x128@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2024-01-24, 22:07:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HAIR_BN_GFX_H
#define GRIT_HAIR_BN_GFX_H

#define hair_bn_gfxTilesLen 2048
extern const bn::tile hair_bn_gfxTiles[64];

#define hair_bn_gfxPalLen 32
extern const bn::color hair_bn_gfxPal[16];

#endif // GRIT_HAIR_BN_GFX_H

//}}BLOCK(hair_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item hair(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(hair_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(hair_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

