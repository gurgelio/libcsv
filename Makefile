shared_object = libcsv.so
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)

tests = $(wildcard test/t_*.c)
test_objects = $(tests:.c=.o)

compiler = gcc
flags = -g -fPIC -Wall -Wextra

$(shared_object): $(objects)
	$(compiler) $(flags) -shared $^ -o $@

%.o: %.c include/%.h
	$(compiler) -c $(flags) $< -o $@

test_runner: $(objects) $(test_objects)
	$(compiler) $(flags) $^ -o $@

runtest: test_runner
	@./test_runner 2>> test.log

clean:
	-rm -f $(shared_object) $(objects) test_runner $(test_objects)
	-cd test; make -B clean