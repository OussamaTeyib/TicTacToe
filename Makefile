CC = gcc
CFLAGS = -g -std=c2x -Wall -Wextra -Werror

SRC_DIR = src
BIN_DIR = bin

$(BIN_DIR)/xo: $(SRC_DIR)/xo.c
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/xo $(SRC_DIR)/xo.c

.PHONY: push clear

push:
	@git add .
	@git commit -m "$(msg)"
	@git push origin main
clear:
	@rm -r bin