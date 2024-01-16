
@{{BLOCK(ground_bg_bn_gfx)

@=======================================================================
@
@	ground_bg_bn_gfx, 256x256@4, 
@	+ palette 16 entries, not compressed
@	+ 30 tiles (t|f|p reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 32 + 960 + 2048 = 3040
@
@	Time-stamp: 2024-01-16, 01:56:03
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ground_bg_bn_gfxTiles		@ 960 unsigned chars
	.hidden ground_bg_bn_gfxTiles
ground_bg_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x33333322
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22233333
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x33222222,0x33332222
	.word 0x22222222,0x22222222,0x33222222,0x33333222,0x33333322,0x33333333,0x33333333,0x33333333
	.word 0x33332222,0x33333332,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333

	.word 0x22222333,0x22333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22222222,0x22222222,0x22222223,0x22223333,0x22233333,0x23333333,0x33333333,0x33333333
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222223,0x22222333
	.word 0x22222222,0x22222222,0x22222222,0x32222222,0x33222222,0x33322222,0x33332222,0x33333222
	.word 0x33333222,0x33333322,0x33333332,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22223333,0x22233333,0x22333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222223,0x22222233,0x22222333,0x22223333
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x32222222,0x32222222,0x33222222,0x33222222

	.word 0x33333322,0x33333322,0x33333332,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22233333,0x22233333,0x22333333,0x23333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222223,0x22222223
	.word 0x33322222,0x33332222,0x33332222,0x33333222,0x33333222,0x33333322,0x33333322,0x33333322
	.word 0x22222233,0x22222333,0x22222333,0x22223333,0x22223333,0x22233333,0x22233333,0x22233333
	.word 0x33333322,0x33333332,0x33333332,0x33333332,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x22233333,0x22333333,0x22333333,0x22333333,0x23333333,0x23333333,0x23333333,0x23333333
	.word 0x22222222,0x22222222,0x32222222,0x32222222,0x32222222,0x32222222,0x32222222,0x32222222

	.word 0x23333333,0x23333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x32222222,0x32222222,0x32222222,0x32222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x23333333,0x23333333,0x23333333,0x23333333
	.word 0x33333333,0x33333333,0x33333332,0x33333332,0x33333332,0x33333322,0x33333322,0x33333322
	.word 0x23333333,0x23333333,0x22333333,0x22333333,0x22333333,0x22233333,0x22233333,0x22233333
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global ground_bg_bn_gfxMap		@ 2048 unsigned chars
	.hidden ground_bg_bn_gfxMap
ground_bg_bn_gfxMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0003,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0004,0x0005,0x0006,0x0007,0x0007,0x0008
	.hword 0x0009,0x000A,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x000B,0x000C,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x000D,0x000E,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x000F,0x0010,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0011,0x0012,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0013,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0014,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0015,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0016,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0017
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0018,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0019
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x001A,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x001B,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x001C,0x0001,0x0001,0x0001,0x0001

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D
	.hword 0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D,0x001D

	.section .rodata
	.align	2
	.global ground_bg_bn_gfxPal		@ 32 unsigned chars
	.hidden ground_bg_bn_gfxPal
ground_bg_bn_gfxPal:
	.hword 0x7C1F,0x200A,0x05FF,0x001C,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(ground_bg_bn_gfx)