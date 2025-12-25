# Variables
CC = gcc
DEBUG_FLAGS = -Wall -Wextra -g -fsanitize=undefined,address
BUILDFLAGES = -shared
LIBS = lib/bigint.c  # Ajoutez ici vos fichiers de librairie
TESTS = tests/main.c   # Ajoutez ici vos fichiers de test

# Cibles par défaut
all: build test

# Instruction de build pour compiler les librairies
build:
	echo $(CC) $(BUILDFLAGES) $(LIBS)

# Instruction pour compiler et lancer les tests
test:
	$(CC) $(DEBUG_FLAGS) $(LIBS) $(TESTS) -o test_runner
	./test_runner

# Instructions de nettoyage
clean:
	rm -f *.o *.so test_runner