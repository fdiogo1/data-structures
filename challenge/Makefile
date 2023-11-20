APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src
DIR = C:\Users\Admin\Desktop\Estrutura de Dados\codes\desafios

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB) 

all: libed myapps 

libed: $(OBJ)/lists.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.*

myapps: cleanapps \
	$(BIN)/main

run:
	$(BIN)/main.exe

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

clean:
	del /q "$(DIR)\obj\*.*"
	del /q "$(DIR)\bin\*.*"
	del /q "$(DIR)\lib\*.*"
cleanapps:
	del /q "$(DIR)\bin\*.*"