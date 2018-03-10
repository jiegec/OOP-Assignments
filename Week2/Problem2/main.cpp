#include "review_assigner.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    ReviewAssigner ra;
    ra.load("ContactEmail.txt");
    ra.choose();
    ra.output("reviewer.txt");
    return 0;
}
