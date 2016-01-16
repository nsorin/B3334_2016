#Variables

COMP     =g++
EDL      =g++
RM       =@rm
ECHO     =@echo
RMFLAGS  =-f
OUTPUT   =-o
CPPFLAGS =-Wall #-DMAP
EDLFLAGS =
INT      =Controller.h Object.h ComplexObject.h SimpleObject.h Point.h InterObject.h UnionObject.h Polygone.h Rectangle.h Segment.h
INTPATH  =../header/
REAL     =$(REALPATH)$(INT:.h=.cpp) $(REALPATH)Application.cpp
REALPATH =../src/
OBJ      =$(OBJPATH)$(INT:.h=.o) $(OBJPATH)Application.o
OBJPATH  =
LIBS     =
LIBPATH  =#-L
INCPATH  =#-I
EXE      =analog
CLEAN    =clean
.PHONY:$(CLEAN)

#Règles

$(EXE): $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(EDLFLAGS) $(OUTPUT) $(EXE) $(LIBPATH) $(OBJ) $(LIBS)
	rm $(OBJ)

%.o: $(REALPATH)%.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

$(CLEAN):
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) Core

#Gestion des dépendances
Application.o: $(INTPATH)Object.o
