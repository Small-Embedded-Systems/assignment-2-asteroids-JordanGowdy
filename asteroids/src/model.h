/* Asteroids Model */
struct point {
    float x,y;
};
typedef struct point coordinate_t;
typedef struct point vector_t;

/* Some insitial struct types if you want to usd them */
struct ship {
	  float heading;
    coordinate_t p;
    vector_t     v;
		int resetTime;
};

/* initial struts for building linked lists */
struct rock {
    coordinate_t p;
		int type;
	  int height;
	  int rockPic;
	  int width;
	  int lifetime;
		bool hit;
	  float heading;
    struct rock *next;
};

struct missile {
	  float heading;
    coordinate_t p;
		int lifetime;
		bool hit;
    struct missile *next;
};

void physics(void);
