#!/bin/bash


echo "Extracting kernel source code..."
tar -xvf linux-6.11.7.tar.xz
cd linux-6.11.7


echo "Configuring the kernel..."
make menuconfig
echo "Reconfigurung"
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS


echo "Compiling the kernel. This may take a while..."
make -j$(nproc)
make modules -j$(nproc)


echo "Installing the kernel and modules..."
sudo make modules_install
sudo make install


echo "Updating the bootloader..."
sudo update-grub


echo "Kernel installation completed. A reboot is required to apply the new kernel."
read -p "Do you want to reboot now? (y/n): " REBOOT

if [[ "$REBOOT" == "y" || "$REBOOT" == "Y" ]]; then
    sudo reboot
else
    echo "Please remember to reboot your system later to activate the new kernel."
fi
