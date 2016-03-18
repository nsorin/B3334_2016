#Variables

COMP=g++
EDL=g++
RM=@rm
ECHO=@echo
RMFLAGS=-f
OUTPUT=-o
CPPFLAGS=-Wall -DMAP
EDLFLAGS=
INT= Mere.h
REAL=$(INT:.h=.cpp)
OBJ=$(INT:.h=.o)
LIBS= -l tp -l ncurses -l tcl8.5
LIBPATH=-L ./
INCPATH=#-I
EXE= Parking
CLEAN=clean
.PHONY:$(CLEAN)


#Règles

$(EXE): $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(EDLFLAGS) $(OUTPUT) $(EXE) $(LIBPATH) $(OBJ) $(LIBS)

%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

$(CLEAN):
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) Core


#Gestion des dépendances
