CC=gcc
EXT=c

OPT=
DBG=
WARNINGS=-Wall -Wextra -Wsign-conversion -Wconversion
DEPFLAGS=-MP -MD

INCS=$(foreach DIR,$(INC_DIRS),-I$(DIR))
LIBS=$(foreach DIR,$(LIB_DIRS),-L$(DIR))
LIBS+=

CFLAGS=$(DBG) $(OPT) $(INCS) $(LIBS) $(WARNINGS) $(DEPFLAGS)

INC_DIRS=. ./inc/
LIB_DIRS=
BUILD_DIR=build
CODE_DIRS=. src
VPATH=$(CODE_DIRS)

SRC=$(foreach DIR,$(CODE_DIRS),$(wildcard $(DIR)/*.$(EXT)))

OBJ=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.$(EXT)=.o)))
DEP=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.$(EXT)=.d)))

EXEC=Main.exe

all: $(BUILD_DIR)/$(EXEC)
	@echo "========================================="
	@echo "              BUILD SUCCESS              "
	@echo "========================================="

release: OPT += -O2 
release: all

debug: DBG += -g -gdwarf-2
debug: OPT += -O0
debug: all

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c  $< -o $@ $(CFLAGS)
$(BUILD_DIR)/$(EXEC): $(OBJ)
	$(CC)  $^ -o $@ $(CFLAGS)

$(BUILD_DIR):
	mkdir $@
	$(info SRC_DIRS  : $(CODE_DIRS))
	$(info INC_DIRS  : $(INC_DIRS))
	$(info INCS      : $(INCS))
	$(info SRC_FILES : $(SRC))
	$(info OBJ_FILES : $(OBJ))
	@echo "========================================="

clean:
	rm -fR $(BUILD_DIR)

-include $(DEP)

.PHONY: all clean release debug
