#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

void child4() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;
    exit(0);
}

void child5() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;
    exit(0);
}

void child6() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;
    exit(0);
}

void child7() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;
    exit(0);
}

void child2() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;

    //create child4
    pid_t pid4 = fork();
    if (pid4 == 0) {
        child4();
    } 

    //create child5
    pid_t pid5 = fork();
    if (pid5 == 0) {
        child5();
    } 

    wait(NULL);
    wait(NULL);

    exit(0);
}

void child3() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;

    //create child6
    pid_t pid6 = fork();
    if (pid6 == 0) {
        child6();
    } 

    //create child7
    pid_t pid7 = fork();
    if (pid7 == 0) {
        child7();
    } 

    wait(NULL);
    wait(NULL);

    exit(0);
}

void child1() {
    cout << "I am child pid= " << getpid() << "; my parent is pid=" << getppid() << endl;

    //create child2
    pid_t pid2 = fork();
    if (pid2 == 0) {
        child2();
    } 

    //create child3
    pid_t pid3 = fork();
    if (pid3 == 0) {
        child3();
    } 

    wait(NULL);
    wait(NULL);

    exit(0);
}

void parent() {
    cout << "I am parent pid= " << getpid() << "; my parent is pid=" << getppid() << endl;

    //create child1
    pid_t pid1 = fork();
    if (pid1 == 0) {
        child1();
    } 

    wait(NULL);
}

int main() {
    parent();
    return 0;
}
