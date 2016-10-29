#include <iostream>
#include "exclusionhandler.h"
#include "namehandler.h"

int main(int argc, char **argv) {

    ExclusionHandler exhandler;
    NameHandler nhandle;

    if (argc > 1) {
        exhandler.init(argv[1]);
    }
    nhandle.getNames();
    nhandle.drawNames(exhandler.getExclusions());
    exit(0);

}
