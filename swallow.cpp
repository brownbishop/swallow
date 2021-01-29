#include <X11/Xlib.h>

#include <cstdlib> 
#include <iostream> 
#include <string>

void usage() { 
    std::cout << "swallow app_name [arguments]\n"; 
}

int main(int argc, char** argv) { 
    if (argc <= 1) { 
        usage();
        return 0; 
    }

    std::string command;

    for (int i = 1; i < argc; i++) { 
        command += argv[i]; 
        command += ' ';
    }


    // open current display 
    int rev; 
    Window win; 
    Display* dis = XOpenDisplay(0); 
    
    if (dis == nullptr) { 
        std::cerr << "Failed to open display!\n";
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
    int res = system(command.c_str()); 

    if (res != 0) { 
        std::cerr << "Application exited with " << res << "\n";
    }

    // the application exited 
    // unhide the terminal emulator
    XMapWindow(dis, win); 
    XCloseDisplay(dis);

}
