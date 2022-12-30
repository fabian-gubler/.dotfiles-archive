# SOURCE: https://gist.github.com/ThHareau/4509e969a094429121bd9830d88adeb7

sudo apt-get install zstd
mkdir /tmp/sound
cd /tmp/sound

# Step 2: download sof 1.6.2

wget https://ftp5.gwdg.de/pub/linux/archlinux/extra/os/x86_64/sof-firmware-1.6.1-1-any.pkg.tar.zst
tar -I zstd -xvf sof-firmware-1.6.1-1-any.pkg.tar.zst
sudo rm -rf /usr/lib/firmware/intel/sof*
sudo mv /usr/lib/firmware/intel/* /usr/lib/firmware/intel/

# Step 3: 

wget http://xps17.ddns.net/sof-soundwire.zip 
unzip sof-soundwire.zip
sudo rm -rf /usr/share/alsa/ucm2/sof-soundwire
sudo mv sof-soundwire /usr/share/alsa/ucm2/
