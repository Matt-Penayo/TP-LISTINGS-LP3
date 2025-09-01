#include <stdio.h>

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
    printf ("The process ID is %d\n", (int)getpid());
    printf ("The parent process ID is %d\n", (int)getppid());
    return 0;
}