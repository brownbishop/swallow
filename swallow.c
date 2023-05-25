#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
    printf("swallow app_name [arguments]\n");
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        usage();
        return 0;
    }

    char *command;
    int maxsize, i;
    for(maxsize=0,i=1; argv[i] ; i++) {
      maxsize += strlen(argv[i]);
    }

    command = (char*)malloc(maxsize+1);

    for (int i = 1; i < argc; i++) {
        strcat(command, argv[i]);
        *((command+strlen(argv[i]))+1) = ' ';
    }

    // open current display
    int rev;
    Window win;
    Display* dis = XOpenDisplay(0);

    if (dis == NULL) {
        printf("Failed to open display!\n");
        return 0;
    }

    /*
     * when this program runs the terminal emulator
     * is the current focused window
     */

    // hide the focused window
    XGetInputFocus(dis, &win, &rev);
    XUnmapWindow(dis, win);
    XFlush(dis);

    // launch the application
    int res = system(command);

    if (res != 0) {
        printf("Application exited with %i\n", res);
    }

    // the application exited
    // unhide the terminal emulator
    XMapWindow(dis, win);
    XCloseDisplay(dis);

}

