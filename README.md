# Particle
így fordul, indul terminálból:
gcc -c reszecske.c    # létrehozza reszecske.o
gcc -c szimulacio.c  # létrehozza sszimulacio.o
gcc -c kiir.c      # létrehozza kiir.o
gcc -c main.c        # létrehozza main.o
gcc -o szim main.o reszecske.o szimulacio.o kiir.o
./szim 