#Variables

COMP     =g++
EDL      =g++
RM       =@rm
ECHO     =@echo
RMFLAGS  =-f
OUTPUT   =-o
CPPFLAGS =-Wall #-DMAP
EDLFLAGS =
INT      =Add.h AddPolygone.h AddRectangle.h AddSegment.h Clear.h Command.h ComplexObject.h Delete.h InterObject.h Intersection.h List.h Load.h Move.h Object.h Operation.h Point.h Polygone.h Rectangle.h Redo.h Save.h Segment.h SimpleObject.h Union.h UnionObject.h
INTPATH  =../header/
REAL     =$(REALPATH)$(INT:.h=.cpp) $(REALPATH)Controller.cpp
OBJ      =$(OBJPATH)$(INT:.h=.o) $(OBJPATH)Controller.o
OBJPATH  =
LIBS     =
LIBPATH  =#-L
INCPATH  =#-I
EXE      =exe
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
