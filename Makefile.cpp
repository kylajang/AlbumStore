CC := g++
CFLAGS := -Wall -pedantic --std=c++17

# Variables
	PART1_EXE_NAME := lab7-main.bin
	PART1_EXE_PATH := ./$(PART1_EXE_NAME)

# Targets

lab7-main.bin:
	@echo Bulding $@
	$(CC) $(CFLAGS) main.cpp -o $@ \
		&& chmod +x $@

lab7-main:	lab7-main.bin
	$(PART1_EXE_PATH)
