export LD_LIBRARY_PATH=`pwd`/libsoundio/build:`pwd`/kissfft

path_audio = LD_LIBRARY_PATH=`pwd`/libsoundio/build:`pwd`/kissfft
gcc -Wl 

to rm submodule ==> https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule


# to 

```
git clone https://gitlab.com/nipal/sound_manager sound_manager
cd sound_manager
git submodule init
git submodule update

export LD_LIBRARY_PATH="/usr/local/lib"     # to put in bashrc
make libs
```

