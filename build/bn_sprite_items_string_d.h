#ifndef BN_SPRITE_ITEMS_STRING_D_H
#define BN_SPRITE_ITEMS_STRING_D_H

#include "bn_sprite_item.h"

//{{BLOCK(string_d_bn_gfx)

//======================================================================
//
//	string_d_bn_gfx, 64x768@4, 
//	+ palette 16 entries, not compressed
//	+ 768 tiles not compressed
//	Total size: 32 + 24576 = 24608
//
//	Time-stamp: 2024-01-15, 20:25:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STRING_D_BN_GFX_H
#define GRIT_STRING_D_BN_GFX_H

#define string_d_bn_gfxTilesLen 24576
extern const bn::tile string_d_bn_gfxTiles[768];

#define string_d_bn_gfxPalLen 32
extern const bn::color string_d_bn_gfxPal[16];

#endif // GRIT_STRING_D_BN_GFX_H

//}}BLOCK(string_d_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item string_d(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(string_d_bn_gfxTiles, 768), bpp_mode::BPP_4, compression_type::NONE, 12), 
            sprite_palette_item(span<const color>(string_d_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

