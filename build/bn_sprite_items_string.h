#ifndef BN_SPRITE_ITEMS_STRING_H
#define BN_SPRITE_ITEMS_STRING_H

#include "bn_sprite_item.h"

//{{BLOCK(string_bn_gfx)

//======================================================================
//
//	string_bn_gfx, 64x4096@4, 
//	+ palette 16 entries, not compressed
//	+ 4096 tiles not compressed
//	Total size: 32 + 131072 = 131104
//
//	Time-stamp: 2024-01-20, 17:43:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STRING_BN_GFX_H
#define GRIT_STRING_BN_GFX_H

#define string_bn_gfxTilesLen 131072
extern const bn::tile string_bn_gfxTiles[4096];

#define string_bn_gfxPalLen 32
extern const bn::color string_bn_gfxPal[16];

#endif // GRIT_STRING_BN_GFX_H

//}}BLOCK(string_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item string(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(string_bn_gfxTiles, 4096), bpp_mode::BPP_4, compression_type::NONE, 64), 
            sprite_palette_item(span<const color>(string_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

