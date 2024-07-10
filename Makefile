shared_object = libcsv.so
executable = libcsv.out
sources = $(wildcard src/*.c) $(wildcard src/*/*.c)
objects = $(sources:.c=.o)
flags = -lm -g -fPIC -Wall -Wextra -ggdb3

$(shared_object): $(objects)
	gcc $(flags) -shared $^ -o $@

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

test: $(objects)
	gcc $(flags) $^ -o $(executable) && ./$(executable)

clean:
	rm -f $(executable) $(shared_object) $(objects)