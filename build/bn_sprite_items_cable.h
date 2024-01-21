#ifndef BN_SPRITE_ITEMS_CABLE_H
#define BN_SPRITE_ITEMS_CABLE_H

#include "bn_sprite_item.h"

//{{BLOCK(cable_bn_gfx)

//======================================================================
//
//	cable_bn_gfx, 64x4096@4, 
//	+ palette 16 entries, not compressed
//	+ 4096 tiles not compressed
//	Total size: 32 + 131072 = 131104
//
//	Time-stamp: 2024-01-20, 23:18:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CABLE_BN_GFX_H
#define GRIT_CABLE_BN_GFX_H

#define cable_bn_gfxTilesLen 131072
extern const bn::tile cable_bn_gfxTiles[4096];

#define cable_bn_gfxPalLen 32
extern const bn::color cable_bn_gfxPal[16];

#endif // GRIT_CABLE_BN_GFX_H

//}}BLOCK(cable_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cable(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cable_bn_gfxTiles, 4096), bpp_mode::BPP_4, compression_type::NONE, 64), 
            sprite_palette_item(span<const color>(cable_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

