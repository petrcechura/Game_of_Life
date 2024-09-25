
PRO_FILE=./build/Game_of_Life.pro
SRC_DIR=./src
BUILD_DIR=./build
BIN_DIR=./bin
MAKEFILE_DIR=./build/

.PHONY: all
all: build qmake compile


.PHONY: build
build:
	@mkdir $(BUILD_DIR)
	@echo "QT += core gui" > $(PRO_FILE) 
	@echo "greaterThan(QT_MAJOR_VERSION, 4): QT += widgets" >> $(PRO_FILE)
	@echo "CONFIG += c++17\n\n" >> $(PRO_FILE)
	@echo "SOURCES += $(shell for file in $(SRC_DIR)/cpp/*; do realpath "$$file \\ \n "; done)" >> $(PRO_FILE)
	@echo "HEADERS += $(shell for file in $(SRC_DIR)/h/*; do realpath "$$file \\ \n"; done)"   >> $(PRO_FILE)
	@echo "INCLUDEPATH += $(realpath $(SRC_DIR))/cpp/ $(realpath $(SRC_DIR))/h/" >> $(PRO_FILE)
	@echo "\n\nqnx: target.path = /tmp/$${TARGET}/bin" >> $(PRO_FILE)
	@echo "else: unix:!android: target.path = /opt/$${TARGET}/bin" >> $(PRO_FILE)
	@echo "!isEmpty(target.path): INSTALLS += target" >> $(PRO_FILE)

.PHONY: qmake
qmake: 
	@qmake $(PRO_FILE) -o $(MAKEFILE_DIR)

.PHONY: compile
compile:
	@mkdir $(BIN_DIR)
	@(cd $(MAKEFILE_DIR) && make)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm $(PRO_FILE)

