#ifndef BN_REGULAR_BG_ITEMS_GROUND_BG_H
#define BN_REGULAR_BG_ITEMS_GROUND_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(ground_bg_bn_gfx)

//======================================================================
//
//	ground_bg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 30 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 960 + 2048 = 3040
//
//	Time-stamp: 2024-01-16, 01:56:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GROUND_BG_BN_GFX_H
#define GRIT_GROUND_BG_BN_GFX_H

#define ground_bg_bn_gfxTilesLen 960
extern const bn::tile ground_bg_bn_gfxTiles[30];

#define ground_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell ground_bg_bn_gfxMap[1024];

#define ground_bg_bn_gfxPalLen 32
extern const bn::color ground_bg_bn_gfxPal[16];

#endif // GRIT_GROUND_BG_BN_GFX_H

//}}BLOCK(ground_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item ground_bg(
            regular_bg_tiles_item(span<const tile>(ground_bg_bn_gfxTiles, 30), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(ground_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(ground_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

