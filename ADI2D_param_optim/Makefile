# Makefile du Projet: sonde
#
CC   = gcc -g -std=gnu11

BIN  = ADI2D
LIBS =  -L/usr/X11R6/lib -lX11 -lXext -lm
INCS =  -I. -I/usr/X11R6/include 

SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))
DEPENDS := $(patsubst %.c,%.d,$(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same
all:  $(BIN)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(BIN)

# Linking the executable from the object files
$(BIN): $(OBJECTS)
	$(CC) $(INCS) $(WARNING) $(CFLAGS) $^ -o $@ $(LIBS)

-include $(DEPENDS)

%.o: %.c Makefile
	$(CC) $(INCS) $(WARNING) $(CFLAGS) -MMD -MP -c $< -o $@
