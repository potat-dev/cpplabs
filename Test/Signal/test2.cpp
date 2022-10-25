#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

volatile bool isRunnung = true;

BOOL WINAPI HandlerRoutine(_In_ DWORD dwCtrlType) {
  switch (dwCtrlType) {
    case CTRL_C_EVENT:
      cout << "[Ctrl]+C\n";
      // isRunnung = false;
      exit(0);
      // Signal is handled - don't pass it on to the next handler
      return TRUE;
    default:
      // Pass signal on to the next handler
      return FALSE;
  }
}

int main(int argc, char* argv[]) {
  SetConsoleCtrlHandler(HandlerRoutine, TRUE);

  cout << "Starting\n";
  while (1) {
    // Sleep(1);
    cout << "Running\n";
  }
  cout << "Ending\n";

  return 0;
}