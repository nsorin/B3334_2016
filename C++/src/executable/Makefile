#Variables

COMP     =g++
EDL      =g++
RM       =@rm
ECHO     =@echo
RMFLAGS  =-f
OUTPUT   =-o
CPPFLAGS =-std=c++11 -Wall #-DMAP
EDLFLAGS =
INT      =AddPolygone.h AddRectangle.h AddSegment.h Clear.h Command.h ComplexObject.h Delete.h InterObject.h Intersection.h Load.h Move.h Object.h Polygone.h Rectangle.h Segment.h SimpleObject.h Union.h UnionObject.h
INTPATH  =../header/
REAL     =$(REALPATH)$(INT:.h=.cpp) $(REALPATH)Controller.cpp
REALPATH =../src/
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
#Model
#Object.o: $(INCPATH)Object.h $(INCPATH)Point.h
#SimpleObject.o: $(INCPATH)SimpleObject.h $(INCPATH)Object.h $(INCPATH)Point.h
#ComplexObject.o: $(INCPATH)ComplexObject.h $(INCPATH)Object.h $(INCPATH)Point.h
#InterObject.o: $(INCPATH)InterObject.h $(INCPATH)ComplexObject.h
#UnionObject.o: $(INCPATH)UnionObject.h $(INCPATH)ComplexObject.h
#Polygone.o: $(INCPATH)Polygone.h $(INCPATH)SimpleObject.h
#Rectangle.o: $(INCPATH)Rectangle.h $(INCPATH)SimpleObject.h
#Segment.o: $(INCPATH)Segment.h $(INCPATH)SimpleObject.h
#Controller
#Controller.o: $(INCPATH)Command.h $(INCPATH)Object.h
#Command.o: $(INCPATH)Object.h $(INCPATH)Command.h
#Operation.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Operation.h
#Intersection.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Operation.h $(INCPATH)Intersection.h
#Union.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Operation.h $(INCPATH)Union.h
#Clear.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Clear.h
#Save.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Save.h
#Load.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Load.h
#Move.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Move.h
#Delete.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Delete.h
#Add.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Add.h
#AddPolygone.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Add.h $(INCPATH)AddPolygone.h
#AddRectangle.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Add.h $(INCPATH)AddRectangle.h
#AddSegment.o: $(INCPATH)Command.h $(INCPATH)Object.h $(INCPATH)Add.h $(INCPATH)AddSegment.h
