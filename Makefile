# Compiler
CC = gcc

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
BUILD_DIR = build

# Common compile flags
CFLAGS = -Wall -Wextra -g -I$(INC_DIR)

# Detect OS
ifeq ($(OS),Windows_NT)
    # ---- WINDOWS SETTINGS ----
    DLL_EXT = dll
    EXE_EXT = exe
    RM = del /Q
    OUT = $(BUILD_DIR)/app.$(EXE_EXT)
    DLL = $(BUILD_DIR)/mylib.$(DLL_EXT)
    LDFLAGS =
else
    # ---- LINUX SETTINGS ----
    DLL_EXT = so
    EXE_EXT = out
    RM = rm -f
    OUT = $(BUILD_DIR)/app.$(EXE_EXT)
    DLL = $(BUILD_DIR)/libmylib.$(DLL_EXT)
    LDFLAGS = -ldl
endif

# Sources
LIST_SRC = $(SRC_DIR)/list.c
ITER_SRC = $(SRC_DIR)/iter.c
TEST_SRC = $(TEST_DIR)/test.c

# Objects
LIST_OBJ = $(BUILD_DIR)/list.o
ITER_OBJ = $(BUILD_DIR)/iter.o
TEST_OBJ = $(BUILD_DIR)/test.o

# Default
all: dirs $(DLL) $(OUT)

dirs:
	mkdir -p $(BUILD_DIR)

# ------- Build DLL / SO -------
$(DLL): $(LIST_OBJ) $(ITER_OBJ)
	$(CC) -DBUILDING_DLL -shared $(LIST_OBJ) $(ITER_OBJ) -o $(DLL)

# ------- Build objects -------
$(LIST_OBJ): $(LIST_SRC) $(INC_DIR)/list.h
	$(CC) $(CFLAGS) -c $(LIST_SRC) -o $(LIST_OBJ)

$(ITER_OBJ): $(ITER_SRC) $(INC_DIR)/iter.h
	$(CC) $(CFLAGS) -c $(ITER_SRC) -o $(ITER_OBJ)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

# ------- Build executable -------
$(OUT): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -L$(BUILD_DIR) -lmylib -o $(OUT) $(LDFLAGS)

# ------- Clean -------
clean:
	$(RM) $(BUILD_DIR)/*
