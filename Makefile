include CONFIG.cfg

CC = gcc
LD = gcc

INPUT_FILE_TYPE = in
OUTPUT_FILE_TYPE = out

EXEC_FILE = $(BUILD_DIR)/$(NAME)
OBJECTS = $(BUILD_DIR)/sorter.o $(BUILD_DIR)/handler.o $(BUILD_DIR)/validate.o
DEPENDENCE = $(OBJECTS:.o=.d)

.PHONY: all clean


all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(EXEC_FILE) $(OBJECTS) $(DEPS) $(MAIN_LOG)
