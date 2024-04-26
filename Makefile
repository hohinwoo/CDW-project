# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -c
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Directories
SRCDIR = src
INCDIR = include
RESDIR = res
LIBDIR = lib

# Include and library paths
INCLUDES = -I$(INCDIR) -I$(RESDIR)
LIBS = -L$(LIBDIR)

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.c, %.o, $(SOURCES))

# Executable name
EXECUTABLE = myprogram.exe

# Default target
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(LDFLAGS) -o $@

# Compilation
%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean