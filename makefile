# Cible par défaut
all: build

# Dossier pour les fichiers objets
OBJDIR = obj
SRCDIR = src
INCDIR = include

# Chemins
SRC_DIRS = $(shell find $(SRCDIR) -type d)
INC_DIRS = $(shell find $(INCDIR) -type d | sed 's/^/-I/')

# Compilation
CFLAGS = $(INC_DIRS) -lncurses -lm
TARGET = donut

# Fichiers à compler
SRC = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.c))
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))


# Création du dossier obj si nécessaire
$(shell mkdir -p $(OBJDIR))


# Règle pour nettoyer le projet
clean:
	rm -rf $(OBJDIR) donut


# Règle pour construire le projet
build: $(OBJ)
	@echo "Construction du projet..."
	gcc $(OBJ) $(CFLAGS) -o donut



# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compilation de $<..."
	gcc -c $(CFLAGS) $< -o $@