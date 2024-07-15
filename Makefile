shared_object = libcsv.so
executable = libcsv.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
compiler = gcc
flags = -g -fPIC -Wall -Wextra

$(shared_object): $(objects)
	$(compiler) $(flags) -shared $^ -o $@

%.o: %.c include/%.h
	$(compiler) -c $(flags) $< -o $@

test: $(objects)
	$(compiler) $(flags) $^ -o $(executable) && ./$(executable)

clean:
	rm -f $(executable) $(shared_object) $(objects)