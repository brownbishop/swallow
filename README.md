# swallow
X11 window "swallower"

#### What it does? 

When used to launch a GUI application from terminal it hides the terminal emulator from which the application was launched. The terminal will be restored after the launched application exits. 

#### Usage
`swallow application_name [arguments]`

#### Installation
```  
git clone https://github.com/brownbishop/swallow
cd swallow  
sudo(doas) make install
```  

#### Removal
From the swallow directory run: 
` sudo make uninstall` 

