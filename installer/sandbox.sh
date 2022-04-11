GROUPS=(
	'networkmanager-submodules'
	'virtualization'
	'sound-and-video'
)

for PKG in "${GROUPS[@]}"; do
    echo "INSTALLING: $PKG"
    # echo "$PKG" 
done
# GROUPS
# sudo dnf group install -y networkmanager-submodules virtualization sound-and-video
