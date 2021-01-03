/*uint8_t thinkingImg[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x62, 0xee, 0x4a, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xa8, 0x40, 0x00, 
0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x0b, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0x00, 0x3b, 0xff, 0xa0, 0x0f, 0xff, 0xd0, 0x00, 
0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xfe, 0x20, 0x1f, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x07, 0xc1, 0x29, 0xa3, 0x0a, 0x10, 0x3f, 0xff, 0xf0, 0x00, 
0x00, 0x01, 0xff, 0xff, 0xff, 0xef, 0x5c, 0x1f, 0xdf, 0xff, 0xe0, 0x00, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xf8, 0x00, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf0, 0x00, 
0x00, 0x0f, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x00, 
0x00, 0x02, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x17, 0xe7, 0x3f, 0xff, 0xff, 0xaf, 0x7f, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x3f, 0xc0, 0x33, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x5f, 0x02, 0x07, 0xff, 0xff, 0xa0, 0x3f, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0xfe, 0x5c, 0x31, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xe0, 0x00, 
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xf0, 0x00, 
0x00, 0x03, 0xff, 0xfd, 0xff, 0xfe, 0x7f, 0xfc, 0x03, 0xed, 0xe0, 0x00, 
0x00, 0x03, 0xff, 0xfa, 0x7f, 0xd7, 0xcf, 0xfe, 0x03, 0xc3, 0xf0, 0x00, 
0x00, 0x01, 0xff, 0xf0, 0xbf, 0x80, 0x01, 0xfe, 0x00, 0x02, 0xf0, 0x00, 
0x00, 0x07, 0xff, 0xf0, 0x3f, 0xcc, 0x31, 0xfc, 0x00, 0x00, 0xf8, 0x00, 
0x00, 0x03, 0xff, 0xe0, 0x3f, 0xec, 0x1f, 0xfe, 0x00, 0x00, 0xf8, 0x00, 
0x00, 0x07, 0xff, 0xf0, 0x7f, 0xf8, 0x0e, 0xff, 0x00, 0x00, 0x78, 0x00, 
0x00, 0x07, 0xff, 0xe0, 0x3f, 0xf8, 0x2f, 0xff, 0x00, 0x00, 0x7c, 0x00, 
0x00, 0x07, 0xff, 0xe8, 0xbf, 0xf8, 0x2f, 0xff, 0x80, 0x00, 0x7c, 0x00, 
0x00, 0x07, 0xff, 0xf9, 0x7f, 0xf8, 0x3f, 0xff, 0x80, 0x00, 0x3e, 0x00, 
0x00, 0x0f, 0xff, 0xfd, 0xff, 0xf8, 0x5f, 0xff, 0x80, 0x00, 0x7c, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xfd, 0x7f, 0xff, 0x00, 0x00, 0x3c, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3c, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7c, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3e, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0x00, 
0x00, 0x0f, 0xff, 0xe7, 0xca, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0x00, 
0x00, 0x0f, 0xff, 0xff, 0xc1, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x3e, 0x00, 
0x00, 0x0f, 0xff, 0xfb, 0x9c, 0x07, 0xff, 0xff, 0x00, 0x00, 0x3e, 0x00, 
0x00, 0x0f, 0xff, 0xbd, 0xd8, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x3e, 0x00, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x03, 0xff, 0xbf, 0xff, 0xf7, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xfe, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x03, 0xfe, 0xff, 0xff, 0xe7, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x02, 0xff, 0xfd, 0xf7, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x3e, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf0, 0x00, 0x00, 0x1e, 0x00, 
0x00, 0x00, 0xf7, 0xff, 0xff, 0xff, 0x3f, 0xf8, 0x00, 0x00, 0x3e, 0x00, 
0x00, 0x00, 0xb7, 0xff, 0xff, 0xee, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xfe, 0x1f, 0xff, 0xd0, 0x00, 0x00, 0x7c, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xfe, 0xff, 0xff, 0xa0, 0x00, 0x01, 0xfe, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0xf8, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x03, 0xf4, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x0b, 0xf0, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x0f, 0xe0, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xcf, 0xf2, 0x00, 0x3f, 0xd0, 0x00, 
0x00, 0x00, 0x3f, 0xff, 0xff, 0x7e, 0xa7, 0xfe, 0xff, 0x7f, 0xa0, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xff, 0x7c, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0x2f, 0xff, 0xfe, 0x18, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xfd, 0x00, 0x00, 0xff, 0xff, 0xf6, 0x00, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x6f, 0xff, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x0b, 0xff, 0xff, 0x00, 0x00, 0x07, 0x76, 0x40, 0x00, 0x00, 
0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x06, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0xc0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};*/

uint8_t testImg[] = {0x00,0xFF,0x00,
                    0xFF,0x00,0xFF,
                    0x00,0xFF,0x00};