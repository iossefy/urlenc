CC=gcc
FLAGS=-Wall -s -O3

RM=rm -rf
CP=cp -r

BUILD=./build
INSTALL_PATH=~/.local/bin

MKDIR=mkdir -p -v

SRC=doc.c  doc.h  urldec.c  urldec.h  urlenc.c  util.c  util.h

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
