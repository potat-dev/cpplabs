// #include <signal.h>
// #include <unistd.h>

// #include <cstdlib>
// #include <iostream>

// using namespace std;
// // Define the function to be called when ctrl-c (SIGINT) is sent to process
// void signal_callback_handler(int signum) {
//   cerr << endl << "Caught signal " << signum << endl;
//   // Terminate program
//   exit(signum);
// }

// int main() {
//   // Register signal and signal handler
//   signal(SIGINT, signal_callback_handler);
//   while (true) {
//     cout << "Program processing...";
//     sleep(5);
//     cout << endl;
//   }
//   return EXIT_SUCCESS;
// }

#include <csignal>
#include <iostream>
#include <string>

volatile sig_atomic_t count = 0;

using namespace std;

void ctrl_c(int sig) {
  cerr << endl << "Ctrl-C caught" << endl;
  cerr << "Pressed " << count++ << " times" << endl;
  if (count > 10) {
    cerr << "Exiting" << endl;
    exit(0);
  }
  signal(sig, ctrl_c);  // re-installs handler
}

int main() {
  string buf;
  void (*old)(int);

  old = signal(SIGINT, ctrl_c);  // installs handler

  for (;;) {
    cout << "Enter first number: " << endl;
    getline(cin, buf);
    if (cin.fail() || cin.eof()) {
      exit(0);
      // cin.clear();  // reset cin state
    } else {
      cout << "Number 1: " << buf << endl;
    }

    string buf1(buf);
    cout << "Enter second number: " << endl;
    getline(cin, buf);
    if (cin.fail() || cin.eof()) {
      cin.clear();  // reset cin state
    } else {
      cout << "Number 2: " << buf << endl;
    }

    cout << "Result: " << buf1 + buf << endl;
  }
  signal(SIGINT, old);  // restore initial handler
  return 0;
}