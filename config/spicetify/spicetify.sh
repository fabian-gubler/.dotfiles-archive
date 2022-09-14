# download
curl -fsSL https://raw.githubusercontent.com/spicetify/spicetify-cli/master/install.sh | sh

# change permission
sudo chmod 777 /usr/share/spotify-client -R

# change directory
cd ~/.spicetify

# add extensions
./spicetify config extensions keyboardShortcut.js

# backup and apply
./spicetify backup apply
./spicetify apply

