CPP=g++

ALL_C	:= $(wildcard ../src/*.c)
ALL_CPP	:= $(wildcard *.cpp)

SOURCES	:= $(filter-out %main.c,$(ALL_C))
OBJS	:= $(addprefix , $(SOURCES:.c=.o))
OBJS	+= $(addprefix , $(ALL_CPP:.cpp=.o))

CFLAGS	+= -fprofile-arcs -ftest-coverage
CFLAGS  += -I../include 

LDFLAGS += -lgtest -lgcov -lpthread -lgtest_main

TARGET := json_test

#
#	make all
#
all: $(TARGET)
        
$(TARGET): $(OBJS)
	@echo "[BIN] $@"
	@$(CPP) $^ $(LDFLAGS) -o $@
	@./$(TARGET)

%.o: %.c
	@echo "[CPP] $@"
	@$(CPP) $(CFLAGS) -o $@ -c $<
        
%.o: %.cpp
	@echo "[CPP] $@"
	@$(CPP) $(CFLAGS) -o $@ -c $<

clean:
	@echo "rm -rf $(OBJS)"
	@rm -rf $(OBJS) $(TARGET) ../src/*.gc* *.gc*

format:
	@astyle --style=linux -t4 -n $(ALL_C)
	@astyle --style=linux -t4 -n $(ALL_CPP)
