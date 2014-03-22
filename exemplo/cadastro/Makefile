CC = $(CROSS)gcc

SOURCES ?= $(wildcard src/*.c)
OBJS    ?= $(addprefix , $(SOURCES:.c=.o))

CFLAGS += -fno-strict-aliasing
CFLAGS += -Iinclude/ 
CFLAGS += -DDEBUG=0

TARGET := cadastro

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "BINARY $@"
	@$(CC) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): %.o: %.c
	@echo "CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "RM $(TARGET) $(OBJS)"
	@rm -rf $(TARGET) $(OBJS) *.o *~ *bak src/*.gc*
	@make -C test/ clean

test: clean
	@echo "TEST"
	@make -C test/

coverage: test
	@echo "Code Coverage(lcov)"
	@lcov --directory . --capture --output-file test/stap.info
	@lcov --remove test/stap.info "/usr*" -o test/stap.info
	@genhtml -o ./test/coverage ./test/stap.info
	@echo "Coverage at $(TARGET) created, please open ./test/coverage/index.html"

