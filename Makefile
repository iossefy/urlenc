CC=gcc
FLAGS=-Wall -s -O3

RM=rm -rf
CP=cp -r

BUILD=./build/
INSTALL_PATH=~/.local/bin

MKDIR=mkdir -p -v

E_SRC=urlenc.c util.c
D_SRC=urldec.c util.c

TARGET_E=urlenc
TARGET_D=urldec

compile: dir urlenc urldec
	@echo "to install run: make install"

install:
	$(CP) $(BUILD)/$(TARGET_E) $(INSTALL_PATH)/$(TARGET_E)
	$(CP) $(BUILD)/$(TARGET_D) $(INSTALL_PATH)/$(TARGET_D)

dir:
	$(MKDIR) $(BUILD)

urlenc:
	$(CC) $(FLAGS) $(E_SRC) -o $(BUILD)$(TARGET_E)

urldec:
	$(CC) $(FLAGS) $(D_SRC) -o $(BUILD)$(TARGET_D)

clean:
	$(RM) $(BUILD)
