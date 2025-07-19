TARGET_EXEC := zore80

CC := gcc

CFLAGS := -Wall -Wextra -std=c99 -g
ASFLAGS :=

SRC_DIRS := ./src
BUILD_DIR := ./build

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: all clean exec

clean:
	rm -rf $(BUILD_DIR)

exec: $(BUILD_DIR)/$(TARGET_EXEC)
	./$<

-include $(DEPS)
