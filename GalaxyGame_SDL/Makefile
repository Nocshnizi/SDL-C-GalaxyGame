CFLAGS =  -O3 -Dmain=SDL_main
LDFLAGS = -lm -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -L C:\MinGW\lib\gcc\mingw32\6.3.0 -L C:\sdlmingw32\lib
SDL2_INCLUDE_DIR = C:\sdlmingw32\include
SDL2_LIBRARIES_DIR = C:\sdlmingw32\lib

INC = sdl2-light.h logic.h graphic.h sdl-ttf.h 
SRC = main.c sdl2-light.c logic.c graphic.c sdl-ttf.c
OBJ = $(SRC:%.c=%.o)

PROG = spacecorridor.exe

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<  -I $(SDL2_INCLUDE_DIR)

$(PROG): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@ -L $(SDL2_LIBRARIES_DIR)

doc: $(PROG)
	doxygen $(PROG)

.PHONY: clean
clean:
	del /f /q *.o *~ $(PROG)
	rd /s /q latex html
