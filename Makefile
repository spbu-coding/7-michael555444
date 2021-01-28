#include CONFIG.cfg
#
#CC = gcc
#LD = gcc -lm
#EXEC_FILE = $(BUILD_DIR)/$(NAME)
#SRC_FILE = $(SOURCE_DIR)/$(NAME).c
#OBJS = $(EXEC_FILE).o
#
#
#SRCS := $(wildcard *.c)
#
#.PHONY: all clean check
#
#all: $(EXEC_FILE)
#
#$(BUILD_DIR) :
#	@mkdir $@
#
#$(EXEC_FILE) : $(OBJS) | $(BUILD_DIR)
#	$(CC) $^ -o $@
#
#$(OBJS) : $(BUILD_DIR)/%.o:
#
#
#clean:
#	$(RM) $(OBJS) $(BUILD_DIR)
#
#check:
#

include CONFIG.cfg

CC = gcc
LD = gcc
CFLAGS =
CPPFLAGS =
LDFLAGS =

INPUT_FILE_TYPE = in
OUTPUT_FILE_TYPE = out
LOG_FILE_TYPE = log

EXEC = $(BUILD_DIR)/$(NAME)
OBJECTS = $(BUILD_DIR)/sorter.o $(BUILD_DIR)/handler.o $(BUILD_DIR)/validate.o
DEPS = $(OBJECTS:.o=.d)
LOGS = $(patsubst $(TEST_DIR)/%.$(INPUT_FILE_TYPE), $(TEST_DIR)/%.$(LOG_FILE_TYPE), $(wildcard $(TEST_DIR)/*.$(INPUT_FILE_TYPE)))

.PHONY: all check clean


all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(EXEC) $(OBJECTS) $(DEPS) $(MAIN_LOG) $(LOGS)
