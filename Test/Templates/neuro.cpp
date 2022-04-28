#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Neuro {
  private:
    vector <double> input;
    vector <double> hidden;
    vector <double> output;
    vector <double> weights;

  public:
    Neuro(int in, int hide, int out):
      input(in),
      hidden(hide),
      output(out),
      weights(in * hide + hide * out) {
    }
};

int main() {
  Neuro net(18, 9, 1);
}