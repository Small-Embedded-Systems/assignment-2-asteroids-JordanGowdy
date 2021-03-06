/* Asteroids View */

/* support double buffering */
void init_DBuffer(void);
void swap_DBuffer(void);

void draw(void);

#define rock1_width 15
#define rock1_height 15
static char rock1_bits[] = {
  0x00, 0x00, 0xC0, 0x1B, 0x40, 0x1E, 0x60, 0x10, 0x30, 0x30, 0x1C, 0x26, 
  0x04, 0x26, 0x04, 0x30, 0x02, 0x10, 0x02, 0x10, 0x46, 0x30, 0x04, 0x20, 
  0x0C, 0x38, 0x90, 0x0F, 0xF0, 0x00, };

	


#define rock2_width 20
#define rock2_height 20
static char rock2_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0xC0, 0x1F, 0x03, 0x70, 0x00, 0x06, 
  0x1C, 0x00, 0x06, 0x06, 0x78, 0x06, 0x02, 0x4E, 0x04, 0x02, 0x62, 0x04, 
  0x02, 0x66, 0x06, 0x06, 0x24, 0x03, 0x04, 0xBC, 0x01, 0x04, 0x80, 0x00, 
  0x04, 0x80, 0x01, 0x04, 0x00, 0x03, 0x0C, 0x00, 0x02, 0x08, 0x00, 0x02, 
  0x08, 0x00, 0x03, 0x18, 0xFF, 0x01, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 
};
	
	


	
#define bigrock_width 70
#define bigrock_height 70
static char bigrock_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x7F, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 
  0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xC0, 
  0x1F, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x08, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 
  0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x20, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1E, 0x00, 0x00, 0x20, 0x00, 
  0x00, 0x00, 0x9C, 0x03, 0x06, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x06, 
  0x02, 0x04, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x06, 0x02, 0x04, 0x00, 
  0x00, 0x0C, 0x00, 0x00, 0x00, 0x06, 0x02, 0x3C, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0x00, 0x0C, 0x02, 0x60, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1C, 
  0x03, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x40, 0x00, 
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x08, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x08, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x00, 0x08, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x40, 0x00, 
  0x00, 0x08, 0x00, 0x31, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x08, 0x00, 
  0x61, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0xC7, 0x01, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x04, 0x07, 0x00, 0x00, 0x20, 0x00, 
  0x00, 0x30, 0x00, 0x04, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x60, 0x00, 
  0x04, 0x06, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x00, 0x18, 0x03, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x80, 0x03, 0xF0, 0x01, 0x00, 0x00, 0x20, 0x00, 
  0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
  0x00, 0x1F, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 
  0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x40, 
  0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
