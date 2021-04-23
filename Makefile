IDIR = include
ODIR = obj
SDIR = src
JDIR = java

CC = gcc
CFLAGS = -Wall -fPIC -I$(IDIR)
LIB = $(JDIR)/schedule_library.so

#JINCLUDES = -I/usr/lib/jvm/java-8-openjdk-amd64/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/ -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux/
JINCLUDES = -I/usr/lib/jvm/jdk-11.0.10/ -I/usr/lib/jvm/jdk-11.0.10/include/ -I/usr/lib/jvm/jdk-11.0.10/include/linux/

_DEPS = utilities.h list.h olist.h bstree.h instance.h schedule.h model_ScheduleModel.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = utilities.o list.o olist.o bstree.o instance.o main.o schedule.o model_ScheduleModel.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(OBJ) $(ODIR)/model_ScheduleModel.o
	$(CC) -shared -o $(LIB) $^

$(ODIR)/model_ScheduleModel.o : $(SDIR)/model_ScheduleModel.c $(DEPS)
	$(CC) $(CFLAGS) $(JINCLUDES) -c -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(LIB)
