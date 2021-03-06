#!/bin/sh
COUNT=`kreadconfig --file kwinrulesrc --group General --key count`
if [ -z "$COUNT" ]; then
    exit 0 # nothing to do for us
fi

# can you imaging how *much* faster sed is?
# it's however less reliable (installation, ini config, etc.)

for i in `seq 1 $COUNT`; do
    if [ "`kreadconfig --file kwinrulesrc --group $i --key activity`" = "ALL" ]; then
        kwriteconfig --file kwinrulesrc --group $i --key activity "00000000-0000-0000-0000-000000000000"
    fi
done