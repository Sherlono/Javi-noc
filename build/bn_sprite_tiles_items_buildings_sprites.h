#ifndef BN_SPRITE_TILES_ITEMS_BUILDINGS_SPRITES_H
#define BN_SPRITE_TILES_ITEMS_BUILDINGS_SPRITES_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(buildings_sprites_bn_gfx)

//======================================================================
//
//	buildings_sprites_bn_gfx, 64x1024@4, 
//	+ 1024 tiles not compressed
//	Total size: 32768 = 32768
//
//	Time-stamp: 2024-01-15, 01:49:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUILDINGS_SPRITES_BN_GFX_H
#define GRIT_BUILDINGS_SPRITES_BN_GFX_H

#define buildings_sprites_bn_gfxTilesLen 32768
extern const bn::tile buildings_sprites_bn_gfxTiles[1024];

#endif // GRIT_BUILDINGS_SPRITES_BN_GFX_H

//}}BLOCK(buildings_sprites_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item buildings_sprites(span<const tile>(buildings_sprites_bn_gfxTiles, 1024), 
            bpp_mode::BPP_4, compression_type::NONE, 16);

    constexpr inline sprite_shape_size buildings_sprites_shape_size(sprite_shape::SQUARE, sprite_size::HUGE);
}

#endif

