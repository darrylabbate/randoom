INSTALL_DIR := /usr/local/bin
OUT_NAME    := randoom

all: install

install:
	$(CC) randoom.c -o $(OUT_NAME)
	install $(OUT_NAME) $(INSTALL_DIR)
	rm $(OUT_NAME)

uninstall:
	rm $(INSTALL_DIR)/$(OUT_NAME)
