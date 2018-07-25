#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start cored traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/cored
  cp /usr/local/bin/steem-sv-run.sh /etc/service/cored/run
  chmod +x /etc/service/cored/run
  runsv /etc/service/cored
else
  /usr/local/bin/startpaascored.sh
fi
