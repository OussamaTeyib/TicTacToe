CC = gcc
CFLAGS = -g -std=c2x -Wall -Wextra -Werror

SRC_DIR = src
BIN_DIR = bin

$(BIN_DIR)/xo: $(SRC_DIR)/xo.c
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/xo $(SRC_DIR)/xo.c

.PHONY: push clean

push:
	@git add .
	@git commit -m "$(msg)"
	@git push origin main

clean:
	@rm -r bin