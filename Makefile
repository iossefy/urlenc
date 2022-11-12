CC=gcc
FLAGS=-Wall -s -O3

RM=rm -rf
CP=cp -r

BUILD=./build
INSTALL_PATH=~/.local/bin

MKDIR=mkdir -p -v

SRC=*.c

TARGET=urlenc

compile: dir urlenc
	@echo "Done compiling"

all: compile install

install:
	$(CP) $(BUILD)/$(TARGET) $(INSTALL_PATH)/$(TARGET)
	@echo "Done installing"

dir:
	$(MKDIR) $(BUILD)

.PHONY: urlenc
urlenc:
	$(CC) $(FLAGS) $(SRC) -o $(BUILD)/$(TARGET)

.PHONY: clean
clean:
	$(RM) $(BUILD)
