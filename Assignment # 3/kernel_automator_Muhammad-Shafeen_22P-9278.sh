!/bin/bash
# " Updating and upgrading before running more commands to make sure latest software is being run"
sudo apt update;sudo apt upgrade
# "Downloading the zip file for linux kernel " 
version="6.11.7"
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.11.7.tar.xz
file_name="linux-$version.tar.xz"
# "Verifying the integrity of the downloaded file..."
sha256sum $file_name 
# "Installing essential packages for smooth installation"
sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison
# "extracting content from zip file"
sudo tar xvf linux-6.11.7.tar.xz
# "changing directory "
cd linux-6.11.7
# "Copying the files " 
cp -v /boot/config-$(uname -r) .config
# "Giving permissions to the certificates"
sudo scripts/config --disable SYSTEM_TRUSTED_KEYS
sudo scripts/config --disable SYSTEM_REVOCATION_KEYS
# "Make the kernel"
sudo make -j$(nproc)
# "Make modules"
sudo modules 
# "Make modules intaller"
sudo make modules_install 
# "Update files"
sudo update-initramfs -c -k 6.0.7 
# "Update Grub"
sudo update-grub 
# "Check grub version"
uname -mrs 
# "Kernel installed.Reboot required."
read -p "Press Y to reboot now or N to reboot later :" REBOOT
if [[ "$REBOOT" == "y" || "$REBOOT" == "Y" ]]; 
then
    sudo reboot
else
     "Please remember to reboot your system later to activate the new kernel."
fi


