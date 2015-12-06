gcc -shared -fPIC caculate.c -o libcac.so
gcc main.c -o main -ldl
./main
