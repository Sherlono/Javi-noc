#ifndef BN_SPRITE_ITEMS_LIGHT_POST_H
#define BN_SPRITE_ITEMS_LIGHT_POST_H

#include "bn_sprite_item.h"

//{{BLOCK(light_post_bn_gfx)

//======================================================================
//
//	light_post_bn_gfx, 64x128@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2024-01-16, 00:29:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LIGHT_POST_BN_GFX_H
#define GRIT_LIGHT_POST_BN_GFX_H

#define light_post_bn_gfxTilesLen 4096
extern const bn::tile light_post_bn_gfxTiles[128];

#define light_post_bn_gfxPalLen 32
extern const bn::color light_post_bn_gfxPal[16];

#endif // GRIT_LIGHT_POST_BN_GFX_H

//}}BLOCK(light_post_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item light_post(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(light_post_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(light_post_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

