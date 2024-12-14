#!/bin/bash

#muse=$(free | grep -e Mem | tr -s ' ' | cut --delimiter=' ' --fields=3)
#mmax=$(free | grep -e Mem | tr -s ' ' | cut --delimiter=' ' --fields=2)
muse=$(top -bn1 | grep -e 'MiB Mem' | tr -s ' ' | cut --delimiter=' ' --fields=8)
mmax=$(top -bn1 | grep -e 'MiB Mem' | tr -s ' ' | cut --delimiter=' ' --fields=4)
mp100=$(echo ${muse}*100/${mmax} | bc)
ip=$(arp -n | grep -e '[a-z0-9][a-z0-9]:' | tr -s ' ' | cut --delimiter=' ' --fields="1,3")
mac=$(arp -n | grep -e '[a-z0-9][a-z0-9]:' | tr -s ' ' | cut --delimiter=' ' --fields=3)


cpu="100 - $(top -n1 | grep -e '^%Cpu' | cut --delimiter=' ' --fields='11')"

echo "#Architecture: $(uname -a | cut --delimiter=' ' --fields='1,2,3,4,14,15')"

echo "#CPU physical : $(lscpu | grep -e 'Core(s)' | rev | cut --delimiter=' ' --fields=1 | rev)"

echo "#vCPU: $(nproc)"

echo "#Memory Usage: ${muse}/${mmax} MiB    ${mp100} %"    

echo "#Disk Usage: $(df -P | grep -e '/$' | tr -s ' '| cut --delimiter=' ' --fields=3)/$(df -P | grep -e '/$' | tr -s ' '| cut --delimiter=' ' --fields=2)    $(df -P | grep -e '/$' | tr -s ' '| cut --delimiter=' ' --fields=5)"

echo "#CPU load: 0$(echo ${cpu} | bc) %" 

echo "#Last boot: $(who -b | tr -s ' ')"

echo "#LVM use: $(lvs)"

echo "#Number of TCP connexions :$(netstat --tcp | grep -e 'ESTABLISHED' | wc -l)"

echo "#User log: $(users | wc -l)"

echo "#Network IPv4/MAC: ${ip}"

echo "#Sudo did :$(cat /var/log/sudo/sudo.log | wc -l) cmds"
