SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,build/%.o,$(SRC))

TARGET := build/kbfc

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc $^ -o $@

build/%.o: src/%.c
	mkdir -p $(@D)
	gcc -c $< -o $@

clean:
	rm -fr build

