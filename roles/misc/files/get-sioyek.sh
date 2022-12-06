# SOURCE: https://github.com/ahrm/sioyek#fedora

# sudo dnf install qt5-qtbase-devel qt5-qtbase-static qt5-qt3d-devel harfbuzz-devel

# SAVE_DIR=$HOME/.local/share
#
# [ -d $SAVE_DIR/sioyek ] && echo "Exited: Directory already exists!" && exit
#
# mkdir $SAVE_DIR/sioyek
# cd $SAVE_DIR
# git clone --recursive https://github.com/ahrm/sioyek sioyek
# cd sioyek
# ./build_linux.sh
#
# ln -s $HOME/.local/share/sioyek/build/sioyek $HOME/.local/bin/
