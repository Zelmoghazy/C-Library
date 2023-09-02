CC=gcc

OPT=-O0
DBG=-g
WARNINGS=-Wall -Wextra -Wsign-conversion -Wconversion
INCS=$(foreach DIR,$(INC_DIRS),-I$(DIR))
DEPFLAGS=-MP -MD
CFLAGS=$(DBG) $(OPT) $(INCS) $(WARNINGS) $(DEPFLAGS)

INC_DIRS=. ./include/
BUILD_DIR=build
CODE_DIRS=. src
VPATH=$(CODE_DIRS)
LIB=

SRC=$(foreach DIR,$(CODE_DIRS),$(wildcard $(DIR)/*.c))

OBJ=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.o)))
DEP=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.d)))


PROJ=Main

all: $(BUILD_DIR)/$(PROJ).exe
	@echo "========================================="
	@echo "              BUILD SUCCESS              "
	@echo "========================================="

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@ 
$(BUILD_DIR)/$(PROJ).exe: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

$(BUILD_DIR):
	mkdir $@
	$(info SRC_DIRS : $(CODE_DIRS))
	$(info INC_DIRS : $(INC_DIRS))
	$(info INCS     : $(INCS))
	$(info SRC_FILES: $(SRC))
	$(info OBJ_FILES: $(OBJ))
	@echo "========================================="

clean:
	rm -fR $(BUILD_DIR)

-include $(DEP)

.PHONY: all clean
