#type du projet
TYPE = algebre
#TYPE = graphique

#Nom de lexecutable :
EXECUTABLE = ft_minishell1

# Choix du compilateur :
COMPILATEUR = gcc
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -g3 -O0 
#-Wall -Wextra -Werror

DIR_LIB = ./Libs/

INC  =   -I $(DIR_LIB)libft/Include/
LIB  =   -L $(DIR_LIB)libft/ -lft
INC +=   -I $(DIR_LIB)libftprintf/Include/
LIB +=   -L $(DIR_LIB)libftprintf/  -lftprintf
#LIB  += -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  += -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

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

SRC =	$(SRCDIR)/ft_setup.c				\
		$(SRCDIR)/ft_parser.c				\
		$(SRCDIR)/ft_which_op.c				\
		$(SRCDIR)/ft_joinlst.c				\
		$(SRCDIR)/ft_join_red.c				\
		$(SRCDIR)/ft_env.c					\
		$(SRCDIR)/ft_printenv.c				\
		$(SRCDIR)/ft_builtin_cd.c			\
		$(SRCDIR)/ft_exec.c					\
		$(SRCDIR)/ft_pwd.c					\
		$(SRCDIR)/main.c					\
		$(SRCDIR)/ft_lst_sh_addend.c		\
		$(SRCDIR)/ft_lst_sh_new.c			\
		$(SRCDIR)/ft_lst_sh_del.c			\
		$(SRCDIR)/ft_tabaddargs.c			\
		$(SRCDIR)/ft_lstinbtree.c			\
		$(SRCDIR)/ft_create_node_btree.c	\
		$(SRCDIR)/ft_addnode_btree.c		\
		$(SRCDIR)/ft_clear_btree.c			\
		$(SRCDIR)/ft_parsing.c				\
		$(SRCDIR)/ft_wh.c					\
		$(SRCDIR)/ft_red.c					\
		$(SRCDIR)/ft_manage_cmd.c			\
		$(SRCDIR)/ft_manage_exec.c			\
		$(SRCDIR)/ft_star.c					\
		$(SRCDIR)/ft_error.c				\



# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: help

help:
	@echo
	@echo "\033[33;36m Programme \033[33;1m$(EXECUTABLE)\033[33;0m"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo "\033[33;36m Regles disponibles"
	@echo
	@echo "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@echo "\033[33;36m relib     : \033[33;0mRecompile la library"
	@echo "\033[33;36m cplib     : \033[33;0mcompile la library"
	@echo "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@echo "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@echo "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@echo "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@echo "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

.PHONY: re_pre install cp faire_dossier

re_pre: faire_dossier cp

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe cplib
	@echo
	@echo "\033[33;32mFile created\tDONE\033[33;0m"
	@echo

# regle edition de liens
install: faire_dossier cplib cp

cp: $(OBJ)
	@printf "\r\033[33;40mLinking $@, executable create\033[33;0m\n"
	@$(COMPILATEUR) $(LIB) $(COPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ) $(LIB)
	@echo "\033[33;32m OK\033[33;0m"

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	@$(COMPILATEUR) -c  $(COPTIONS) -I$(INCDIR) -o $@ $< $(INC)
	@echo "\033[33;32m OK\033[33;0m"

testmba:
	$(CC) $(INC) $(LIB) -g -I ./Includes/ Srcs_mba/main.c ./Objets/*.o -o test.out

testambre:
	$(CC) $(COPTIONS) $(INC) $(LIB) -I ./Includes/ Srcs_ambre/main.c ./Objets/*.o -o test2.out
	./test2.out
# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin relib cplib

# creation du dossier $(OBJDIR) si besoin :
dirobj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(INCDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p ./Libs/
	@mkdir -p ./Libs/

direxe:
	@mkdir -p $(EXEDIR)

relib:
	@make -C ./Libs/libft/ re
	@make -C ./Libs/libftprintf/ re

cplib:
	@make -C ./Libs/libft/
	@make -C ./Libs/libftprintf/

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	rm -rf $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean: clean
	rm -rf $(EXEDIR) $(OBJDIR) && mkdir -p $(EXEDIR) $(OBJDIR)

uninstall:
	printf "\r\033[33;31mDelete all project file and library file\033[33;0m\n"
	rm -rf $(OBJDIR) $(EXEDIR)
	make -C ./Libs/libft fclean
	make -C ./Libs/libftprintf fclean

re: fclean cp
