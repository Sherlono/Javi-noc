#ifndef BN_SPRITE_ITEMS_STRING_A_H
#define BN_SPRITE_ITEMS_STRING_A_H

#include "bn_sprite_item.h"

//{{BLOCK(string_a_bn_gfx)

//======================================================================
//
//	string_a_bn_gfx, 64x1024@4, 
//	+ palette 16 entries, not compressed
//	+ 1024 tiles not compressed
//	Total size: 32 + 32768 = 32800
//
//	Time-stamp: 2024-01-15, 20:20:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STRING_A_BN_GFX_H
#define GRIT_STRING_A_BN_GFX_H

#define string_a_bn_gfxTilesLen 32768
extern const bn::tile string_a_bn_gfxTiles[1024];

#define string_a_bn_gfxPalLen 32
extern const bn::color string_a_bn_gfxPal[16];

#endif // GRIT_STRING_A_BN_GFX_H

//}}BLOCK(string_a_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item string_a(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(string_a_bn_gfxTiles, 1024), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(string_a_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

