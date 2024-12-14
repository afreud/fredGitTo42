#!/bin/bash

#su -
#apt install sudo -y
#sudo

apt-get update -y
apt-get upgrade -y
apt-get install vim -y
apt-get install git -y
apt install openssh-server -y
apt install ufw -y
apt install libpam-pwquality -y
apt-get install -y net-tools

groupadd user 42
usermod -aG sudo frdurand42
usermod -aG user42 frdurand42
echo "$(getent group sudo)"
echo "$(getent group user42)"
[ ! -d /var/log/sudo ] && mkdir /var/log/sudo || echo " /var/log/sudo already exist"
[ ! -f /var/log/sudo/sudo.log ] && touch /var/log/sudo/sudo.log || echo "/var/log/sudo/sudo.log already exist"

ufw enable
ufw allow ssh
ufw allow 4242
ufw status numbred || echo "Problem UFW"

echo "Port 4242" | cat >> /ect/ssh/sshd_config
systemctl restart ssh
systemctl status ssh

echo "$(aa -status)"
