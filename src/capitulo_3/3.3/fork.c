#include <stdio.h>
#include <sys/types.h>
#ifdef _WIN32
  #include <process.h>  // Windows
  static int getppid(void) {
      // Not natively supported.
      // Return dummy value or implement with Windows API if you *really* need it.
      return 0;
  }
#else
  #include <unistd.h>   // Linux / Unix
#endif

int main (){
    pid_t child_pid;

    printf("The main process ID is %d\n", (int)getpid());
    child_pid = fork ();
    if (child_pid != 0){
        printf("This is the parent process with ID %d\n", (int)getpid());
        printf("This is the parent of the process with ID %d\n", child_pid);
    }
    else {
        printf("This is the child process with ID %d\n", (int)getpid());
    }
    return 0;
}