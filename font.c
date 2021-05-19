/* font.c: bitmap font, taken from https://git.badd10de.dev/bd-font */

/*
   each glyph is 8x8

   char c;
   unsigned char *glyph = font[(unsigned)c];

   ........  glyph[0]
   ..OOO...  glyph[1]
   .O...O..  glyph[2]
   .O...O..  glyph[3]
   .OOOOO..  glyph[4]
   .O...O..  glyph[5]
   .O...O..  glyph[6]
   ........  glyph[7]

   . = 0
   O = 1
 */

unsigned char font[256][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /* ASCII=0 */
  {0x00, 0x00, 0x24, 0x00, 0x42, 0x3c, 0x00, 0x00},
  {0x00, 0x00, 0x24, 0x00, 0x3c, 0x42, 0x00, 0x00},
  {0x00, 0x00, 0x6c, 0x7c, 0x7c, 0x38, 0x10, 0x00},
  {0x00, 0x10, 0x38, 0x7c, 0x7c, 0x38, 0x10, 0x00},
  {0x00, 0x38, 0x38, 0x7c, 0x6c, 0x7c, 0x10, 0x38},
  {0x00, 0x10, 0x38, 0x7c, 0x7c, 0x7c, 0x10, 0x38},
  {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
  {0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x7e, 0x7e, 0x7e},
  {0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00},
  {0x7e, 0x7e, 0x66, 0x5a, 0x5a, 0x66, 0x7e, 0x7e},
  {0x00, 0x10, 0x38, 0x7c, 0x10, 0x38, 0x44, 0x38},
  {0x00, 0x38, 0x44, 0x38, 0x10, 0x10, 0x7c, 0x10},
  {0x00, 0x18, 0x1c, 0x14, 0x10, 0x10, 0x30, 0x30},
  {0x00, 0x3c, 0x24, 0x24, 0x24, 0x2c, 0x6c, 0x60},
  {0x00, 0x10, 0x44, 0x10, 0x38, 0x10, 0x44, 0x10},
  {0x20, 0x30, 0x38, 0x3c, 0x38, 0x30, 0x20, 0x00},
  {0x04, 0x0c, 0x1c, 0x3c, 0x1c, 0x0c, 0x04, 0x00},
  {0x10, 0x38, 0x7c, 0x10, 0x10, 0x7c, 0x38, 0x10},
  {0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x28},
  {0x00, 0x3c, 0x54, 0x54, 0x34, 0x14, 0x14, 0x14},
  {0x00, 0x1c, 0x20, 0x3c, 0x42, 0x3c, 0x04, 0x78},
  {0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00},
  {0x10, 0x38, 0x7c, 0x10, 0x7c, 0x38, 0x10, 0x7c},
  {0x10, 0x38, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x38, 0x10},
  {0x00, 0x00, 0x08, 0x0c, 0x7e, 0x0c, 0x08, 0x00},
  {0x00, 0x00, 0x10, 0x30, 0x7e, 0x30, 0x10, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x7c},
  {0x00, 0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00},
  {0x00, 0x10, 0x10, 0x38, 0x38, 0x7c, 0x7c, 0x00},
  {0x00, 0x7c, 0x7c, 0x38, 0x38, 0x10, 0x10, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x10},
  {0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x28, 0x7c, 0x28, 0x7c, 0x28, 0x00},
  {0x00, 0x10, 0x38, 0x40, 0x38, 0x04, 0x78, 0x10},
  {0x00, 0x00, 0x64, 0x68, 0x10, 0x2c, 0x4c, 0x00},
  {0x00, 0x10, 0x28, 0x10, 0x2c, 0x48, 0x34, 0x00},
  {0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10},
  {0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10},
  {0x00, 0x00, 0x28, 0x10, 0x7c, 0x10, 0x28, 0x00},
  {0x00, 0x00, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x10, 0x20},
  {0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
  {0x00, 0x04, 0x0c, 0x18, 0x30, 0x60, 0x40, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x54, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x30, 0x50, 0x10, 0x10, 0x7c, 0x00},
  {0x00, 0x00, 0x38, 0x04, 0x38, 0x40, 0x7c, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x18, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x08, 0x18, 0x28, 0x7c, 0x08, 0x00},
  {0x00, 0x00, 0x7c, 0x40, 0x78, 0x04, 0x78, 0x00},
  {0x00, 0x00, 0x38, 0x40, 0x78, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x7c, 0x04, 0x08, 0x10, 0x20, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x38, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x3c, 0x04, 0x38, 0x00},
  {0x00, 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x00},
  {0x00, 0x00, 0x30, 0x30, 0x00, 0x30, 0x10, 0x20},
  {0x00, 0x08, 0x10, 0x20, 0x20, 0x10, 0x08, 0x00},
  {0x00, 0x00, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x00},
  {0x00, 0x20, 0x10, 0x08, 0x08, 0x10, 0x20, 0x00},
  {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x00, 0x10},
  {0x00, 0x38, 0x4c, 0x54, 0x58, 0x40, 0x38, 0x00},
  {0x00, 0x38, 0x44, 0x44, 0x7c, 0x44, 0x44, 0x00},
  {0x00, 0x78, 0x44, 0x78, 0x44, 0x44, 0x78, 0x00},
  {0x00, 0x38, 0x44, 0x40, 0x40, 0x44, 0x38, 0x00},
  {0x00, 0x70, 0x48, 0x44, 0x44, 0x48, 0x70, 0x00},
  {0x00, 0x7c, 0x40, 0x78, 0x40, 0x40, 0x7c, 0x00},
  {0x00, 0x7c, 0x40, 0x78, 0x40, 0x40, 0x40, 0x00},
  {0x00, 0x38, 0x44, 0x40, 0x4c, 0x44, 0x38, 0x00},
  {0x00, 0x44, 0x44, 0x44, 0x7c, 0x44, 0x44, 0x00},
  {0x00, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00},
  {0x00, 0x04, 0x04, 0x04, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x44, 0x48, 0x50, 0x70, 0x48, 0x44, 0x00},
  {0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x00},
  {0x00, 0x44, 0x6c, 0x54, 0x44, 0x44, 0x44, 0x00},
  {0x00, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x44, 0x00},
  {0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x78, 0x44, 0x44, 0x78, 0x40, 0x40, 0x00},
  {0x00, 0x38, 0x44, 0x44, 0x54, 0x48, 0x34, 0x00},
  {0x00, 0x78, 0x44, 0x44, 0x78, 0x48, 0x44, 0x00},
  {0x00, 0x38, 0x40, 0x38, 0x04, 0x44, 0x38, 0x00},
  {0x00, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00},
  {0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x44, 0x44, 0x44, 0x44, 0x28, 0x10, 0x00},
  {0x00, 0x44, 0x44, 0x54, 0x54, 0x54, 0x28, 0x00},
  {0x00, 0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0x00},
  {0x00, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x00},
  {0x00, 0x7c, 0x08, 0x10, 0x20, 0x40, 0x7c, 0x00},
  {0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38},
  {0x00, 0x40, 0x60, 0x30, 0x18, 0x0c, 0x04, 0x00},
  {0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x38},
  {0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00},
  {0x00, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3c, 0x00},
  {0x00, 0x40, 0x40, 0x78, 0x44, 0x44, 0x78, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x40, 0x44, 0x38, 0x00},
  {0x00, 0x04, 0x04, 0x3c, 0x44, 0x44, 0x3c, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x78, 0x40, 0x3c, 0x00},
  {0x00, 0x00, 0x3c, 0x40, 0x40, 0x78, 0x40, 0x40},
  {0x00, 0x00, 0x3c, 0x44, 0x44, 0x3c, 0x04, 0x38},
  {0x00, 0x40, 0x40, 0x78, 0x44, 0x44, 0x44, 0x00},
  {0x00, 0x10, 0x00, 0x30, 0x10, 0x10, 0x7c, 0x00},
  {0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x44, 0x38},
  {0x00, 0x40, 0x48, 0x50, 0x60, 0x50, 0x4c, 0x00},
  {0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00},
  {0x00, 0x00, 0x68, 0x54, 0x54, 0x54, 0x54, 0x00},
  {0x00, 0x00, 0x70, 0x4c, 0x44, 0x44, 0x44, 0x00},
  {0x00, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x78, 0x44, 0x44, 0x78, 0x40, 0x40},
  {0x00, 0x00, 0x3c, 0x44, 0x44, 0x3c, 0x04, 0x0e},
  {0x00, 0x00, 0x58, 0x64, 0x40, 0x40, 0x40, 0x00},
  {0x00, 0x00, 0x38, 0x40, 0x38, 0x04, 0x78, 0x00},
  {0x00, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x18, 0x00},
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x28, 0x10, 0x00},
  {0x00, 0x00, 0x44, 0x44, 0x54, 0x54, 0x28, 0x00},
  {0x00, 0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00},
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x3c, 0x04, 0x38},
  {0x00, 0x00, 0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00},
  {0x18, 0x20, 0x20, 0x40, 0x40, 0x20, 0x20, 0x18},
  {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x30, 0x08, 0x08, 0x04, 0x04, 0x08, 0x08, 0x30},
  {0x00, 0x00, 0x34, 0x58, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x10, 0x28, 0x44, 0x44, 0x7c, 0x00},
  {0x00, 0x38, 0x44, 0x40, 0x44, 0x38, 0x10, 0x70},
  {0x00, 0x28, 0x00, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x08, 0x10, 0x00, 0x38, 0x44, 0x78, 0x40, 0x3c},
  {0x10, 0x28, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3c},
  {0x00, 0x28, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3c},
  {0x20, 0x10, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3c},
  {0x10, 0x28, 0x10, 0x38, 0x04, 0x3c, 0x44, 0x3c},
  {0x00, 0x00, 0x38, 0x40, 0x44, 0x38, 0x10, 0x70},
  {0x10, 0x28, 0x00, 0x38, 0x44, 0x78, 0x40, 0x3c},
  {0x00, 0x28, 0x00, 0x38, 0x44, 0x78, 0x40, 0x3c},
  {0x20, 0x10, 0x00, 0x38, 0x44, 0x78, 0x40, 0x3c},
  {0x00, 0x28, 0x00, 0x30, 0x10, 0x10, 0x10, 0x7c},
  {0x00, 0x28, 0x00, 0x30, 0x10, 0x10, 0x10, 0x7c},
  {0x20, 0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x7c},
  {0x00, 0x28, 0x00, 0x38, 0x44, 0x7c, 0x44, 0x44},
  {0x10, 0x28, 0x10, 0x38, 0x44, 0x7c, 0x44, 0x44},
  {0x08, 0x10, 0x00, 0x7c, 0x40, 0x78, 0x40, 0x7c},
  {0x00, 0x00, 0x68, 0x14, 0x38, 0x50, 0x2c, 0x00},
  {0x00, 0x3c, 0x50, 0x58, 0x70, 0x50, 0x5c, 0x00},
  {0x10, 0x28, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38},
  {0x00, 0x28, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38},
  {0x20, 0x10, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38},
  {0x10, 0x28, 0x00, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x20, 0x10, 0x00, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x00, 0x28, 0x00, 0x44, 0x44, 0x3c, 0x04, 0x38},
  {0x28, 0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x28, 0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x00, 0x10, 0x38, 0x44, 0x40, 0x44, 0x38, 0x10},
  {0x00, 0x18, 0x24, 0x70, 0x20, 0x20, 0x7c, 0x00},
  {0x00, 0x44, 0x28, 0x10, 0x38, 0x10, 0x38, 0x10},
  {0x00, 0x1c, 0x20, 0x78, 0x20, 0x78, 0x20, 0x1c},
  {0x00, 0x0c, 0x10, 0x38, 0x10, 0x10, 0x10, 0x60},
  {0x08, 0x10, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3c},
  {0x08, 0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x7c},
  {0x08, 0x10, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38},
  {0x08, 0x10, 0x00, 0x44, 0x44, 0x44, 0x44, 0x38},
  {0x34, 0x58, 0x00, 0x70, 0x4c, 0x44, 0x44, 0x44},
  {0x34, 0x58, 0x00, 0x44, 0x64, 0x54, 0x4c, 0x44},
  {0x00, 0x38, 0x48, 0x34, 0x00, 0x78, 0x00, 0x00},
  {0x00, 0x30, 0x48, 0x30, 0x00, 0x78, 0x00, 0x00},
  {0x10, 0x00, 0x10, 0x20, 0x40, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x00, 0x7c, 0x40, 0x40, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x7c, 0x04, 0x04, 0x00, 0x00},
  {0x60, 0x24, 0x28, 0x16, 0x22, 0x44, 0x0f, 0x00},
  {0x60, 0x24, 0x28, 0x16, 0x2a, 0x4f, 0x02, 0x00},
  {0x10, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00},
  {0x00, 0x12, 0x24, 0x48, 0x24, 0x12, 0x00, 0x00},
  {0x00, 0x48, 0x24, 0x12, 0x24, 0x48, 0x00, 0x00},
  {0x00, 0x11, 0x00, 0x44, 0x00, 0x11, 0x00, 0x44},
  {0xaa, 0x11, 0xaa, 0x44, 0xaa, 0x11, 0xaa, 0x44},
  {0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10},
  {0x28, 0x28, 0x28, 0xe8, 0x28, 0x28, 0x28, 0x28},
  {0x00, 0x00, 0x00, 0xf8, 0x28, 0x28, 0x28, 0x28},
  {0x00, 0x00, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10},
  {0x28, 0x28, 0xe8, 0x08, 0xe8, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28},
  {0x00, 0x00, 0xf8, 0x08, 0xe8, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0xe8, 0x08, 0xf8, 0x00, 0x00, 0x00},
  {0x28, 0x28, 0x28, 0xf8, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0xf0, 0x10, 0xf0, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x10, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0xff, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10},
  {0x28, 0x28, 0x28, 0x2f, 0x28, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0x2f, 0x20, 0x3f, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x3f, 0x20, 0x2f, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0xef, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0xff, 0x00, 0xef, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0x2f, 0x20, 0x2f, 0x28, 0x28, 0x28},
  {0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x28, 0x28, 0xef, 0x00, 0xef, 0x28, 0x28, 0x28},
  {0x10, 0x10, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x28, 0x28, 0x28, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0xff, 0x00, 0xff, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0xff, 0x28, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0x28, 0x3f, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0x3f, 0x28, 0x28, 0x28, 0x28},
  {0x28, 0x28, 0x28, 0xff, 0x28, 0x28, 0x28, 0x28},
  {0x10, 0x10, 0xff, 0x10, 0xff, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x10},
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
  {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff},
  {0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0},
  {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f},
  {0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x34, 0x48, 0x48, 0x48, 0x34, 0x00},
  {0x00, 0x30, 0x48, 0x50, 0x48, 0x44, 0x5c, 0x40},
  {0x00, 0x7c, 0x44, 0x40, 0x40, 0x40, 0x40, 0x00},
  {0x00, 0x00, 0x7c, 0x28, 0x28, 0x28, 0x28, 0x00},
  {0x7c, 0x44, 0x20, 0x10, 0x20, 0x44, 0x7c, 0x00},
  {0x00, 0x00, 0x3c, 0x48, 0x48, 0x48, 0x30, 0x00},
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x78, 0x40, 0x40},
  {0x00, 0x34, 0x58, 0x10, 0x10, 0x14, 0x08, 0x00},
  {0x38, 0x10, 0x38, 0x44, 0x44, 0x38, 0x10, 0x38},
  {0x38, 0x44, 0x44, 0x7c, 0x44, 0x44, 0x38, 0x00},
  {0x38, 0x44, 0x44, 0x44, 0x44, 0x28, 0x6c, 0x00},
  {0x78, 0x20, 0x18, 0x24, 0x44, 0x44, 0x38, 0x00},
  {0x00, 0x00, 0x28, 0x54, 0x54, 0x28, 0x00, 0x00},
  {0x00, 0x04, 0x28, 0x54, 0x54, 0x28, 0x40, 0x00},
  {0x00, 0x00, 0x3c, 0x40, 0x38, 0x40, 0x3c, 0x00},
  {0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x40},
  {0x00, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x7c, 0x00},
  {0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x38, 0x00},
  {0x20, 0x10, 0x08, 0x10, 0x20, 0x00, 0x38, 0x00},
  {0x08, 0x10, 0x20, 0x10, 0x08, 0x00, 0x38, 0x00},
  {0x0c, 0x12, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60},
  {0x00, 0x00, 0x10, 0x00, 0x7c, 0x00, 0x10, 0x00},
  {0x00, 0x00, 0x32, 0x4c, 0x00, 0x32, 0x4c, 0x00},
  {0x00, 0x18, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
  {0x00, 0x0f, 0x08, 0x08, 0x08, 0x48, 0x28, 0x18},
  {0x30, 0x2c, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00},
  {0x18, 0x08, 0x10, 0x3c, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};