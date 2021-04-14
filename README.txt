To compile:
gcc -o hw4 -fopnmp hw4p4.c

In Columbia, looks like:
chc69@columbia:~/CS_Fundamentals$ gcc -o hw4 -fopenmp hw4p4.c

To run once: 
./hw4 <number of threads>

In Columbia, looks like:
chc69@columbia:~/CS_Fundamentals$ ./hw4 16

It will output the number of threads (from the parallell portion to make sure it was actually using those threads) used to run the program, the total time taken for all threads and the execution time PER THREAD.

If necessary, I ran 5x using the shell script:
chc69@columbia:~/CS_Fundamentals$ for i in {1..5}; do ./exh2 16; done