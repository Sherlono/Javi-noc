#ifndef BN_SPRITE_ITEMS_BUILDINGS_SPRITES_H
#define BN_SPRITE_ITEMS_BUILDINGS_SPRITES_H

#include "bn_sprite_item.h"

//{{BLOCK(buildings_sprites_bn_gfx)

//======================================================================
//
//	buildings_sprites_bn_gfx, 32x1024@4, 
//	+ palette 16 entries, not compressed
//	+ 512 tiles not compressed
//	Total size: 32 + 16384 = 16416
//
//	Time-stamp: 2024-01-16, 00:14:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUILDINGS_SPRITES_BN_GFX_H
#define GRIT_BUILDINGS_SPRITES_BN_GFX_H

#define buildings_sprites_bn_gfxTilesLen 16384
extern const bn::tile buildings_sprites_bn_gfxTiles[512];

#define buildings_sprites_bn_gfxPalLen 32
extern const bn::color buildings_sprites_bn_gfxPal[16];

#endif // GRIT_BUILDINGS_SPRITES_BN_GFX_H

//}}BLOCK(buildings_sprites_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item buildings_sprites(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(buildings_sprites_bn_gfxTiles, 512), bpp_mode::BPP_4, compression_type::NONE, 32), 
            sprite_palette_item(span<const color>(buildings_sprites_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

