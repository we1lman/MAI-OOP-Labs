.PHONY: all build run test clean

BUILD_DIR = build

MAIN_EXEC = main_lab3
TEST_EXEC = tests_lab3

CMAKE = cmake
MAKE = make
RM = rm -rf

all: build

build:
	@echo "Создание директории сборки..."
	$(CMAKE) -S . -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)

run: build
	@echo "Запуск основного приложения..."
	./$(BUILD_DIR)/$(MAIN_EXEC)

test: build
	@echo "Запуск тестов..."
	./$(BUILD_DIR)/$(TEST_EXEC)

clean:
	@echo "Очистка директории сборки..."
	$(RM) $(BUILD_DIR)
