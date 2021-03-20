include CONFIG.cfg

CC = gcc
LD = gcc

EXEC_FILE = $(BUILD_DIR)/$(NAME)
OBJECTS = $(BUILD_DIR)/sorter.o $(BUILD_DIR)/handler.o $(BUILD_DIR)/confirm.o
CHECKS = $(patsubst $(TEST_DIR)/%.in, $(TEST_DIR)/%.log, $(wildcard $(TEST_DIR)/*.in))

.PHONY: all check clean


all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

check: $(CHECKS)
	@for n in $^; \
	do \
  		if echo 2 | cmp -s $$n; then \
 	  		exit 2; \
  	  	fi; \
	done

$(CHECKS): $(TEST_DIR)/%.log: $(TEST_DIR)/%.in $(TEST_DIR)/%.out $(EXEC_FILE)
	@if $(EXEC_FILE) $< | cmp -s $(TEST_DIR)/$*.out; then \
		echo Test $* - was successful; \
		echo 1 > $@; \
	else \
		echo Test $* - was failed; \
		echo 2 > $@; \
	fi


clean:
	$(RM) $(EXEC_FILE) $(OBJECTS) $(CHECKS)
