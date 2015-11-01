#type du projet
TYPE = algebre

#Nom de lexecutable :
NAME = ft_sh

# Choix du compilateur :
CC = clang

DIR_LIB = ./Libs

INC  =   -I $(DIR_LIB)/libft/Include/
LIB  =   -L $(DIR_LIB)/libft/ -lft
INC +=   -I $(DIR_LIB)/libftprintf/Include/
LIB +=   -L $(DIR_LIB)/libftprintf/  -lftprintf
INC +=   -I $(DIR_LIB)/libftstream/Include/
LIB +=   -L $(DIR_LIB)/libftstream/  -lftstream
#LIB  += -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  += -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

# Options
CFLAGS += -g -O0 -Werror -Wextra -Wall -I ./Includes/ $(INC)

ifeq ($(TYPE), graphique)
	LIB  += -framework OpenGL -framework AppKit -LLibs/minilibx_macos -lmlx
endif

# -------------------------------------------------------------------
#  Emplacement des sources et des objets, des includes et de lexecutable
# -------------------------------------------------------------------

# Dossier racine du code :
CODE :=.

# dossier de lexecutable
EXEDIR := $(CODE)/Bin

# Adresse des sources, des objets et des includes :
SRCDIR = $(CODE)/Srcs
OBJDIR = $(CODE)/Objets
INCDIR = $(CODE)/Includes

BUILTIN_DIR = $(SRCDIR)/Builtin
ERROR_DIR = $(SRCDIR)/Error
EXEC_DIR = $(SRCDIR)/Execution
PARSE_DIR = $(SRCDIR)/Parser
RED_DIR = $(SRCDIR)/Redirection

SRC =	
	$(BUILTIN_DIR)/ft_builtin_cd.c		\
	$(BUILTIN_DIR)/ft_env.c			\
	$(BUILTIN_DIR)/ft_modif_env.c		\
	$(BUILTIN_DIR)/ft_print_env.c		\
	$(BUILTIN_DIR)/ft_pwd.c			\
	$(EXEC_DIR)/ft_exec.c			\



# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: all help

all: dirobj $(EXEDIR)/$(NAME)

help:
	@printf
	@printf "\033[33;36m Programme \033[33;1m$(NAME)\033[33;0m"
	@printf "\033[33;36m--------------------------------------------------------------------------"
	@printf "\033[33;36m Regles disponibles"
	@printf
	@printf "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@printf "\033[33;36m cplib     : \033[33;0mcompile la library"
	@printf "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@printf "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@printf "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@printf "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@printf "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@printf "\033[33;36m--------------------------------------------------------------------------"
	@printf

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

.PHONY: re_pre install cp faire_dossier cplib relib


re_pre: faire_dossier cp

# regle pour fabriquer les dossiers;
faire_dossier:
	@printf
	@printf "\033[33;32mFile created\tDONE\033[33;0m"
	@printf

# regle edition de liens
install: dirobj cp

cp: $(EXEDIR)/$(NAME)

$(EXEDIR)/$(NAME): $(DIR_LIB)/libft/libft.a $(DIR_LIB)/libftprintf/libftprintf.a $(OBJ)
	@printf "\r\033[33;40mLinking \033[33;31m$@\033[33;40m, executable create\033[33;0m"
	@$(CC) -o $@ $(OBJ) $(LIB)
	@printf "\033[33;32m OK\033[33;0m\n"

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	@$(CC) -c $(CFLAGS) $< -o $@
	@printf "\033[33;32m OK\033[33;0m"

# -------------------------------------------------------------------
#  regles des librairies, compilation, recompilation
# -------------------------------------------------------------------

$(DIR_LIB)/libftprintf/libftprintf.a: $(DIR_LIB)/libft/libft.a
	@$(MAKE) -s -j4 -C $(DIR_LIB)/libftprintf
	@printf "================================================================\n\n"

$(DIR_LIB)/libft/libft.a:
	@$(MAKE) -s -j4 -C $(DIR_LIB)/libft
	@printf "================================================================\n\n"

relib:
	@$(MAKE) -s -C $(DIR_LIB)/libftprintf fclean
	@$(MAKE) -s -C $(DIR_LIB)/libft fclean
	@$(MAKE) -s -j4 -C $(DIR_LIB)/libft
	@$(MAKE) -s -j4 -C $(DIR_LIB)/libftprintf

# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj bin cplib

# creation du dossier $(OBJDIR) si besoin :
dirobj:
	@mkdir -p $(OBJDIR) $(INCDIR) $(SRCDIR) $(EXEDIR)

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	@$(RM) -rf $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean: clean
	@printf "\r\033[33;31mDelete all project file \033[33;0m\n"
	@$(RM) -rf $(EXEDIR) $(OBJDIR)

uninstall:
	@printf "\r\033[33;31mDelete all project file and library file\033[33;0m\n"
	@$(RM) -rf $(OBJDIR) $(EXEDIR)
	@$(MAKE) -s -C ./Libs/libft fclean
	@$(MAKE) -s -C ./Libs/libftprintf fclean

re: fclean dirobj cp
