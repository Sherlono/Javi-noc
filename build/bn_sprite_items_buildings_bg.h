#ifndef BN_SPRITE_ITEMS_BUILDINGS_BG_H
#define BN_SPRITE_ITEMS_BUILDINGS_BG_H

#include "bn_sprite_item.h"

//{{BLOCK(buildings_bg_bn_gfx)

//======================================================================
//
//	buildings_bg_bn_gfx, 64x1024@4, 
//	+ palette 16 entries, not compressed
//	+ 1024 tiles not compressed
//	Total size: 32 + 32768 = 32800
//
//	Time-stamp: 2024-01-14, 17:29:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUILDINGS_BG_BN_GFX_H
#define GRIT_BUILDINGS_BG_BN_GFX_H

#define buildings_bg_bn_gfxTilesLen 32768
extern const bn::tile buildings_bg_bn_gfxTiles[1024];

#define buildings_bg_bn_gfxPalLen 32
extern const bn::color buildings_bg_bn_gfxPal[16];

#endif // GRIT_BUILDINGS_BG_BN_GFX_H

//}}BLOCK(buildings_bg_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item buildings_bg(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(buildings_bg_bn_gfxTiles, 1024), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(buildings_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

