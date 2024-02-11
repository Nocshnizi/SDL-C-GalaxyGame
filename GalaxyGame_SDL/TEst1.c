#include <stdio.h>

typedef struct sprite_s {
    int x;
    int y;
    int h;
    int w;
} sprite_t;

void init_sprite(sprite_t *sprite, int x, int y, int w, int h) {
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

void print_sprite(sprite_t *sprite) {
    printf("x: %d, y: %d, w: %d, h: %d\n", sprite->x, sprite->y, sprite->w, sprite->h);
}

void test_init_sprite_param(int x, int y, int w, int h) {
    sprite_t sprite;
    init_sprite(&sprite, x, y, w, h);
    print_sprite(&sprite);
}

void test_init_sprite() {
    // Test 1
    test_init_sprite_param(0, 0, 32, 32);
    
    // Test 2
    test_init_sprite_param(10, 20, 64, 64);
    
    // Test 3
    test_init_sprite_param(-5, -5, 16, 16);
}

int main() {
    test_init_sprite();
    return 0;
}