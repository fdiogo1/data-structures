#maneiras de evitar ter que alterar em cmd por cmd quando houver mudança de diretórios
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src
DIR = C:\Users\Admin\Desktop\Estrutura de Dados\codes\projects

# -O3 é uma otimização, tenta melhorar a performance de loops... Otimiza o código fonte na hora de gerar o binário
# -Wall = mostra todos os warnings (não necessariamente um erro, irá compilar mesmo assim, mas é importante tratar todos os possíveis)
FLAGS = -O3 -Wall
LIBS = -led -L $(LIB) # -l<libed>, vai ignorar o lib, pois já sabe que é uma biblioteca, então, -led

# quando eu der make, ele irá chamar automaticamente as flags libed e myapps
# que são dependencias (a ordem é importante!)
all: libed myapps 

# o \ é utilizado para poder pular linhas, ele ignora o enter e lê o próximo #
# o ar -rcs junta tudo em um arquivo só, cria uma BIBLIOTECA ESTÁTICA
libed: $(OBJ)/float_vector.o \
	$(OBJ)/linked_list.o \
	$(OBJ)/double_linked_list.o \
	$(OBJ)/circular_lists.o \
	$(OBJ)/static_stack.o \
	$(OBJ)/stack.o \
	$(OBJ)/static_queue.o \
	$(OBJ)/queue.o \
	$(OBJ)/mlibs.o \
	$(OBJ)/hashtable.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.*


myapps: cleanapps \
	$(BIN)/app \
	$(BIN)/app1_lists \
	$(BIN)/app2_lists \
	$(BIN)/app3_lists \
	$(BIN)/app4_stack \
	$(BIN)/app5_stack \
	$(BIN)/app6_queue \
	$(BIN)/app7_queue \
	$(BIN)/app8 \
	$(BIN)/hashApp

run:
	$(BIN)/hashApp.exe

#para ganhar tempo, só irá compilar a biblioteca novamente caso não haja um arquivo .o gerado na pasta
#ou então, caso tenha havido alguma alteração recente em um dos seus arquivos de dependencia
#o $@ chama toda a flag passada, por isso não há necessidade de por o $(OBJ) novamente depois do -o

#diretiva genérica p/ compilação das TADs, arquivos objetos
# "o arquivo .h é o manual, o .o é a caixa de ferramentas"


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

# diretiva genérica p/ compilação dos programas executáveis
# -led = indico que quero utilizar uma biblioteca específica, no meu caso, 
# a libed.a. No caso, ele já sabe que é uma lib, então o "lib" do "libed" é ignorado
# por isso, apenas -led, e utilizo -L $(LIB) para indicar onde ela está

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

clean:
	del /q "$(DIR)\obj\*.*"
	del /q "$(DIR)\bin\*.*"
	del /q "$(DIR)\lib\*.*"
cleanapps:
	del /q "$(DIR)\bin\*.*"